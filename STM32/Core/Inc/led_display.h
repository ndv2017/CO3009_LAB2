/*
 * led_display.h
 *
 *  Created on: Oct 7, 2024
 *      Author: Admin
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "main.h"
#define LED_NUMBER 4

extern int led_index;
extern int led_buffer[LED_NUMBER];
extern int hour;
extern int minute;
extern int second;

void display7SEG(int num);
void update7SEG(int index);
void updateClockBuffer();

#endif /* INC_LED_DISPLAY_H_ */
