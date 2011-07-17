#include <stdio.h>
#include "uart.h"

FILE uart_str = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW); // This line is used to set up file access

int main(void) {
	//Connect to uart
	uart_init();
	uart_str= FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);
	stdout = stdin = &uart_str;
	printf("Hello World!");
}
