#include <pigpiod_if2.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int pi = pigpio_start(NULL, NULL);
    if (pi < 0)
    {
        printf("Failed to connect to pigpio daemon.\n");
        return 1;
    }

    set_mode(pi, 17, PI_OUTPUT); // Set GPIO17 as output

    for (int i = 0; i < 10; i++)
    {
        gpio_write(pi, 17, 1); // LED ON
        sleep(1);
        gpio_write(pi, 17, 0); // LED OFF
        sleep(1);
    }

    pigpio_stop(pi);
    return 0;
}