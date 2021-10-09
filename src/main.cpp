#include <avr/io.h>
#include "avrGame/Controller/Controller.h"
#include "avrGame/avrGame.h"
#include <avr/interrupt.h>
#define LED_PORT D
#define LED_PIN 4


Controller controller = Controller();

int main(void){
    TCCR0 |= (1<<CS01);
    TIMSK |= (1<<TOIE0);
    Matrix matrix = avrGame::matrix();

    sei();
    while(true){
        controller.run();
        avrGame::draw.point(matrix, red,0,0);
        avrGame::display.fill(matrix);

    }
}


ISR(TIMER0_OVF_vect){
    controller.updateTimers();
    TCNT0 = 159;
}