// Nombre de archivo: DAC_config.h

// Autores:

// Ernesto Ariel Arciniega Rivera
// Luis Fernando Macías Sepúlveda
// Iván Ramón Urbina Leos

// Institución: TECNM campus Chihuahua

// Fecha: 30/11/2022

#pragma once

#include "soc/rtc_io_struct.h"
#include "soc/sens_struct.h"
#include "hal/misc.h"
#include "driver/rtc_io.h"
#include <unistd.h>
#include <math.h>
#include <stdbool.h>

#define pi M_PI

#ifdef __cplusplus
extern "C" {
#endif

//Definicion de cada canal segun su pin de GPIO
#define DAC_CHANNEL_1_GPIO 25
#define DAC_CHANNEL_2_GPIO 26

//Constantes usadas en las funciones de generador de señale para definir la frecuencia de la señal
#define F_1Hz    1
#define F_5Hz    2
#define F_10Hz   3
#define F_100Hz  4

//Enumeracion que se envia como parametro a las funciones de activar/desactivar canal y hacer el uso de los mismos
typedef enum
{
    DAC_CANAL_1 = 0,
    DAC_CANAL_2 = 1,
    DAC_CANAL_MAX,
} dac_channel_x;

//Estrucutra para ubicar los 2 canales segun su número de pin de GPIO
typedef struct
{
    const uint8_t dac_channel_io_num[2]; //Dos pines de DAC
} dac_signal_conn_x;

//Enumeración para la identidicación de los pines de GPIO
typedef enum
{
    GPIO_NC = -1,
    GPIO_0 = 0,     //GPIO 0
    GPIO_1 = 1,     //GPIO 1
    GPIO_2 = 2,     //GPIO 2
    GPIO_3 = 3,     //GPIO 3
    GPIO_4 = 4,     //GPIO 4
    GPIO_5 = 5,     //GPIO 5
    GPIO_6 = 6,     //GPIO 6
    GPIO_7 = 7,     //GPIO 7
    GPIO_8 = 8,     //GPIO 8
    GPIO_9 = 9,     //GPIO 9
    GPIO_10 = 10,   //GPIO 10
    GPIO_11 = 11,   //GPIO 11
    GPIO_12 = 12,   //GPIO 12
    GPIO_13 = 13,   //GPIO 13
    GPIO_14 = 14,   //GPIO 14
    GPIO_15 = 15,   //GPIO 15
    GPIO_16 = 16,   //GPIO 16
    GPIO_17 = 17,   //GPIO 17
    GPIO_18 = 18,   //GPIO 18
    GPIO_19 = 19,   //GPIO 19
    GPIO_20 = 20,   //GPIO 20
    GPIO_21 = 21,   //GPIO 21
    GPIO_22 = 22,   //GPIO 22
    GPIO_23 = 23,   //GPIO 23
    GPIO_25 = 25,   //GPIO 25
    GPIO_26 = 26,   //GPIO 26
    GPIO_27 = 27,   //GPIO 27
    GPIO_28 = 28,   //GPIO 28
    GPIO_29 = 29,   //GPIO 29
    GPIO_30 = 30,   //GPIO 30
    GPIO_31 = 31,   //GPIO 31
    GPIO_32 = 32,   //GPIO 32
    GPIO_33 = 33,   //GPIO 33
    GPIO_34 = 34,   //GPIO 34
    GPIO_35 = 35,   //GPIO 35
    GPIO_36 = 36,   //GPIO 36
    GPIO_37 = 37,   //GPIO 37
    GPIO_38 = 38,   //GPIO 38
    GPIO_39 = 39,   //GPIO 39
    GPIO_MAX,
} gpio_num_x;

#ifdef __cplusplus
}
#endif
