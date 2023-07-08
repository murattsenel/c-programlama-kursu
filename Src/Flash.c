/*
 * Flash.c
 *
 *  Created on: Jun 21, 2023
 *      Author: murat
 */
#include "stm32f4xx.h"
#include "string.h"
#include "flash.h"
#include "CB.h"


size_t FLASH_SectorSize(uint8_t sector)
{
    if (sector >= 0 && sector <= 3) {
        return (16 * 1024);
    } else if (sector == 4) {
        return (64 * 1024);
    } else if (sector >= 5 && sector <= 11) {
        return (128 * 1024);
    }

    return 0;
}

uint8_t FLASH_Unlock(void)
{
    /* Check if unlock is really needed */
    if (!(FLASH->CR & FLASH_CR_LOCK)) {
        return FLASH_RETURN_SUCCESS;
    }

    /* Write magic unlock sequence */
    FLASH->KEYR = 0x45670123;
    FLASH->KEYR = 0xCDEF89AB;

    /* Check if unlock was successful */
    if (FLASH->CR & FLASH_CR_LOCK) {
        return FLASH_RETURN_FAILED;
    }

    return FLASH_RETURN_SUCCESS;
}

void FLASH_Lock(void)
{
    FLASH->CR |= 0x80000000; // FLASH_CR_LOCK = 0x80000000;
}


uint8_t FLASH_Erase(unsigned long sector)
{

    if (FLASH_Unlock() == FLASH_RETURN_FAILED) {
        return FLASH_RETURN_FAILED;
    }

    while (FLASH->SR & FLASH_SR_BSY);

    CLEAR_BIT(FLASH->CR, FLASH_CR_PSIZE);
    FLASH->CR |= (1<<9);
    FLASH->CR |= (0<<0);
    CLEAR_BIT(FLASH->CR, FLASH_CR_SNB);
    sector = sector & 0x0F;
    FLASH->CR |= FLASH_CR_SER;			// Sector Erase Flag
    FLASH->CR |= (sector << 3);			// Sector Number to SNB
    FLASH->CR |= FLASH_CR_STRT;			// Sector Erase Start

    while (FLASH->SR & FLASH_SR_BSY);

    /* Sector erase flag does not clear automatically. */
    FLASH->CR &= ~FLASH_CR_SER;

    return FLASH_RETURN_SUCCESS;
}

void FLASH_Write(uint32_t address, uint32_t data)
{
    /* Enter flash programming mode */
	 //CLEAR_BIT(FLASH->CR, FLASH_CR_PSIZE);

    FLASH->CR |= (1<<9);
    FLASH->CR |= (0<<0);
    FLASH->CR |= FLASH_CR_PG;
    /* Write the data */
    *(uint32_t *)address = data;

    /* Wait for completion */
    while (FLASH->SR & FLASH_SR_BSY);

    /* Exit flash programming mode */
    FLASH->CR &= ~FLASH_CR_PG;
}

uint8_t FLASH_WriteBuffer(uint32_t address, uint32_t * dataBuffer, size_t size)
{


		/* Unlock flash for write access */
    if (FLASH_Unlock() == FLASH_RETURN_FAILED) {
        return FLASH_RETURN_FAILED;
    }

    /* Wait for any busy flags */
    while (FLASH->SR & FLASH_SR_BSY);

    while (size >= sizeof(*dataBuffer)) {
        FLASH_Write(address, *dataBuffer);
        address += sizeof(*dataBuffer);
        dataBuffer++;
        size -= sizeof(*dataBuffer);
    }

    return FLASH_RETURN_SUCCESS;
}

uint8_t FLASH_Read(uint32_t address, uint32_t * buffer, size_t size)
{
    memcpy(buffer, (uint32_t*) address, size);
    return FLASH_RETURN_SUCCESS;
}
uint8_t FLASH_R(uint32_t address)
{
   return *(uint32_t*) address;
}
