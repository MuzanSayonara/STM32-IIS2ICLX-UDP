/*
 * SPI_I2C_MODE.c
 *
  ******************************************************************************
  * @file    SPI_I2C_MODE.c
  * @brief   This file is for predefined functions for SPI/I2C MODE for the sensor.
  ******************************************************************************
  * Created on: May , 2021
  *      Author: RAZZOUK Ali
  *
 ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f2xx_it.h"
#include "REG_MKI.h"

/*Declaration of extern variables to not block the program*/
extern SPI_HandleTypeDef hspi1;
extern I2C_HandleTypeDef hi2c1;

/*----------------------------------------SPI_MODE---------------------------------------------------*/
void Set_CS_High(void){

	HAL_GPIO_WritePin(CS_PINREG,CS_PIN, GPIO_PIN_SET);
}
void Set_CS_Low(void){

	HAL_GPIO_WritePin(CS_PINREG,CS_PIN, GPIO_PIN_RESET);
}

void TestBegin_SPI(void){
	printf("SPI Test : TEST-SPI_MKI ! \r\n");
	/* Testing if the Slave(Sensor) responds to our signals by sending back it's identity, Pin control's code and both offsets*/
}

void TestId_SPI(void){
	/* Reading the Id of our Sensor, in this case : 6B */
	uint8_t pData;

	pData = ONE | ID_REG;
	Set_CS_Low();
	HAL_SPI_Transmit(&hspi1, &pData, 1,100);
    HAL_SPI_Receive(&hspi1, &pData, 1 ,100);
	printf("-My address is %x \r\n", pData);
	Set_CS_High();
}

void Ctrl1_SPI(uint8_t reg_value){
	/* Giving proper control using register CTRL1_XL */
	/* reg is a register that defines the type of ODR the user wants and the default g (see sensor's Datasheet)*/
	uint8_t pData[2];
	pData[0] =  CTRL1_XL ;
	pData[1] = reg_value;
	Set_CS_Low();
	HAL_SPI_Transmit(&hspi1, (uint8_t *)pData , 2, 100);
	Set_CS_High();
}

//.................Normal Mode.....................
int X_ACCValue_SPI(float Sensitivity){
	/* Measure of X's acceleration,printing it and returning it (Warning = The value is with -mg- )*/
	HAL_StatusTypeDef ret;
	uint8_t Xl = ONE | OUTX_L;
	uint8_t Xh = ONE | OUTX_H ;
	int16_t Value;
	int Results;

	Set_CS_Low();
	HAL_SPI_Transmit(&hspi1, &Xl , 1 , 100 );
	ret = HAL_SPI_Receive(&hspi1, &Xl , 1 ,100);
	if(ret != HAL_OK){ printf("Error reading! \r\n");}  /* This function helps us to see if the reading is done well */
	Set_CS_High();

	Set_CS_Low();
	HAL_SPI_Transmit(&hspi1, &Xh , 1 ,100);
	ret = HAL_SPI_Receive(&hspi1, &Xh , 1,100);
	if(ret != HAL_OK){ printf("Error reading! \r\n");}  /* This function helps us to see if the reading is done well */

	Set_CS_High();

	Value = ((int16_t)Xh << 8)| Xl ;
	Results = Value * Sensitivity ;
    /*printf("- X acceleration is : %i g \r\n", Res /1000 );*/


    return Results;
}

