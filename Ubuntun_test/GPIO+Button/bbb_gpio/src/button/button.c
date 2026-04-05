#include <unistd.h>
#include "button.h"
#include "../gpio/gpio.h"  

int button_init(Button *btn, int pin) {
    btn->pin       = pin;
    btn->on_press  = NULL;
    btn->on_release = NULL;
    gpio_export(pin);
    gpio_set_direction(pin, GPIO_IN);
    btn->last_state = gpio_read(pin);
    return 0;
}

void button_set_press_cb(Button *btn, button_callback_t cb)   { btn->on_press = cb; }
void button_set_release_cb(Button *btn, button_callback_t cb) { btn->on_release = cb; }

void button_poll(Button *btn) {
    int state = gpio_read(btn->pin);
    if (state != btn->last_state) {
        usleep(20000);
        state = gpio_read(btn->pin);
        if (state != btn->last_state) {
            if (state == 0 && btn->on_press)    btn->on_press();
            if (state == 1 && btn->on_release)  btn->on_release();
            btn->last_state = state;
        }
    }
}

void button_cleanup(Button *btn) {
    gpio_unexport(btn->pin);
}