/*
 * state_machine_xmodem.c
 *
 *  Created on: Jun 16, 2023
 *      Author: murat
 */

#include "state_machine_xmodem.h"
#include "CB.h"
#include "Usart2_Driver.h"
#include"stm32f4xx_hal.h"
#include "stdio.h"
#include "flash.h"

xmodem_Packet *xmodem;
CircularBuffer *rxBuf;
CircularBuffer *txBuf;

void initializeXmodemData( xmodem_Packet* buff ,CircularBuffer *rxBf,CircularBuffer *txBf){

	xmodem=buff;

	rxBuf = rxBf;
	txBuf = rxBf;
	memset(buff->data,0,128);
	xmodem->blockNumber=1;
	xmodem->blockNumberComplement = 255-xmodem->blockNumber;
	xmodem->command = 0 ;
	 xmodem->checksum = 0;
	xmodem->bytesRead = 0 ;
	xmodem->packetNumber = 0;
	xmodem->NAKflag = 1;


}

uint8_t calculateChecksum(const uint8_t *data, size_t length) {
	uint8_t checksum = 0;

    for (uint16_t i = 0; i < length; i++) {
        checksum += data[i];
    }

    return checksum;
}

XMODEM_STATES xmodemState=XMODEM_WAIT_SOH;
uint8_t padding =0;


void state_machine(void){

	if(xmodem->NAKflag==1)
	{
		WriteChar(NAK);
		sendArray("Dosya bekleniyor.", 17 );
		Delay_ms(3000);
	}
     uint8_t ch = 0 ;
   uint32_t address = APPLICATION_START_ADDRESS;

   if(readCircularBuffer(rxBuf,&ch ))

	   {

	switch(xmodemState)
	      {



	      case XMODEM_WAIT_SOH:

	    	  xmodem->NAKflag=0;


        	    if ( ch == SOH){
	    	  	  xmodemState = XMODEM_WAIT_PACKET_INDEX;
	    	  	  xmodem->command = ch;
	    	  }
	    	  else if(ch==EOT)

	    	  {    WriteChar(ACK);
	    		  sendArray("Dosya aktarimi bitti.", 21 );

	    		  memset(xmodem->data,0,128);

	    		  	xmodem->blockNumber=1;
	    		  	xmodem->blockNumberComplement = 255-xmodem->blockNumber;
	    		  	xmodem->command = 0 ;
	    		  	 xmodem->checksum = 0;
	    		  	xmodem->bytesRead = 0 ;
	    		  	xmodem->packetNumber = 0;

	    		  	xmodem->NAKflag = 1;

	    	  }
	    	  else if(ch==CAN)
	    	  {
	    		  sendArray("Dosya aktarimi iptal edildi.", 28 );
	    	  }

	    	  break;


	          case XMODEM_WAIT_PACKET_INDEX	:


	        	  if (xmodem->blockNumber == ch)
	        	  {
	        		  xmodemState = XMODEM_WAIT_PACKET_INDEX_COMPLEMENT;
	        		  padding = ch;
	        	  }
	        	  else
	        	  {
	        		  xmodemState = XMODEM_WAIT_SOH;
	        		  WriteChar(NAK);
	        		  CurcilarBufferReset(rxBuf);

	        	  }
	        	  break;


	          case XMODEM_WAIT_PACKET_INDEX_COMPLEMENT	:
	        	   if (xmodem->blockNumberComplement == ch)
	        	    {
	        	  	   xmodemState = XMODEM_WAIT_PACKET_DATA;
	        	  	}
	        	  	else
	        	  	{
	        	  	   xmodemState = XMODEM_WAIT_SOH;
	        	  	   WriteChar(NAK);
	        	  	   CurcilarBufferReset(rxBuf);
	        	  	}
	        	  	break;


	          case XMODEM_WAIT_PACKET_DATA	:

	        		  xmodem->data[xmodem->bytesRead] = ch;
	        		  xmodem->bytesRead++;

	        	  if(xmodem->bytesRead==128)
	        	  {
	        		  xmodemState = XMODEM_WAIT_PACKET_CHECKSUM;
	        	  }
	        	  break;


	          case XMODEM_WAIT_PACKET_CHECKSUM	:
	        	  xmodem->checksum=calculateChecksum(xmodem->data, xmodem->bytesRead);
	        	  if((xmodem->checksum)==ch)
	        	  {

	        		  if( xmodem->packetNumber==0 )
	        		  {

	        			  for(unsigned long i = 5 ; i<=11 ;++i)
	        			  {
	        				  FLASH_Unlock();
	        			   while(!FLASH_Erase(i));
	        			   FLASH_Lock();
	        			  }

	        		  }
	        		     FLASH_Unlock();
                         address += (uint32_t) xmodem->packetNumber *128;



	        		  FLASH_WriteBuffer(address, ((uint32_t*)xmodem->data) , 128);
	        		  FLASH_Lock();

	        		  xmodem->blockNumber++;
	        		  xmodem->blockNumberComplement = 255-xmodem->blockNumber;
	        		  xmodem->packetNumber++;
	        		  xmodem->bytesRead =0;
					  WriteChar(ACK);
					  xmodemState = XMODEM_WAIT_SOH;


	        	  }
	        	  else
	        	  {
	        		  WriteChar(NAK);
	        		  xmodemState = XMODEM_WAIT_SOH;
	        	  }




	         }
      }
}
