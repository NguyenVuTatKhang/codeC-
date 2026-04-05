#ifndef BUTTON_H
#define BUTTON_H

typedef void (*button_callback_t)(void);

typedef struct {
    int pin;
    int last_state;
    button_callback_t on_press;
    button_callback_t on_release;
} Button;

int  button_init(Button *btn, int pin);
void button_set_press_cb(Button *btn, button_callback_t cb);
void button_set_release_cb(Button *btn, button_callback_t cb);
void button_poll(Button *btn);
void button_cleanup(Button *btn);

#endif