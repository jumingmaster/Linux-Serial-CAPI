/****************************
 *     author: Chienheng
 *      data :  2020/11/20 
*****************************/
#ifndef __UART__H__
#define __UART__H__
#include "usart_property.h"

void open_uart (usart_t *uart, const char *dev,int flag);

void set_usart 
(
        usart_t * usart, u_int8_t databit, u_int8_t hs_ctl,
        u_int8_t parity, speed_t budrate, u_int8_t stop_bit, 
        u_int8_t vmin, u_int8_t vtime);

void read_serial_char (usart_t *com, char * buf, char end);

void read_serial_hex (usart_t *com, u_int8_t * buf, u_int8_t end);

void write_serial_char (usart_t *com, const char * buf, u_int32_t len);

void write_serial_hex (usart_t *com, const u_int8_t * buf, u_int32_t len);

void show_serial_data (const char * buf, u_int32_t len);

void show_serial_data_hex (const u_int8_t * buf, u_int32_t len);


/*your interface*/
int check_DLLN3x_data_len (const u_int8_t *buf);

#endif  //!__UART__H__