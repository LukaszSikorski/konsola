#include <avr/io.h>
#include "Matrix.h"
#include "Spi.h"


class Display{
    public:
        void fill(Matrix &matrix);
        void draw(Matrix &matrix);
        void drawPoint(Matrix &matrix, Colors color, uint8_t x, uint8_t y);
        uint8_t getColumns();
        uint8_t getRed(Matrix &matrix);
        uint8_t getGreen(Matrix &matrix);
        uint8_t getBlue(Matrix &matrix);

    private:
        Spi spi = Spi();
        uint8_t colums:4;

};