int Y_ACCValue_SPI(float Sensitivity){
	/* Measure of X's acceleration,printing it and returning it (Warning = The value is with -mg- )*/
	HAL_StatusTypeDef ret;
	uint8_t Yl = ONE | OUTY_L;
	uint8_t Yh = ONE | OUTY_H ;
	int16_t Value;
	int Results;

	Set_CS_Low();
	HAL_SPI_Transmit(&hspi1, &Yl , 1 ,100);
	ret = HAL_SPI_Receive(&hspi1, &Yl , 1 ,100);
	if(ret != HAL_OK){ printf("Error reading! \r\n");}  /* This function helps us to see if the reading is done well */
	Set_CS_High();

	Set_CS_Low();
	HAL_SPI_Transmit(&hspi1, &Yh , 1 ,100);
	ret = HAL_SPI_Receive(&hspi1, &Yh , 1,100);
	if(ret != HAL_OK){ printf("Error reading! \r\n");}  /* This function helps us to see if the reading is done well */
	Set_CS_High();

	Value = ((int16_t)Yh << 8)| Yl ;
	Results = Value * Sensitivity ;
    /*printf("- Y acceleration is : %i g \r\n", Res /1000 );*/



    return Results;
}

//..........................IT MODE............................
float X_ACCValue_SPI_IT(float Sensitivity){
	/* Measure of X's acceleration,printing it and returning it (Warning = The value is with -mg- )*/
	HAL_StatusTypeDef ret;
	uint8_t Xl = ONE | OUTX_L;
	uint8_t Xh = ONE | OUTX_H ;
	int16_t Value;
	int Results;

	Set_CS_Low();
	HAL_SPI_Transmit_IT(&hspi1, &Xl , 1);
	ret = HAL_SPI_Receive_IT(&hspi1, &Xl , 1 );
	if(ret != HAL_OK){ printf("Error reading! \r\n");}  /* This function helps us to see if the reading is done well */
	Set_CS_High();

	Set_CS_Low();
	HAL_SPI_Transmit_IT(&hspi1, &Xh , 1);
	ret = HAL_SPI_Receive_IT(&hspi1, &Xh , 1);
	if(ret != HAL_OK){ printf("Error reading! \r\n");}  /* This function helps us to see if the reading is done well */

	Set_CS_High();

	Value = ((int16_t)Xh << 8)| Xl ;
	Results = Value * Sensitivity ;
    /*printf("- X acceleration is : %i g \r\n", Res /1000 );*/


    return Results;
}

float Y_ACCValue_SPI_IT(float Sensitivity){
	/* Measure of X's acceleration,printing it and returning it (Warning = The value is with -mg- )*/
	HAL_StatusTypeDef ret;
	uint8_t Yl = ONE | OUTY_L;
	uint8_t Yh = ONE | OUTY_H ;
	int16_t Value;
	int Results;

	Set_CS_Low();
	HAL_SPI_Transmit_IT(&hspi1, &Yl , 1);
	ret = HAL_SPI_Receive_IT(&hspi1, &Yl , 1 );
	if(ret != HAL_OK){ printf("Error reading! \r\n");}  /* This function helps us to see if the reading is done well */
	Set_CS_High();

	Set_CS_Low();
	HAL_SPI_Transmit_IT(&hspi1, &Yh , 1);
	ret = HAL_SPI_Receive_IT(&hspi1, &Yh , 1);
	if(ret != HAL_OK){ printf("Error reading! \r\n");}  /* This function helps us to see if the reading is done well */
	Set_CS_High();

	Value = ((int16_t)Yh << 8)| Yl ;
	Results = Value * Sensitivity ;
    /*printf("- Y acceleration is : %i g \r\n", Res /1000 );*/



    return Results;
}
//............INT configuration.....................
void IntMode_SPI(uint8_t INT_REG , uint8_t MODE_VALUE){
	uint8_t pData[2];
	pData[0] = INT_REG;
	pData[1] = MODE_VALUE;
	Set_CS_Low();
	HAL_SPI_Transmit(&hspi1, (uint8_t *)pData , 2,100);
	printf("INT mode Enabled \r\n");

	Set_CS_High();
}

