#define SetSS PORTB |= (1<<PB2)
#define ClrSS PORTB &= ~(1<<PB2)


class Spi{
    public:
        Spi();
        void sendByte(uint8_t bajt);
        void sendBytes(uint8_t data1, uint8_t data2, uint8_t data3, uint8_t data4);
};