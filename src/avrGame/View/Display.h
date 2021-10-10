#include <avr/io.h>
#include "Spi.h"
#include "Matrix.h"

class Display{
    public:
        void flip(Matrix &matrix);

    private:
        uint8_t getColumns();
        uint8_t getRed(Matrix &matrix);
        uint8_t getGreen(Matrix &matrix);
        uint8_t getBlue(Matrix &matrix);

        Spi spi = Spi();
        uint8_t colums:4;

};  
