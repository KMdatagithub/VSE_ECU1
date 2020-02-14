/*
 * SPI.h
 *
 * Created: 2/9/2020 3:26:53 PM
 *  Author: Khaled Magdy
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "SPI_cfg.h"
#include "gpio.h"
#include "registers.h"
#include "interrupts.h"

typedef enum En_spiMode_t{
	SPI_Master = 0x50, SPI_Slave = 0x40
}En_spiMode_t;

typedef enum En_spiModeNumber_t{
	SPI_Mode0 = 0x00, SPI_Mode1 = 0x04, SPI_Mode2 = 0x08, SPI_Mode3 = 0x0C
}En_spiModeNumber_t;

typedef enum En_spiClkRate_t{
	SPI_CLK_F_4 = 0, SPI_CLK_F_16 = 0x01, SPI_CLK_F_64 = 0x02, SPI_CLK_F_128 = 0x03
}En_spiClkRate_t;

typedef enum En_spiDataOrder_t{
	LSB_First = 0x20, MSB_First = 0
}En_spiDataOrder_t;

typedef enum En_spiInterrupts_t{
	SPI_Interrupts_Enabled = 0x80, SPI_Interrupts_Disabled = 0
}En_spiInterrupts_t;

//----------------------------------------------------------

void SPI_Init(En_spiMode_t, En_spiClkRate_t, En_spiModeNumber_t, En_spiDataOrder_t, En_spiInterrupts_t);
void SPI_Write(uint8_t);
void SPI_Write_String(uint8_t*);


#endif /* SPI_H_ */