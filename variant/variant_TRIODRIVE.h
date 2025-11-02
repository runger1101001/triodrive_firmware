#pragma once

//#define HAL_FDCAN_MODULE_ENABLED
//#define USBCON
//#define USBD_USE_CDC
//#define HSE_VALUE 25000000U
#define HAL_QSPI_MODULE_DISABLED
#define SERIAL_UART_INSTANCE 3

#include <variant_generic.h>

// M1 on TIM1
#define M1_INU_PIN          PC0
#define M1_INV_PIN          PC1
#define M1_INW_PIN          PC2

// PA3 = ADC1_IN4, PA2 = ADC1_IN3, PA1 = ADC1_IN2
#define M1_AOUTU_PIN        PA3
#define M1_AOUTV_PIN        PA2
#define M1_AOUTW_PIN        PA1

#define M1_nFAULT_PIN       PC13
#define M1_nSLEEP_PIN       PC14
#define M1_EN_PIN           PC15

// M2 on TIM4
#define M2_INU_PIN          PB7
#define M2_INV_PIN          PB8
#define M2_INW_PIN          PB9

// PA7 = ADC2_IN4, PC4 = ADC2_IN5, PC5 = ADC2_IN11
#define M2_AOUTU_PIN        PA7
#define M2_AOUTV_PIN        PC4
#define M2_AOUTW_PIN        PC5

#define M2_nFAULT_PIN       PE8
#define M2_nSLEEP_PIN       PE10
#define M2_EN_PIN           PB13

// M3 on TIM8
#define M3_INU_PIN          PC6
#define M3_INV_PIN          PC7
#define M3_INW_PIN          PC8

// PB1 = ADC3_IN1, PE7 = ADC3_IN4, PE9 = ADC3_IN2
#define M3_AOUTU_PIN        PB1
#define M3_AOUTV_PIN        PE7
#define M3_AOUTW_PIN        PE9

#define M3_nFAULT_PIN       PD8
#define M3_nSLEEP_PIN       PD9
#define M3_EN_PIN           PA9

// adc measurement
#define VBAT_PIN            
#define VBAT_GAIN           ((2.2f+47.0f)/2.2f)
#define CURRENT_VpA         (2200.0f/9200.0f)

// spi bus 2 - Sensor 2
#define SENSOR2_nCS_PIN     PB0
#define CIPO2_PIN           PA10
#define COPI2_PIN           PB15
#define SCLK2_PIN           PF1
//extern SPIClass SPI_Sensor1;

// spi bus 3 - Sensor 1
#define SENSOR1_nCS_PIN     PE11
#define CIPO1_PIN           PC_11
#define COPI1_PIN           PB_5_ALT1
#define SCLK1_PIN           PC_10
//extern SPIClass SPI_Sensor2;

// spi bus 4 - Sensor 3
#define SENSOR3_nCS_PIN     PC3
#define CIPO3_PIN           PE13
#define COPI3_PIN           PE14
#define SCLK3_PIN           PE12
//extern SPIClass SPI_Sensor3;

// abz input 1 - TIM2
#define ABZ1_A_PIN          PA5
#define ABZ1_B_PIN          PB3
#define ABZ1_Z_PIN          PA15

// abz input 2 - TIM3
#define ABZ2_A_PIN          PA6
#define ABZ2_B_PIN          PA4
#define ABZ2_Z_PIN          PD2

// abz input 3 - TIM5
#define ABZ3_A_PIN          PA0
#define ABZ3_B_PIN          PC12
#define ABZ3_Z_PIN          PB12

// pwm input 1 
#define PWM1_PIN            PB14
#define PWM1_TIM            TIM15

// i2c bus 1 - I2C3
#define I2C1_SCL_PIN        PA8
#define I2C1_SDA_PIN        PC9

// can bus
#define CAN_RX_PIN          PD0
#define CAN_TX_PIN          PD1

// uart - USART3
#define PIN_SERIAL3_RX         PE15
#define PIN_SERIAL3_TX         PB10

#define LED_MCU_PIN         PB11


// uart
// TODO uart pins, define default Serial to the correct uart