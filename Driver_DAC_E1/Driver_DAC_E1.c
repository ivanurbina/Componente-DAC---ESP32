// Nombre de archivo: Driver_DAC_E1.c

// Autores:
// Ernesto Ariel Arciniega Rivera
// Luis Fernando Macías Sepúlveda
// Iván Ramón Urbina Leos

// Institución: TECNM campus Chihuahua

// Fecha: 30/11/2022

#include "Driver_DAC_E1.h"

/*Llenado de estructura que define los canales de GPIO
donde se encuentra el DAC (25 y 26)*/
const dac_signal_conn_x dac_periph_signal =
{
    .dac_channel_io_num[0] = DAC_CHANNEL_1_GPIO,
    .dac_channel_io_num[1] = DAC_CHANNEL_2_GPIO,
};

/****************************************************************************
* Function: Dac_get_number
* Preconditions: Ninguna
* Overview: Obtiene el # de pin GPIO que corresponde al canal
* Input: Canal (0 o 1)
* Output: Ninguna
*
*****************************************************************************/
void Dac_get_number(dac_channel_x channel, gpio_num_x *gpio_num)
{
    *gpio_num = (gpio_num_x)dac_periph_signal.dac_channel_io_num[channel];
}

/****************************************************************************
* Function: Dac_dis_gpio
* Preconditions: Ninguna
* Overview: Deshabilita las funciones de GPIO del pin asociado al canal
* habilitado
* Input: Canal (0 o 1)
* Output: Ninguna
*
*****************************************************************************/
void Dac_dis_gpio(dac_channel_x channel)
{
    gpio_num_x gpio_num = 0;
    Dac_get_number(channel, &gpio_num);
    rtc_gpio_init(gpio_num);
    rtc_gpio_set_direction(gpio_num, RTC_GPIO_MODE_DISABLED);
    rtc_gpio_pullup_dis(gpio_num);
    rtc_gpio_pulldown_dis(gpio_num);
}

/****************************************************************************
* Function: Dac_ON
* Preconditions: Ninguns
* Overview: Enciende el módulo DAC
* Input: Canal (0 o 1)
* Output: Ninguno
*
*****************************************************************************/
void Dac_ON(dac_channel_x channel)
{
	RTCIO.pad_dac[channel].dac_xpd_force = 1;
	RTCIO.pad_dac[channel].xpd_dac = 1;
}

/****************************************************************************
* Function: Dac_OFF
* Preconditions: Ninguns
* Overview: Apaga el módulo DAC
* Input: Canal (0 o 1)
* Output: Ninguna
*
*****************************************************************************/
void Dac_OFF(dac_channel_x channel)
{
    RTCIO.pad_dac[channel].dac_xpd_force = 0;
    RTCIO.pad_dac[channel].xpd_dac = 0;
}

/****************************************************************************
* Function: Dac_syc_ADC
* Preconditions: Ninguna
* Overview: Habilita/deshabilita la operación sincrona entre ADC y DAC
* Input: Boleano
* Output: Ninguna
*
*****************************************************************************/
void Dac_syc_ADC(bool enable)
{
	SENS.sar_meas_ctrl2.sar1_dac_xpd_fsm = enable;
}

/****************************************************************************
* Function: Dac_enable_CH
* Preconditions: Ninguna
* Overview: Activa uno de los 2 canales conectados a GPIO 25 y 26
* Input: Canal (0 o 1)
* Output: Ninguna
*
*****************************************************************************/
void Dac_enable_CH(dac_channel_x channel)
{
	Dac_dis_gpio(channel);
	Dac_ON(channel);
	Dac_syc_ADC(false);
}

/****************************************************************************
* Function: Dac_disable_CH
* Preconditions: Ninguna
* Overview: Desactiva uno de los 2 canales conectados a GPIO 25 y 26
* Input: Canal (0 o 1)
* Output: Ninguna
*
*****************************************************************************/
void Dac_disable_CH(dac_channel_x channel)
{
	Dac_OFF(channel);
}

