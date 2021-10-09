#include <avr/io.h>
#include "avrGame/Controller/Controller.h"
#include "avrGame/avrGame.h"
#include <avr/interrupt.h>
#define LED_PORT D
#define LED_PIN 4



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
        avrGame::display.fill(matrix);
        r.move(controller.listener.x,controller.listener.y);

    }
}


ISR(TIMER0_OVF_vect){
    controller.updateTimers();
    TCNT0 = 159;
}