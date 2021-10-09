#include <avr/io.h>
#include "Controller/Controller.h"
#include "View/Display.h"
#include <avr/interrupt.h>
#define LED_PORT D
#define LED_PIN 4

Controller controller = Controller();
Display display = Display();

int main(void){
    TCCR0 |= (1<<CS01);
    TIMSK |= (1<<TOIE0);
    Matrix matrix = Matrix();
    // display.drawPoint(matrix, red, 0,0);
    // display.drawPoint(matrix, red, 0,1);
    // display.drawPoint(matrix, blue, 2,1);
    display.drawPoint(matrix, green, 7,7);
    sei();
    while(true){
        display.fill(matrix);
        controller.run();

        // spi.sendBytes(a,15,255,255);
    }
}


ISR(TIMER0_OVF_vect){
    controller.updateTimers();
    TCNT0 = 159;
}