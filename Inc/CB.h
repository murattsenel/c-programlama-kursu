/*
 * CB.h
 *
 *  Created on: 14 Haz 2023
 *      Author: murat
 */

#ifndef INC_CB_H_
#define INC_CB_H_

#define BUFFER_SIZE 200
#include"stm32f4xx_hal.h"
#include"string.h"

typedef struct{
	uint8_t buffer[BUFFER_SIZE];
	uint32_t head_index;
	uint32_t tail_index;
	uint32_t data_count;
	uint32_t drop_count;
}CircularBuffer;

void initializeCircularBuffer(CircularBuffer * buff);
uint8_t readCircularBuffer(CircularBuffer * buff, uint8_t *ch);
uint8_t writeCircularBuffer(CircularBuffer * buff, uint8_t ch);
uint8_t isCircularBufferEmpty(CircularBuffer * buff);
uint8_t isCircularBufferFull(CircularBuffer * buff);
void CurcilarBufferReset(CircularBuffer * buff);
#endif /* INC_CB_H_ */
