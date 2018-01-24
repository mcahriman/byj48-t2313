#include <avr/io.h>
#include <avr/interrupt.h>

#include "framework/byj48.h"
#include "framework/millis.h"

#include <util/delay.h>


#define BTN_COOLDOWN 160;


void init() {
	DDRB |= 0x0F;
	DDRD |= _BV(PD4) | _BV(PD5);
	PORTD |= (_BV(DDD2) | _BV(DDD3));
}

void loop() {
	static int current_step;
	static uint8_t direction;
	static uint8_t cooldown_timer;
	static uint8_t motors_on;


	_delay_ms(2)   ;// debug mode 120 Hz (meh)

	if(cooldown_timer != 0) cooldown_timer--;

	if( bit_is_clear(PIND, PD3) && cooldown_timer == 0) {
		direction = !direction;
		cooldown_timer = BTN_COOLDOWN;
	}

	if( bit_is_clear(PIND, PD2) && cooldown_timer == 0) {
		motors_on = !motors_on;
		cooldown_timer = BTN_COOLDOWN;
	}


	PORTB &= ~ 0x0F;
	PORTD &= ~( _BV(PD5) |_BV(PD4)) ;

	if(motors_on) {
		PORTB |= byj_steps[current_step];
		current_step += (direction == 0 ? 1 : -1);
	}

	PORTD |= (direction ? _BV(PD5) : 0) | (motors_on ? 0 : _BV(PD4) );


	current_step = current_step < STEP_COUNT ? current_step : 0;
	current_step = current_step < 0 ? STEP_COUNT - 1 : current_step;

}
