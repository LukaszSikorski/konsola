#include <avr/io.h>
#include "Matrix.h"
#include "Spi.h"


class Display{
    public:
        void fill(Matrix &matrix);

    private:
        Spi spi = Spi();

};