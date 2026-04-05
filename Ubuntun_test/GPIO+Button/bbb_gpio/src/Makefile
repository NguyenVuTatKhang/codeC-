CC      = $(CC)
CFLAGS  = -Wall -fPIC -I.
SRCS    = gpio/gpio.c button/button.c led/led.c
OBJS    = $(SRCS:.c=.o)
TARGET  = libbbb_gpio.so

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -shared -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
