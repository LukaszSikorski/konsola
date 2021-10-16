#include "ADC.h"

Adc::Adc(){
    ADMUX = (1 << REFS1) | (1 << REFS0);
    ADCSRA = (1 << ADPS2) | (1 << ADPS1);
    ADCSRA |= (1 << ADEN);
}

uint16_t Adc::getSingle(uint8_t port){
    uint16_t result = 0;
    ADMUX = (ADMUX & 0xf8 ) | port;
    ADCSRA |= (1 << ADSC);
    while( (ADCSRA & (1 << ADSC)));
    result = ADCW;
    return result;
}