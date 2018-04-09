/*
 * port_b_led.c
 *
 * Created: 02.04.2018 20:27:06
 * Author: DeepSouthT
 */ 
#include <avr/io.h>
#include "port_b_led.h"

void vLEDInit(uint8_t bit_port_b)
{
	// Set LED_O as output pin
	DDR_PORT_B |= (1<<bit_port_b);
}

void vLEDToggle(uint8_t bit_port_b)
{
	//Toggle LED 4
	PORT_B_LED ^= (1<<bit_port_b);
}

void vLEDOn(uint8_t bit_port_b)
{
	//On LED 4
	PORT_B_LED |= (1<<bit_port_b);
}

void vLEDOff(uint8_t bit_port_b)
{
	//On LED 4
	PORT_B_LED &= ~(1<<bit_port_b);
}