#include <avr/io.h>
#include "Controller/Listener.h"
#include "View/Display.h"
#include <avr/interrupt.h>
#define LED_PORT D
#define LED_PIN 4

Listener listener = Listener();
Display display = Display();

int main(void){
    TCCR0 |= (1<<CS01);
    TIMSK |= (1<<TOIE0);
    Matrix matrix = Matrix();
    sei();
    while(true){
        display.fill(matrix);
        listener.update();
        listener.handleSignals();

        // spi.sendBytes(a,15,255,255);
    }
}


ISR(TIMER0_OVF_vect){
    listener.updateTimers();
    TCNT0 = 159;
}