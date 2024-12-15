/*
 * led_display.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Admin
 */

#include "led_display.h"

uint16_t set7SEG[11] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10, 0xFF};
uint16_t reset7SEG[11] = {0xBF, 0x86, 0xDB, 0xCF, 0xE6, 0xED, 0xFD, 0x87, 0xFF, 0xEF, 0x00};

void display7SEG(int num) {
	if (num >= 0 && num <= 9) {
		GPIOA->ODR = (GPIOA->ODR | (set7SEG[num] << 8)) & ~(reset7SEG[num] << 8);
	}
	else {
		GPIOA->ODR = (GPIOA->ODR | (set7SEG[10] << 8)) & ~(reset7SEG[10] << 8);
	}
}

void update7SEG(int index){
    switch (index) {
    case 0:
		HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, GPIO_PIN_SET);
        break;
    case 1:
		HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, GPIO_PIN_SET);
        break;
    case 2:
		HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, GPIO_PIN_SET);
        break;
    case 3:
		HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, GPIO_PIN_RESET);
        break;
	default:
		break;
    }
}
