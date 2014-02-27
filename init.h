#ifndef __INIT_H_
#define __INIT_H_

#include "TinyTimber.h"

typedef struct {
	Object super;
} Init;

#define initH(){initObject()}
	
#endif	__INIT_H_