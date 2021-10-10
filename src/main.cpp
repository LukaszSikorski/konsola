#include <avr/io.h>
#include "avrGame/Controller/Controller.h"
#include "avrGame/avrGame.h"
#include <avr/interrupt.h>
#define LED_PORT D
#define LED_PIN 4

volatile int8_t X = 0;
volatile uint16_t TIMER = 0;

Controller controller = Controller();
Rect r = Rect(2,2,0,2);

int main(void){
    TCCR0 |= (1<<CS01);
    TIMSK |= (1<<TOIE0);
    Matrix matrix = avrGame::matrix();
    sei();
    while(true){
        controller.run();
        avrGame::draw.rect(matrix,r, blue);
        avrGame::draw.point(matrix, 5, 4, blue);
        r.move(X,1);
        avrGame::display.flip(matrix);

    }
}


ISR(TIMER0_OVF_vect){
    controller.updateTimers();
    TCNT0 = 159;
    TIMER--;
    if(!TIMER){
        X--;
        if (X < 0 || X > 7) X = 7;
        TIMER = 1000;
    }
}