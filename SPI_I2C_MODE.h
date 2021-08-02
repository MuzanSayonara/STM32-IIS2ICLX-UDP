
/**
  ******************************************************************************
  * @file    SPI_I2C_MODES.h
  * @brief   This Header is for the SPI/I2C communication mode and for inner configuration of it.
  ******************************************************************************
  * Created on: May , 2021
  *      Author: RAZZOUK Ali
  *
 ******************************************************************************
  */
/* USER CODE END Header */

#ifndef INC_SPI_I2C_MODE_H_
#define INC_SPI_I2C_MODE_H_

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Exported functions prototypes ---------------------------------------------*/

/*----------------------------------------SPI_MODE---------------------------------------------------*/
void Set_CS_High(void);
void Set_CS_Low(void);
//Normal Mode
void TestBegin_SPI(void);
void TestId_SPI(void);
void Ctrl1_SPI(uint8_t reg_value);
int X_ACCValue_SPI(float Sensitivity);
int Y_ACCValue_SPI(float Sensitivity);
void Measure_SPI(float Sensitivity,int* T);
//IT Mode
float X_ACCValue_SPI_IT(float Sensitivity);
float Y_ACCValue_SPI_IT(float Sensitivity);
// Setting up INT(1/2)
void IntMode_SPI(uint8_t INT_REG , uint8_t MODE_VALUE);
void MDMode_SPI(uint8_t MD_REG , uint8_t MODE_VALUE);
void IntCFGMode_SPI(uint8_t INT_REG , uint8_t MODE_VALUE);

/*-----------------------------------------I2C_MODE-------------------------------------------------*/
//Normal Mode
void TestBegin_I2C(void);
void TestId_I2C(void);  /* Reading the Id of our Sensor */
void TestControlPin_I2C(void);
void Ctrl1_I2C(uint8_t reg_value); /*Giving proper control using register CTRL1_XL*/
float X_ACCValue_I2C(float Sensitivity); /*Measure of X's acceleration and returning it */
float Y_ACCValue_I2C(float Sensitivity); /*Measure of Y's acceleration and returning it */
void Measure_I2C(float Sensitivity, int* T);
// IT Mode
float X_ACCValue_I2C_IT(float Sensitivity);
float Y_ACCValue_I2C_IT(float Sensitivity);

// Setting up INT(1/2)
void IntMode_I2C(uint8_t INT_REG , uint8_t MODE_VALUE);
void MDMode_I2C(uint8_t MD_REG , uint8_t MODE_VALUE);
void IntCFGMode_I2C(uint8_t INT_REG , uint8_t MODE_VALUE);


#endif /* INC_SPI_I2C_MODE_H_ */
