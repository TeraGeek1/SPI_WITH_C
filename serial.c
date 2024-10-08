#include <stdio.h>
#include <stdint.h>

struct spi_device {
    uint8_t mosi;
    uint8_t miso;
    uint8_t cs;
    uint8_t sclk;
    
};

int main() {
    printf("Hello World!");
    return 0;
}