#include <avr/io.h>
#include <avr/interrupt.h>
#include "avrGame/avrGame.h"
#define LED_PORT D
#define LED_PIN 4

volatile uint16_t TIMER = 100;
volatile uint16_t TIMER_DRAW = 100;

Controller *controller = &avrGame::controller;

Matrix *matrix = &avrGame::_matrix;
int main(void){
    DDRD |= (1<<PD4);
    TCCR0 |= (1<<CS01);
    TIMSK |= (1<<TOIE0);
    sei();
    while(true){
        controller->capture();
        avrGame::display.fill(matrix);

    }
}


ISR(TIMER0_OVF_vect){
    controller->updateTimers();
    TCNT0 = 159;
    if(TIMER) TIMER--;
    if(TIMER_DRAW) TIMER_DRAW--;
}