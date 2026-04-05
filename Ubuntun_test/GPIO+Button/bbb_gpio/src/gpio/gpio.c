#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "gpio.h"

#define GPIO_PATH "/sys/class/gpio"

int gpio_export(int pin) {
    char buf[64];
    int fd = open(GPIO_PATH "/export", O_WRONLY);
    if (fd < 0) return -1;
    snprintf(buf, sizeof(buf), "%d", pin);
    if (write(fd, buf, strlen(buf)) < 0) {
        close(fd);
        return -1;
    }
    close(fd);
    return 0;
}

int gpio_unexport(int pin) {
    char buf[64];
    int fd = open(GPIO_PATH "/unexport", O_WRONLY);
    if (fd < 0) return -1;
    snprintf(buf, sizeof(buf), "%d", pin);
    if (write(fd, buf, strlen(buf)) < 0) {
        close(fd);
        return -1;
    }
    close(fd);
    return 0;
}

int gpio_set_direction(int pin, int direction) {
    char path[128];
    snprintf(path, sizeof(path), GPIO_PATH "/gpio%d/direction", pin);
    int fd = open(path, O_WRONLY);
    if (fd < 0) return -1;
    const char *dir_str = (direction == GPIO_OUT) ? "out" : "in";
    if (write(fd, dir_str, strlen(dir_str)) < 0) {
        close(fd);
        return -1;
    }
    close(fd);
    return 0;
}

int gpio_write(int pin, int value) {
    char path[128];
    snprintf(path, sizeof(path), GPIO_PATH "/gpio%d/value", pin);
    int fd = open(path, O_WRONLY);
    if (fd < 0) return -1;
    if (write(fd, value ? "1" : "0", 1) < 0) {
        close(fd);
        return -1;
    }
    close(fd);
    return 0;
}

int gpio_read(int pin) {
    char path[128];
    char val = '0';
    snprintf(path, sizeof(path), GPIO_PATH "/gpio%d/value", pin);
    int fd = open(path, O_RDONLY);
    if (fd < 0) return -1;
    if (read(fd, &val, 1) < 0) {
        close(fd);
        return -1;
    }
    close(fd);
    return val == '1' ? 1 : 0;
}