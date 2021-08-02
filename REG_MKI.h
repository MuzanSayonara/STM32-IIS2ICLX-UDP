/*
 * REG_MKI.h
 *
  ******************************************************************************
  * @file    REG_MKI.h
  * @brief   This Header is for all the sensor's registers.
  ******************************************************************************
  * Created on: May , 2021
  *      Author: RAZZOUK Ali
  *
 ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef INC_REG_MKI_H_
#define INC_REG_MKI_H_

#ifdef __cplusplus
 extern "C" {
#endif

 /* Private defines -----------------------------------------------------------*/

#define ONE 0x80 /* it's to add 0b10000000 to a register to pass him to read mode*/

//EThernet Address : 00:80:E1:00:00:00

 /* Address of the Identity register to check the identity of the sensor */
#define ID_REG 0x0F

/* Register to see the state of Data-ready */
#define DEN_SRC 0x1D

 /* Register of the pin controls to check our pin controlling */
#define PIN_CTRL_REG 0x02

 /* To set The Cs pin to higher or lower its value*/
#define CS_PIN GPIO_PIN_7
#define CS_PINREG GPIOC

/* Set the Int1 Pin to execute */
#define INT_PIN GPIO_PIN_15
#define INT_PINREG GPIOD


// Registers of output data For X axis */
#define OUTX_L 0x28   /* Low 8 bits*/
#define OUTX_H 0x29   /* High 8 bits*/

// Registers of output data For Y axis
#define OUTY_L 0x2A   /* Low 8 bits*/
#define OUTY_H 0x2B   /* High 8 bits*/

// Offset Registers
#define X_OFFSET_REG 0x73
#define Y_OFFSET_REG 0x74

// Registers to check the state of our sensor ( If there is temperature data available as well as X and Y accelerations)
#define STATUS_REG 0x1E
#define TAP_SRC 0x1C
#define WAKE_UP 0x1A

/* --------------- Control Commands ------------------- */
// CTR1XL
#define CTRL1_XL 0x10 /* Register to configure ODR and FS */

/*Predefined 8bits Data to write in CTRL1XL to set ODR and FS */

#define ODR104HZ0_5G  0x40 /* ODR = 104 HZ and FS = 0.5 */
#define ODR104HZ1G    0x48 /* ODR = 104 HZ and FS = 1 */

/* Predefined Sensitivity For each FS */
#define S0_5 0.015
#define S1 0.031
#define S2 0.061
#define S3 0.122

// CTRL3C
#define CTRL3C 0x12 /* Register for Spi to set the read/write register */

/*Predefined 8bits Data to write in CTRL3C */

#define SPI0MODE 0x00

/* ----------------------------------------------------- */

/* For Interrupt setting */

// INT Registers
#define INT1_CTRL 0x0D
#define INT2_CTRL 0x0E

// REGISTERS TO CONFIGURE INT MODE
#define MD1_CFG 0x5E
#define MD2_CFG 0x5F
#define COUNTER_BDR_REG1 0x0B

/* CONTROL OF INT SOURCES */
#define DENRDYMODE 0x01 /* To set our Interrupt to act if a new (X,Y) data is available*/
#define MOTIONMODE 0x80 /* To write to the MD1CFG for motion mode in the INT*/
#define DEFAULTMODE 0x00

#ifdef __GNUC__
/* With GCC Compiler, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/*END private defines */



#ifdef __cplusplus
}
#endif

#endif /* INC_REG_MKI_H_ */
