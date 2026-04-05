#include "led.h"
#include "../gpio/gpio.h"   

int led_init(Led *led, int pin) {
    led->pin   = pin;
    led->state = 0;
    gpio_export(pin);
    gpio_set_direction(pin, GPIO_OUT);
    gpio_write(pin, 0);
    return 0;
}

void led_on(Led *led)  { led->state = 1; gpio_write(led->pin, 1); }
void led_off(Led *led) { led->state = 0; gpio_write(led->pin, 0); }

void led_toggle(Led *led) {
    led->state = !led->state;
    gpio_write(led->pin, led->state);
}

void led_cleanup(Led *led) {
    gpio_write(led->pin, 0);
    gpio_unexport(led->pin);
}