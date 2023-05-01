/*
 * SPI_program.c
 *
 * Created: 5/1/2023 8:14:23 PM
 *  Author: mohab
 */ 
#include "SPI_interfce.h"
#include "SERVICE/registers.h"



void SPI_init(void)
{
	DIO_setpindir(SPI_PORT, MOSI, OUTPUT);
	DIO_setpindir(SPI_PORT, SCK, OUTPUT);
	DIO_setpindir(SPI_PORT, SS, OUTPUT);
	DIO_setpindir(SPI_PORT, MISO, INPUT);
	
	DIO_setpinvalue(SPI_PORT, SS, HIGH);
	
	set_bit(SPCR,SPE);
	set_bit(SPCR,MSTR);
	set_bit(SPCR,SPR0);
	
	clear_bit(SPSR,SPI2X);
}

void Master_send(uint8_t data)
{
	uint8_t flush_Buffer;
	DIO_setpinvalue(SPI_PORT, SS, LOW);
	
	SPDR=data;
	
	while(!(SPSR & (1<<SPIF)));
	
	flush_Buffer = SPDR;
	
	DIO_setpinvalue(SPI_PORT, SS, HIGH);
}

void Master_recieve(void)
{
	uint8_t flush_buffer;
	SPDR= 0xFF;
	
	while(!(SPSR & (1<<SPIF)));
	
	flush_buffer = SPDR;
}