/*
 * SPI_interfce.h
 *
 * Created: 5/1/2023 8:13:49 PM
 *  Author: mohab
 */ 


#ifndef SPI_INTERFCE_H_
#define SPI_INTERFCE_H_

#include "SERVICE/standard_types.h"
#include "DIO/DIO_interface.h"

void SPI_init(void);

void Master_send(uint8_t data);

void Master_recieve(void);



#endif /* SPI_INTERFCE_H_ */