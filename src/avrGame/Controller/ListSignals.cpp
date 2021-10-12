#include "ListSignals.h"

ListSignals::ListSignals() {
    this->head = 0;
    this->tail = 0;
}

void ListSignals::appendValue(uint8_t value){
    this->table[this->head] = value;
    if (this->head >= SIZE_BUFFOR) this->head = 0;
    else this->head++;
}

uint8_t ListSignals::getValue(){
    uint8_t result = 0;
    if (this->head == this->tail) return result;
    if (this->head != this->tail) {
        result = this->table[this->tail];
        this->table[this->tail] = 0;
    }
    if (this->tail >= SIZE_BUFFOR) this->tail = 0;
    else this->tail++;
    return result;
}