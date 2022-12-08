// Nombre de archivo: Driver_DAC_E1.h

// Autores:
// Ernesto Ariel Arciniega Rivera
// Luis Fernando Macías Sepúlveda
// Iván Ramón Urbina Leos

// Institución: TECNM campus Chihuahua

// Fecha: 30/11/2022
#pragma once
#include "DAC_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************
* Function: Dac_enable_CH
* Preconditions: Ninguna
* Overview: Activa uno de los 2 canales conectados a GPIO 25 y 26
* Input: Canal (0 o 1)
* Output: Ninguna
*
*****************************************************************************/
void Dac_enable_CH(dac_channel_x channel);

/****************************************************************************
* Function: Dac_disable_CH
* Preconditions: Ninguna
* Overview: Desactiva uno de los 2 canales conectados a GPIO 25 y 26
* Input: Canal (0 o 1)
* Output: Ninguna
*
*****************************************************************************/
void Dac_disable_CH(dac_channel_x channel);

/****************************************************************************
* Function: Dac_out_voltage
* Preconditions: Haber llamado a la funcion Dac_enable_CH
* Overview: Saca un valor de voltaje de 0 a 3.3v segun la conversion del DAC
* Input: Canal y valor de 0-255 a convertir
* Output: Ninguna
*
*****************************************************************************/
void Dac_out_voltage(dac_channel_x channel, uint8_t value);

/****************************************************************************
* Function: Dac_dis_gpio
* Preconditions: Ninguna
* Overview: Deshabilita las funciones de GPIO del pin asociado al canal
* habilitado
* Input: Canal (0 o 1)
* Output: Ninguna
*
*****************************************************************************/
void Dac_dis_gpio(dac_channel_x channel);

/****************************************************************************
* Function: Dac_get_number
* Preconditions: Ninguna
* Overview: Obtiene el # de pin GPIO que corresponde al canal
* Input: Canal (0 o 1)
* Output: Ninguna
*
*****************************************************************************/
void Dac_get_number(dac_channel_x channel, gpio_num_x *gpio_num);

/****************************************************************************
* Function: Dac_ON
* Preconditions: Ninguns
* Overview: Enciende el módulo DAC
* Input: Canal (0 o 1)
* Output: Ninguna
*
*****************************************************************************/
void Dac_ON(dac_channel_x channel);

/****************************************************************************
* Function: Dac_OFF
* Preconditions: Ninguns
* Overview: Apaga el módulo DAC
* Input: Canal (0 o 1)
* Output: Ninguna
*
*****************************************************************************/
void Dac_OFF(dac_channel_x channel);

/****************************************************************************
* Function: Dac_syc_ADC
* Preconditions: Ninguna
* Overview: Habilita/deshabilita la operación sincrona entre ADC y DAC
* Input: Boleano
* Output: Ninguna
*
*****************************************************************************/
void Dac_syc_ADC(bool enable);

/****************************************************************************
* Function: Sin_DAC
* Preconditions: Haber llamado a la funcion Dac_enable_CH
* Overview: Genera una onda sinusoidal con el módulo
* Input: Canal (0 o 1) y entero para la frecuencia
* Output: Ninguna
*
*****************************************************************************/
void Sin_DAC(dac_channel_x channel,int frecuencia);

/****************************************************************************
* Function: Cos_DAC
* Preconditions: Haber llamado a la funcion Dac_enable_CH
* Overview: Genera una onda coseno con el módulo
* Input: Canal (0 o 1) y entero para la frecuencia
* Output: Ninguna
*
*****************************************************************************/
void Cos_DAC(dac_channel_x channel,int frecuencia);

/****************************************************************************
* Function: Triangle_DAC
* Preconditions: Haber llamado a la funcion Dac_enable_CH
* Overview: Genera una señal triangular con el módulo
* Input: Canal (0 o 1) y entero para la frecuencia
* Output: Ninguna
*
*****************************************************************************/
void Triangle_DAC(dac_channel_x channel,int frecuencia);

/****************************************************************************
* Function: Square_DAC
* Preconditions: Haber llamado a la funcion Dac_enable_CH
* Overview: Genera una señal cuadrada con el módulo
* Input: Canal (0 o 1) y entero para la frecuencia
* Output: Ninguna
*
*****************************************************************************/
void Square_DAC(dac_channel_x channel, int frecuencia);

#ifdef __cplusplus
}
#endif