void IntCFGMode_SPI(uint8_t INT_REG , uint8_t MODE_VALUE){
	uint8_t pData[2];
	pData[0] = INT_REG;
	pData[1] = MODE_VALUE;
	Set_CS_Low();
	HAL_SPI_Transmit(&hspi1, (uint8_t *)pData , 2,100);

	Set_CS_High();
}
void MDMode_SPI(uint8_t MD_REG , uint8_t MODE_VALUE){
	uint8_t pData[2];
	pData[0] = MD_REG;
	pData[1] = MODE_VALUE;
	Set_CS_Low();
	HAL_SPI_Transmit(&hspi1, (uint8_t *)pData , 2,100);
	Set_CS_High();
	printf("MD mode Enabled \r\n");
}

//......................Measure help..................
void Measure_SPI(float Sensitivity, int* T){
	int X_results;
	int Y_results;
	X_results = X_ACCValue_SPI(Sensitivity);
	Y_results = Y_ACCValue_SPI(Sensitivity);
	printf("------------------------------\r\n");
	printf("New Data ! \r\n");
	printf("- X acceleration is : %i mg \r\n", X_results );
	printf("- Y acceleration is : %i mg \r\n", Y_results );
	printf("------------------------------\r\n");
	 T[0] = X_results;
	 T[1] = Y_results;
}
//
//


/*------------------------------------I2C_MODE---------------------------------------------------*/
#define MKI_ADD 0x6A << 1 /* Address of the Sensor moved by 1 bit to leave it for Read/Write (0/1) */

void TestBegin_I2C(void){
	printf("I2C Test! \r\n");
}

void TestId_I2C(void){
	/* Reading the Id of our Sensor, in this case : 6B */
	uint8_t pData;
	HAL_I2C_Mem_Read(&hi2c1,  MKI_ADD, ID_REG, 1 , &pData, 1, 100);
	printf("-My address is %x \r\n", pData);
}


void Ctrl1_I2C(uint8_t reg_value){
	/* Giving proper control using register CTRL1_XL */
	/* reg is a register that defines the type of ODR the user wants and the default g (see sensor's Datasheet)*/
	uint8_t pData;
	pData = reg_value;
	HAL_I2C_Mem_Write(&hi2c1,  MKI_ADD, CTRL1_XL , 1 , &pData, 1, 200);
}

void TestControlPin_I2C(void){
	/* Reading the control pin 8bits of our Sensor, in this case : 3F (For Cs = HIGH and Cs0 = LOW ).*/
	uint8_t pData;
	HAL_I2C_Mem_Read(&hi2c1,  MKI_ADD, PIN_CTRL_REG, 1 , &pData, 1, 100);
	printf("-My pin's control binary code is : %x \r\n", pData);
}
//.................Normal Mode.....................
float X_ACCValue_I2C(float Sensitivity){
	/* Measure of X's acceleration,printing it and returning it (Warning = The value is with -mg- )*/
	HAL_StatusTypeDef ret;
	uint8_t pData;
	uint8_t pData2;
	int16_t Value;
	int Results;
	ret = HAL_I2C_Mem_Read(&hi2c1,  MKI_ADD, OUTX_L , 1 , &pData, 1, 100);
	if(ret != HAL_OK){ printf("Error reading! \r\n");}  /* This function helps us to see if the reading is done well */
	ret = HAL_I2C_Mem_Read(&hi2c1,  MKI_ADD, OUTX_H, 1 , &pData2, 1, 100);
	if(ret != HAL_OK){ printf("Error reading! \r\n");}  /* This function helps us to see if the reading is done well */

	Value = ((int16_t)pData2 << 8)| pData ;
	Results = Value * Sensitivity ;

    return Results;
}

float Y_ACCValue_I2C(float Sensitivity){
	/* Measure of Y's acceleration,printing it and returning it (Warning = The value is with -mg- ) */
	HAL_StatusTypeDef ret;
	uint8_t pData;
	uint8_t pData2;
	int16_t Value;
	int Results;
	ret = HAL_I2C_Mem_Read(&hi2c1,  MKI_ADD, OUTY_L , 1 , &pData, 1, 100);
	if(ret != HAL_OK){ printf("Error reading! \r\n");} /* This function helps us to see if the reading is done well*/
	ret = HAL_I2C_Mem_Read(&hi2c1,  MKI_ADD, OUTY_H, 1 , &pData2, 1, 100);
	if(ret != HAL_OK){ printf("Error reading! \r\n");}  /* This function helps us to see if the reading is done well*/

	Value = ((int16_t)pData2 << 8) | pData  ;
	Results = Value * Sensitivity ;

	return Results;
}

