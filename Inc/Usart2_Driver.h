/*
 * Usart2_Driver.h
 *
 *  Created on: Jun 9, 2023
 *      Author: murat
 */

#ifndef INC_USART2_DRIVER_H_
#define INC_USART2_DRIVER_H_

#include <CB.h>
#include"stm32f4xx_hal.h"

void Usart2_Config (CircularBuffer *rxB,CircularBuffer *txB);

void WriteChar (uint8_t c);
uint32_t ReadChar (void);

void WriteStr (char *string);
void ReadStr (char * p);
void sendArray( char * data, uint32_t length );
//////////usart//////////
/*int32_t UART_read_byte(void);
uint32_t UART_bytes_to_read(void);

void UART_send_byte(uint8_t data);
void UART_send_byte_array(uint8_t* buffer, uint32_t size);
uint32_t UART_bytes_to_write(void);

*/


#endif /* INC_USART2_DRIVER_H_ */
