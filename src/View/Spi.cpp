#include <avr/io.h>
#include "Spi.h"


Spi::Spi(){
    DDRB = ( 1 << PB2 ) | ( 1 << PB3 ) | ( 1 << PB5 );
    SPCR = ( 1 << SPE ) | ( 1 << MSTR ) | ( 1 << SPR1 ) | ( 1 << SPR0 );
}

void Spi::sendByte(uint8_t data){
    SPDR = data;
    while ( ! (SPSR & (1 << SPIF)));
}

void Spi::sendBytes(uint8_t data1, uint8_t data2, uint8_t data3, uint8_t data4){
    sendByte(data1);
    sendByte(data2);
    sendByte(data3);
    sendByte(data4);
    SetSS;
    ClrSS;
}