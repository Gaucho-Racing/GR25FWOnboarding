#include "streamBuffer.h"

int main()
{
    addToBuffer("testingthisout!", 17, 'r');
    printBuffer();
 
    updateHardwareBuffer('r');
    printBuffer();

    addToBuffer("iddonotknowhowtospellanything", 30, 't');
    updateHardwareBuffer('t');
    printBuffer();

    resetSoftwareBuffer('r');
    printBuffer();
}

