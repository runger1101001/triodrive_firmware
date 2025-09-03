#pragma once

// TODO these should move to board file
#define HAL_QSPI_MODULE_DISABLED
#define DHAL_FDCAN_MODULE_ENABLED
#define USBCON
#define USBD_USE_CDC
#define HSE_VALUE 25000000U

#include <variant_generic.h>

#define M1_INUH_PIN         PC6
#define M1_INUL_PIN         PB3
#define M1_INVH_PIN         PC7
#define M1_INVL_PIN         PB4
#define M1_INWH_PIN         PC9
#define M1_INWL_PIN         PD0

#define M1_AOUTU_PIN        PA1
#define M1_AOUTV_PIN        PA2
#define M1_AOUTW_PIN        PA3

#define M1_nFAULT_PIN       PD8
#define M1_nSLEEP_PIN       PD9

#define M2_INUH_PIN         PC6
#define M2_INUL_PIN         PB3
#define M2_INVH_PIN         PC7
#define M2_INVL_PIN         PB4
#define M2_INWH_PIN         PC9
#define M2_INWL_PIN         PD0

#define M2_AOUTU_PIN        PA1
#define M2_AOUTV_PIN        PA2
#define M2_AOUTW_PIN        PA3

#define M2_nFAULT_PIN       PD8
#define M2_nSLEEP_PIN       PD9

#define M3_INUH_PIN         PC6
#define M3_INUL_PIN         PB3
#define M3_INVH_PIN         PC7
#define M3_INVL_PIN         PB4
#define M3_INWH_PIN         PC9
#define M3_INWL_PIN         PD0

#define M3_AOUTU_PIN        PA1
#define M3_AOUTV_PIN        PA2
#define M3_AOUTW_PIN        PA3

#define M3_nFAULT_PIN       PD8
#define M3_nSLEEP_PIN       PD9

// adc measurement
#define VBAT_PIN            PB2
#define VBAT_GAIN           ((2.2f+47.0f)/2.2f)
#define CURRENT_VpA         (2200.0f/9200.0f)

// spi bus 1 - Sensor 1
#define SENSOR1_nCS_PIN     PA4
#define CIPO1_PIN           PA6
#define COPI1_PIN           PA7
#define SCLK1_PIN           PA5
//extern SPIClass SPI_Sensor1;

// spi bus 2 - Sensor 2
#define SENSOR2_nCS_PIN     PB12
#define CIPO2_PIN           PB14
#define COPI2_PIN           PB15
#define SCLK2_PIN           PB13
//extern SPIClass SPI_Sensor2;

// spi bus 3 - Sensor 3
#define SENSOR3_nCS_PIN        PA15
#define CIPO3_PIN           PC11
#define COPI3_PIN           PC12
#define SCLK3_PIN           PC10
//extern SPIClass SPI_Sensor3;

// abz input 1
#define ABZ1_A_PIN          PB0
#define ABZ1_B_PIN          PB1
#define ABZ1_Z_PIN          PC13

// abz input 2
#define ABZ2_A_PIN          PB0
#define ABZ2_B_PIN          PB1
#define ABZ2_Z_PIN          PC13

// abz input 3
#define ABZ3_A_PIN          PB0
#define ABZ3_B_PIN          PB1
#define ABZ3_Z_PIN          PC13

// pwm input 1
#define PWM1_PIN            PB0
#define PWM1_TIM            TIM3

// pwm input 2
#define PWM2_PIN            PB0
#define PWM2_TIM            TIM3

// pwm input 3
#define PWM3_PIN            PB0
#define PWM3_TIM            TIM3

// i2c bus 1
#define I2C1_SCL_PIN        PA9
#define I2C1_SDA_PIN        PA8

// can bus
#define CAN_RX_PIN          PB8
#define CAN_TX_PIN          PB9

// uart
// TODO uart pins, define default Serial to the correct uart