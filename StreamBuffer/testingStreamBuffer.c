#include "streamBuffer.h"

int main()
{
    addToBuffer("testingthisout!", 17, 'r');
    printBuffer();

    printf("\n");
 
    updateHardwareBuffer('r');
    printBuffer();
}