//.................IT Mode.....................

float X_ACCValue_I2C_IT(float Sensitivity){
	/* Measure of X's acceleration,printing it and returning it (Warning = The value is with -mg- )*/
	HAL_StatusTypeDef ret;
	uint8_t pData;
	uint8_t pData2;
	int16_t Value;
	int Results;
	ret = HAL_I2C_Mem_Read_IT(&hi2c1,  MKI_ADD, OUTX_L , 1 , &pData, 1);
	if(ret != HAL_OK){ printf("Error reading! \r\n");}  /* This function helps us to see if the reading is done well */
	ret = HAL_I2C_Mem_Read_IT(&hi2c1,  MKI_ADD, OUTX_H, 1 , &pData2, 1);
	if(ret != HAL_OK){ printf("Error reading! \r\n");}  /* This function helps us to see if the reading is done well */

	Value = ((int16_t)pData2 << 8)| pData ;
	Results = Value * Sensitivity ;

    return Results;
}

float Y_ACCValue_I2C_IT(float Sensitivity){
	/* Measure of Y's acceleration,printing it and returning it (Warning = The value is with -mg- ) */
	HAL_StatusTypeDef ret;
	uint8_t pData;
	uint8_t pData2;
	int16_t Value;
	int Results;
	ret = HAL_I2C_Mem_Read_IT(&hi2c1,  MKI_ADD, OUTY_L , 1 , &pData, 1);
	if(ret != HAL_OK){ printf("Error reading! \r\n");} /* This function helps us to see if the reading is done well*/
	ret = HAL_I2C_Mem_Read_IT(&hi2c1,  MKI_ADD, OUTY_H, 1 , &pData2, 1);
	if(ret != HAL_OK){ printf("Error reading! \r\n");}  /* This function helps us to see if the reading is done well*/

	Value = ((int16_t)pData2 << 8) | pData  ;
	Results = Value * Sensitivity ;
	return Results;
}
//............INT configuration.....................
void IntMode_I2C(uint8_t INT_REG , uint8_t MODE_VALUE){
	uint8_t pData;
	pData = MODE_VALUE;
	HAL_I2C_Mem_Write(&hi2c1,  MKI_ADD, INT_REG , 1 , &pData, 1, 200);
	printf("INT mode Enabled \r\n");

}

void IntCFGMode_I2C(uint8_t INT_REG , uint8_t MODE_VALUE){
	uint8_t pData;
	pData = MODE_VALUE ;
	HAL_I2C_Mem_Write(&hi2c1,  MKI_ADD, INT_REG , 1 , &pData, 1, 200);
}
void MDMode_I2C(uint8_t MD_REG , uint8_t MODE_VALUE){
	uint8_t pData;
	pData = MODE_VALUE ;
	HAL_I2C_Mem_Write(&hi2c1,  MKI_ADD, MD_REG , 1 , &pData, 1, 200);
	printf("MD mode Enabled \r\n");
}

//............  Measure help..................
void Measure_I2C(float Sensitivity , int* T){
	int X_results;
	int Y_results;
	X_results = X_ACCValue_I2C(Sensitivity);
	Y_results = Y_ACCValue_I2C(Sensitivity);
	printf("------------------------------\r\n");
	printf("New Data ! \r\n");
	printf("- X acceleration is : %i mg \r\n", X_results );
	printf("- Y acceleration is : %i mg \r\n", Y_results );
	printf("------------------------------\r\n");
	 T[0] = X_results;
	 T[1] = Y_results;


}
