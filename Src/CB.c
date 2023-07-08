/*
 * CB.c
 *
 *  Created on: 14 Haz 2023
 *      Author: murat
 */


#include <CB.h>

void initializeCircularBuffer(CircularBuffer * buff)
{

	memset(buff->buffer,0,BUFFER_SIZE);
	buff->head_index=0;
	buff->tail_index=0;
	buff->data_count=0;
	buff->drop_count=0;

}

uint8_t readCircularBuffer(CircularBuffer * buff, uint8_t *ch)
{

	if(buff->data_count == 0 )
	{
     return 0;  // buffer boş ise  okuma yapma
	}
	else
	{

		*ch = buff->buffer[buff->tail_index] ; // tail değeri 1 arttı


		HAL_NVIC_DisableIRQ(USART2_IRQn);

		buff->tail_index++;
		buff->data_count--;    // data okunduğu için kalan data 1 azaldı
		buff->tail_index =  buff->tail_index % BUFFER_SIZE ;


		HAL_NVIC_EnableIRQ(USART2_IRQn);


	}
	return 1;
}

uint8_t writeCircularBuffer(CircularBuffer * buff, uint8_t ch)
{
	if( buff->data_count == BUFFER_SIZE)
	{
		buff->drop_count++;
		return 0; //  buffer tamamen dolu ise yazma
	}
	else
	{
		buff->buffer[buff->head_index] = ch;



		HAL_NVIC_DisableIRQ(USART2_IRQn);

		//Disable INT
		buff->head_index++;
		buff->data_count++;
		buff->head_index =  buff->head_index % BUFFER_SIZE ;

		HAL_NVIC_EnableIRQ(USART2_IRQn);

	}
	return 1;
}

uint8_t isCircularBufferEmpty(CircularBuffer * buff)
{
	return buff->data_count == 0 ? 1 : 0;// buffer içinde bulanan data
}

uint8_t isCircularBufferFull(CircularBuffer * buff)
{
	return buff->data_count == BUFFER_SIZE ? 1 : 0;// buffer içinde bulanan data
}
void CurcilarBufferReset(CircularBuffer * buff)
{
	HAL_NVIC_DisableIRQ(USART2_IRQn);
	buff->head_index =0;
	buff->tail_index =0;
	HAL_NVIC_EnableIRQ(USART2_IRQn);
}
