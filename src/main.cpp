#include <avr/io.h>
#include "avrGame/Controller/Controller.h"
#include "avrGame/avrGame.h"
#include <avr/interrupt.h>
#define LED_PORT D
#define LED_PIN 4

volatile int8_t X = 0;
volatile uint16_t TIMER = 0;

Controller controller = Controller();
Rect r = Rect(2, 2, 4, 1);
Rect r2 = Rect(2,2,7,1);

int main(void){
    TCCR0 |= (1<<CS01);
    TIMSK |= (1<<TOIE0);
    Matrix matrix = avrGame::matrix();
    sei();
    while(true){
        controller.run();
        avrGame::draw.rect(matrix,r, green);
        avrGame::draw.rect(matrix,r2, red);
        r.move(X,1);
        r2.move(1,X);
        // avrGame::draw.point(matrix, 1, X, red);
        avrGame::display.flip(matrix);

    }
}


ISR(TIMER0_OVF_vect){
    controller.updateTimers();
    TCNT0 = 159;
    TIMER--;
    if(!TIMER){
        X++;
        if (X < -1 || X > 10) X = 0;
        TIMER = 3000;
    }
}