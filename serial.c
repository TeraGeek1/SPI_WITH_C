#include <stdio.h>
#include <pigpio.h>
#include <stdint.h>

typedef struct
{
	uint8_t clkPin;	   // Clock pin
	uint8_t mosiPin;   // Master out Slave in pin
	uint8_t misoPin;   // Master in Slave out pin
	uint8_t csPin;	   // Chip Select pin
	uint32_t clkSpeed; // Clock Speed in Hz
	uint8_t mode;	   // SPI Mode (0, 1, 2, 3)
} SPIDevice;

void initSPIDevice(SPIDevice *device)
{
	// Set pin modes
	gpioSetMode(device->mosiPin, PI_OUTPUT);
	gpioSetMode(device->misoPin, PI_INPUT);
	gpioSetMode(device->clkPin, PI_OUTPUT);
	gpioSetMode(device->csPin, PI_OUTPUT);

	// Set initial states
	gpioWrite(device->clkPin, 1); // Clock idle high (can vary based on mode)
	gpioWrite(device->csPin, 1);  // Chip Select inactive (high)
}

void spi_set_mode(SPIDevice *device)
{
	switch (device->mode)
	{
	case 0:
		// CPOL = 0, CPHA = 0
		gpioWrite(device->clkPin, 0);
		break;
	case 1:
		// CPOL = 0, CPHA = 1
		gpioWrite(device->clkPin, 0);
		break;
	case 2:
		// CPOL = 1, CPHA = 0
		gpioWrite(device->clkPin, 1);
		break;
	case 3:
		// CPOL = 1, CPHA = 1
		gpioWrite(device->clkPin, 1);
		break;
	default:
		// TODO: Invalid mode, handle error
		break;
	}
}

void write(SPIDevice *device, int data)
{
}