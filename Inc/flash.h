/*
 * flash.h
 *
 *  Created on: Jun 21, 2023
 *      Author: murat
 */

#ifndef INC_FLASH_H_
#define INC_FLASH_H_

#include <stdbool.h>
#include <stdint.h>



#define APPLICATION_START_ADDRESS 0x08020000
#define FLASH_SECTOR_COUNT 12


#define FLASH_RETURN_SUCCESS        1
#define FLASH_RETURN_FAILED         0


//#define FLASH_WaitWhileBusy() { while (FLASH->SR & FLASH_SR_BSY){} }

size_t FLASH_SectorSize(uint8_t sector);
uint8_t FLASH_Unlock(void);
void FLASH_Lock(void);
uint8_t FLASH_Erase(unsigned long sector);
void FLASH_Write(uint32_t address, uint32_t data);
uint8_t FLASH_WriteBuffer(uint32_t address, uint32_t * dataBuffer, size_t size);
uint8_t FLASH_Read(uint32_t address, uint32_t *buffer, size_t size);
uint8_t FLASH_R(uint32_t address);

#endif /* INC_FLASH_H_ */
