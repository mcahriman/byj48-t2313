#ifndef __BYJ_48_H__
#define __BYJ_48_H__

#include "config.h"
/**
 * Define stepper motor port.
 * I use here first 4 bits of port, so these ones will be reserved for stepper control
 * For example:
 * #define BYJ48_USE PORT B: sets bits 0:3 of DDRB to 1
 */
#include <avr/io.h>
#include <inttypes.h>

#ifdef BYJ48_USE_PORTA
	#define BYJ48_PORT PORTA
	#define BYJ48_DDR DDRA
#elif defined BYJ48_USE_PORTB
	#define BYJ48_PORT PORTB
	#define BYJ48_DDR DDRB
#elif defined BYJ48_USE_PORTC
	#define BYJ48_PORT PORTC
	#define BYJ48_DDR DDRC
#elif defined BYJ48_USE_PORTD
	#define BYJ48_PORT PORTD
	#define BYJ48_DDR DDRD
#elif defined BYJ48_USE_PORTE
	#define BYJ48_PORT PORTE
	#define BYJ48_DDR DDRE
#elif defined BYJ48_USE_PORTF
	#define BYJ48_PORT PORTF
	#define BYJ48_DDR DDRF
#else
#error BYJ48 port is not defined, please define BYJ48_USE_PORTX macro (X is your port of choise)
#endif


#define HALF_STEP_COUNT 8
#define FULL_STEP_COUNT 4

#ifndef STEP_COUNT
#define STEP_COUNT FULL_STEP_COUNT
#endif

#if STEP_COUNT == HALF_STEP_COUNT

uint8_t byj_steps[] = {
		0b0001,
		0b0011,
		0b0010,
		0b0110,
		0b0100,
		0b1100,
		0b1000,
		0b1001
};

#elif STEP_COUNT == FULL_STEP_COUNT

uint8_t byj_steps[] = {
		0b0011,
		0b0110,
		0b1100,
		0b1001
};

#endif


#endif /* __BYJ_48_H__ */
