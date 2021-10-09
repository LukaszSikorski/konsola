#include <avr/io.h>
#include "View/Draw.h"
#include "View/Display.h"
#include "View/Figures.h"

class avrGame{
    public:
        static Draw draw;
        static Display display;
        static Matrix matrix(void);
};
