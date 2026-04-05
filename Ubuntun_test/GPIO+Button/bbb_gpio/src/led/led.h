#ifndef LED_H
#define LED_H

typedef struct {
    int pin;
    int state;
} Led;

int  led_init(Led *led, int pin);
void led_on(Led *led);
void led_off(Led *led);
void led_toggle(Led *led);
void led_cleanup(Led *led);

#endif