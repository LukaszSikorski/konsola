#include <avr/io.h>
#include "Spi.h"
#include "Controller/Listener.h"
#include <avr/interrupt.h>
#define LED_PORT D
#define LED_PIN 4

int main(void){
    TCCR0 |= (1<<CS02) | (1<<CS00);
    TIMSK |= (1<<TOIE0);
    sei();
    Spi spi = Spi();
    uint8_t a = 15;
    Listener listener = Listener();
    while(true){
        
        listener.update();
        listener.handleSignals();

        a ^= 15;
        // spi.sendBytes(a,15,255,255);
    }
}


ISR(TIMER0_OVF_vect){

}