#include <avr/io.h>
#include "Spi.h"
#include "headers.h"
#include "Button.h"
#include "Listener.h"
#define LED_PORT D
#define LED_PIN 4

int main(void){
    Spi spi = Spi();
    uint8_t a = 15;
    Listener listener = Listener();
    Button la = Button(&DDRD, 6);
    Button lb = Button(&DDRD, 7);
    Button lc = Button(&DDRB, 0);
    while(true){
        
        if ( la.isPush() ){
            listener.update(1);
        }
        if ( lb.isPush() ){
            listener.update(2);
        }
        if ( lc.isPush() ){
            listener.update(3);
        }
        listener.handleSignals();

        a ^= 15;
        // spi.sendBytes(a,15,255,255);
    }
}