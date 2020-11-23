/*************************/
/*      This is the
/*      dl-ln3x module
/*        test file
/*
/**************************/
#include "uart.h"


int main(int argc, char **argv)
{
        usart_t uart;
        u_int8_t buf[MAX_BUFFER];
        const u_int8_t cmd[] = {0xfe, 0x05, 0x91, 0x21, 0x00, 0x00, 0x01, 0xff};
        open_uart (&uart, "/dev/ttyUSB0", RW_MODE);
        set_usart (&uart, CS8, HS_NONE, PA_NONE, B115200, 8, 1, 1);
        
        while (1)
        {
                memset (buf, 0, sizeof (buf));
                read_serial_hex (&uart, buf, 0xFF);
                show_serial_data_hex (buf, check_DLLN3x_data_len (buf));
                sleep (5);
                write_serial_hex (&uart, cmd, sizeof (cmd));
        }

        return 0;
}
