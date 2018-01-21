#include <avr/interrupt.h>
#include "framework.h"
#include "millis.h"

int main() {

	sei();

	init();
	for(;;) {
		loop();
	}
	return 0;

}
