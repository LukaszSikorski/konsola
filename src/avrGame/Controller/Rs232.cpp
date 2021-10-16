#include "Rs232.h"
#include <stdlib.h>

Rs232::Rs232(uint16_t baud){
    UBRRH = (uint8_t)( baud >> 8 );
    UBRRL = (uint8_t)( baud);
    UCSRB = (1<<RXEN) | (1<<TXEN);
    UCSRC = (1<<URSEL) | (3 << UCSZ0);
}

void Rs232::sendChar(const char c) const{
    while( !(UCSRA & (1<<UDRE)));
    UDR = c;
}

void Rs232::sendStr(const char *ptr) const{
    char tmp = *ptr;
    while(tmp){
        sendChar(tmp);
        ptr++;
        tmp = *ptr;
    }
}

void Rs232::sendInt(int16_t value) const {
    sendNumber(value, 10);
}

void Rs232::sendNumber(int16_t value, uint8_t base)const{
    char buffer[20];
    itoa(value, buffer, base);
    sendStr(buffer);

}