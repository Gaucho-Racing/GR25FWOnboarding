#include "streamBuffer.h"

int main()
{
    addToBuffer("testingthisout!", 16, 'r');
    printBuffer();
 
    updateHardwareBuffer('r');
    printBuffer();

    addToBuffer("idonotknowhowtospellanything", 28, 't');
    printBuffer();
    
    updateHardwareBuffer('t');
    printBuffer();

    resetSoftwareBuffer('r');
    printBuffer();

    updateHardwareBuffer('t');
    printBuffer();

    updateHardwareBuffer('t');
    printBuffer();

    updateHardwareBuffer('t');
    printBuffer();

     updateHardwareBuffer('t');
     printBuffer();

     printf("%f", softwareRxBufferSize);
}