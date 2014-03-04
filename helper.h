/*
 * helper.h
 *
 * Created: 2014-03-03 18:06:01
 *  Author: SIMON
 */ 


#ifndef __HELPER_H_
#define __HELPER_H_

#include "GUI.h"

typedef struct {
	Object super;
	GUI *gui;
	int firstpress;
} HELP;

void repeat(HELP *this, int incordec);

#define initHelp(gui, firstpress){initObject(), gui, firstpress}


#endif __HELPER_H_