/*
 * SPI_cfg.h
 *
 * Created: 2/9/2020 3:27:10 PM
 *  Author: Khaled Magdy
 */ 


#ifndef SPI_CFG_H_
#define SPI_CFG_H_


#define F_cpu	16000000UL

#define MISO_GPIO	GPIOB
#define MISO_BIT	BIT6

#define MOSI_GPIO	GPIOB
#define MOSI_BIT	BIT5

#define SCK_GPIO	GPIOB
#define SCK_BIT		BIT7

#define SS_GPIO		GPIOB
#define SS_BIT		BIT4

#endif /* SPI_CFG_H_ */