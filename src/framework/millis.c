#include <stdint.h>
#include "millis.h"
#include "config.h"


static uint16_t milliseconds;

void init_millis() {
#ifdef ENABLE_MILLIS

#endif
}

uint16_t millis() {
#ifndef ENABLE_MILLIS
	#pragma message "millis used but not included"
#endif
	return milliseconds;
}

//init
#ifdef ENABLE_MILLIS
#endif
