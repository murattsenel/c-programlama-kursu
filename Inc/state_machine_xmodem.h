/*
 * state_machine_xmodem.h
 *
 *  Created on: Jun 16, 2023
 *      Author: murat
 */

#ifndef INC_STATE_MACHINE_XMODEM_H_
#define INC_STATE_MACHINE_XMODEM_H_

#define EMPTY 0x00
#define SOH 0x01
#define EOT 0x04
#define ACK 0x06
#define NAK 0x15
#define CAN 0x18

typedef enum{

	XMODEM_WAIT_SOH=0,
	XMODEM_WAIT_PACKET_INDEX,
	XMODEM_WAIT_PACKET_INDEX_COMPLEMENT,
	XMODEM_WAIT_PACKET_DATA,
	XMODEM_WAIT_PACKET_CHECKSUM,
}XMODEM_STATES;

#include <CB.h>
#define DATA_SİZE    132


typedef struct  {
	 uint8_t command ;
    uint8_t blockNumber ;
    uint8_t blockNumberComplement ;
    uint8_t data[128];
    uint8_t checksum ;
    uint8_t NAKflag ;
    uint16_t bytesRead;
    uint16_t packetNumber;
} xmodem_Packet;

void initializeXmodemData(xmodem_Packet * buff,CircularBuffer *rxBf,CircularBuffer *txBf);
uint8_t calculateChecksum(const uint8_t *data, size_t length);

#endif /* INC_STATE_MACHINE_XMODEM_H_ */
