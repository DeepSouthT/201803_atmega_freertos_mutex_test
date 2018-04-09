/*
 * port_b_led.h
 *
 * Created: 02.04.2018 20:27:06
 * Author: DeepSouthT
 */ 

#ifndef PORT_B_LED_H_
#define PORT_B_LED_H_

// Output Port pin LED_O
#define PORT_B_LED      PORTB
#define DDR_PORT_B       DDRB

void vLEDInit(uint8_t);
void vLEDToggle(uint8_t);
void vLEDOn(uint8_t);
void vLEDOff(uint8_t);

#endif /* PORT_B_LED_H_ */