# bbb_gpio

Thư viện GPIO, Button và LED cho **BeagleBone Black** — được build bằng Buildroot, giao tiếp qua Linux sysfs interface.

---

## Cấu trúc thư mục

```
package/bbb_gpio/
├── Config.in               # Khai báo package với Buildroot menuconfig
├── bbb_gpio.mk             # Build rules và install rules cho Buildroot
└── src/
    ├── Makefile            # Build libbbb_gpio.so
    ├── gpio/
    │   ├── gpio.c          # Tầng sysfs: đọc/ghi /sys/class/gpio/
    │   └── gpio.h
    ├── button/
    │   ├── button.c        # Logic nút bấm: debounce, callback
    │   └── button.h
    └── led/
        ├── led.c           # Điều khiển LED: on/off/toggle
        └── led.h
```

---

## Kiến trúc phân tầng

```
Application
  ├── button.h  ──┐
  └── led.h    ──┤──▶  gpio.h / gpio.c  ──▶  /sys/class/gpio/  (kernel sysfs)
```

| Tầng | File | Trách nhiệm |
|---|---|---|
| **gpio** | `gpio.c` | Tầng duy nhất chạm sysfs, export/unexport pin, đọc/ghi value |
| **button** | `button.c` | Phát hiện nhấn/thả, debounce 20ms, gọi callback |
| **led** | `led.c` | Bật/tắt/toggle LED qua gpio |

---

## Mô tả thư viện

### gpio

```c
int gpio_export(int pin);                    // Khởi tạo pin với kernel
int gpio_unexport(int pin);                  // Giải phóng pin
int gpio_set_direction(int pin, int dir);    // GPIO_IN hoặc GPIO_OUT
int gpio_write(int pin, int value);          // Ghi GPIO_HIGH hoặc GPIO_LOW
int gpio_read(int pin);                      // Trả về 0 hoặc 1, -1 nếu lỗi
```

### button

```c
int  button_init(Button *btn, int pin);
void button_set_press_cb(Button *btn, button_callback_t cb);    // Callback khi nhấn
void button_set_release_cb(Button *btn, button_callback_t cb);  // Callback khi thả
void button_poll(Button *btn);      // Gọi trong vòng lặp chính
void button_cleanup(Button *btn);   // Giải phóng pin
```

### led

```c
int  led_init(Led *led, int pin);
void led_on(Led *led);
void led_off(Led *led);
void led_toggle(Led *led);
void led_cleanup(Led *led);
```

---

## Ví dụ sử dụng

```c
#include "gpio/gpio.h"
#include "button/button.h"
#include "led/led.h"

#define LED_PIN    44   // P8_12
#define BUTTON_PIN 45   // P8_11

Led led;

void on_press(void) {
    led_toggle(&led);
}

int main(void) {
    led_init(&led, LED_PIN);

    Button btn;
    button_init(&btn, BUTTON_PIN);
    button_set_press_cb(&btn, on_press);

    while (1) {
        button_poll(&btn);
        usleep(10000);  // poll mỗi 10ms
    }

    led_cleanup(&led);
    button_cleanup(&btn);
    return 0;
}
```

---

## Các bước build với Buildroot

### Yêu cầu

- Buildroot đã cài và đã có `.config` cho BeagleBone Black
- WSL Ubuntu hoặc Linux host

### Bước 1 — Tạo cấu trúc package

```bash
cd ~/Documents/Beaglebone_black/buildroot
mkdir -p package/bbb_gpio/src/{gpio,button,led}
touch package/bbb_gpio/Config.in
touch package/bbb_gpio/bbb_gpio.mk
touch package/bbb_gpio/src/Makefile
touch package/bbb_gpio/src/gpio/gpio.{c,h}
touch package/bbb_gpio/src/button/button.{c,h}
touch package/bbb_gpio/src/led/led.{c,h}
```

### Bước 2 — Điền nội dung Config.in

```bash
cat > package/bbb_gpio/Config.in << 'EOF'
config BR2_PACKAGE_BBB_GPIO
    bool "bbb_gpio"
    help
      GPIO, Button, LED library for BeagleBone Black.
EOF
```

### Bước 3 — Điền nội dung bbb_gpio.mk

```bash
cat > package/bbb_gpio/bbb_gpio.mk << 'EOF'
BBB_GPIO_VERSION = 1.0
BBB_GPIO_SITE = $(TOPDIR)/package/bbb_gpio/src
BBB_GPIO_SITE_METHOD = local

define BBB_GPIO_BUILD_CMDS
    $(MAKE) $(TARGET_CONFIGURE_OPTS) -C $(@D)
endef

define BBB_GPIO_INSTALL_TARGET_CMDS
    $(INSTALL) -D -m 0755 $(@D)/libbbb_gpio.so \
        $(TARGET_DIR)/usr/lib/libbbb_gpio.so
endef

$(eval $(generic-package))
EOF
```

### Bước 4 — Đăng ký package vào Buildroot

```bash
# Thêm vào package/Config.in (trước endmenu cuối)
sed -i '/^endmenu$/{$!b;s/^endmenu$/source "package\/bbb_gpio\/Config.in"\nendmenu/}' package/Config.in

# Kiểm tra
tail -5 package/Config.in
```

### Bước 5 — Bật package trong menuconfig

```bash
make menuconfig
# Nhấn / → tìm BBB_GPIO → nhấn số 1 → nhấn Y để bật → Save → Exit
```

### Bước 6 — Build

```bash
# Build chỉ package bbb_gpio
make bbb_gpio

# Nếu sửa code thì rebuild
make bbb_gpio-rebuild
```

### Bước 7 — Kiểm tra output

```bash
# Kiểm tra file tồn tại
ls -lh output/target/usr/lib/libbbb_gpio.so

# Kiểm tra đúng architecture ARM
file output/target/usr/lib/libbbb_gpio.so
# ➜ ELF 32-bit LSB shared object, ARM, EABI5 ✅
```

### Bước 8 — Copy lên BeagleBone Black

```bash
scp output/target/usr/lib/libbbb_gpio.so root@<IP_BBB>:/usr/lib/
```

---

## Output

| File | Đường dẫn trên target |
|---|---|
| `libbbb_gpio.so` | `/usr/lib/libbbb_gpio.so` |

- **Architecture**: ARM 32-bit EABI5
- **Cross-compiler**: `arm-none-linux-gnueabihf-gcc` (Buildroot toolchain)
- **Interface**: Linux sysfs `/sys/class/gpio/`