/****************************************************************************
* Function: Dac_out_voltage
* Preconditions: Haber llamado a la funcion Dac_enable_CH
* Overview: Saca un valor de voltaje de 0 a 3.3v segun la conversion del DAC
* Input: Canal y valor de 0-255 a convertir
* Output: Ninguna
*
*****************************************************************************/
void Dac_out_voltage(dac_channel_x channel, uint8_t value)
{
    if (channel == DAC_CANAL_1)
    {
        SENS.sar_dac_ctrl2.dac_cw_en1 = 0;
        HAL_FORCE_MODIFY_U32_REG_FIELD(RTCIO.pad_dac[channel], dac, value);
    }
    else if (channel == DAC_CANAL_2)
    {
        SENS.sar_dac_ctrl2.dac_cw_en2 = 0;
        HAL_FORCE_MODIFY_U32_REG_FIELD(RTCIO.pad_dac[channel], dac, value);
    }
}

/****************************************************************************
* Function: Sin_DAC
* Preconditions: Haber llamado a la funcion Dac_enable_CH
* Overview: Genera una onda sinusoidal con el módulo
* Input: Canal (0 o 1) y entero para la frecuencia
* Output: Ninguna
*
*****************************************************************************/
void Sin_DAC(dac_channel_x channel,int frecuencia)
{
	int deg,delay;

	switch(frecuencia)
	{
		case F_1Hz:
			delay = 2776;
		break;

		case F_5Hz:
			delay = 540;
		break;

		case F_10Hz:
			delay = 255;
		break;

		case F_100Hz:
			delay = 5;
		break;

		default:
			delay = 540;
	}

	Dac_enable_CH(channel);

	for(deg = 0; deg < 360; deg++)
	{
		Dac_out_voltage(channel, (int) (128 + 127 * (sin(deg * pi / 180))));
		usleep(delay);
	}
}

/****************************************************************************
* Function: Cos_DAC
* Preconditions: Haber llamado a la funcion Dac_enable_CH
* Overview: Genera una onda coseno con el módulo
* Input: Canal (0 o 1) y entero para la frecuencia
* Output: Ninguna
*
*****************************************************************************/
void Cos_DAC(dac_channel_x channel,int frecuencia)
{
	int deg,delay;

	switch(frecuencia)
	{
		case F_1Hz:
			delay = 2776;
		break;

		case F_5Hz:
			delay = 540;
		break;

		case F_10Hz:
			delay = 255;
		break;

		case F_100Hz:
			delay = 5;
		break;

		default:
			delay = 540;
	}

	Dac_enable_CH(channel);

	for(deg = 0; deg < 360; deg++)
	{
		Dac_out_voltage(channel, (int) (128 + 127 * (cos(deg * pi / 180))));
		usleep(delay);
	}
}

/****************************************************************************
* Function: Triangle_DAC
* Preconditions: Haber llamado a la funcion Dac_enable_CH
* Overview: Genera una señal triangular con el módulo
* Input: Canal (0 o 1) y entero para la frecuencia
* Output: Ninguna
*
*****************************************************************************/
void Triangle_DAC( dac_channel_x channel,int frecuencia)
{
	int t,delay;

	switch(frecuencia)
	{
		case F_1Hz:
			delay = 5000;
		break;

		case F_5Hz:
			delay = 1000;
		break;

		case F_10Hz:
			delay = 500;
		break;

		case F_100Hz:
			delay = 48;
		break;

		default:
			delay = 500;
	}

	for(t = 0; t < 100; t++)
	{
		Dac_out_voltage(channel, (int) (255 / 100)*t);
		usleep(delay);
	}

	for(t = 100; t > 0; t--)
	{
		Dac_out_voltage(channel, (int) ((255 / 100)*t));
		usleep(delay);
	}
}

/****************************************************************************
* Function: Square_DAC
* Preconditions: Haber llamado a la funcion Dac_enable_CH
* Overview: Genera una señal cuadrada con el módulo
* Input: Canal (0 o 1) y entero para la frecuencia
* Output: Ninguna
*
*****************************************************************************/
void Square_DAC(dac_channel_x channel,int frecuencia)
{
	int delay;

	switch(frecuencia)
	{
		case F_1Hz:
			delay = 500000;
		break;

		case F_5Hz:
			delay = 100000;
		break;

		case F_10Hz:
			delay = 50000;
		break;

		case F_100Hz:
			delay = 5000;
		break;

		default:
			delay = 50000;
	}

	Dac_out_voltage(channel, 255);
	usleep(delay);

	Dac_out_voltage(channel, 0);
	usleep(delay);
}
