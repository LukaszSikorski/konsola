#include <avr/io.h>
#include "Matrix.h"
#include "Colors.h"
#include "Figures.h"

class Draw{
    public:
     void rect(Matrix &,Colors color, Rect &);
};