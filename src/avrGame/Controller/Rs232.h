#ifndef _RS232_H
#define _RS232_H
#include <avr/io.h>

#define UART_BAUD 9600
#define __UBRR ((F_CPU + UART_BAUD * 8UL) / ( 16UL * UART_BAUD) - 1)


class Rs232{
    public:

        Rs232(uint16_t baud);
        void sendChar(const char c) const;
        void sendStr(const char *)const ;
        void sendInt(int16_t value)const;
        void sendNumber(int16_t value, uint8_t base)const;
};


#endif /* _RS232_H */