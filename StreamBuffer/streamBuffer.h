#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define HARDWARE_SIZE 8
#define SOFTWARE_SIZE 512

void addToBuffer(uint8_t *addBuffer, uint8_t size, char rt);
void updateHardwareBuffer(char rt);
void resetSoftwareBuffer(char rt);
void printBuffer();

#ifndef STREAMBUFFER_H
        #define STREAMBUFFER_H

        volatile uint8_t hardwareRxBuffer[HARDWARE_SIZE];
        volatile uint8_t hardwareTxBuffer[HARDWARE_SIZE];

        volatile uint8_t softwareRxBuffer[SOFTWARE_SIZE];
        volatile uint8_t softwareRxBufferSize = 0;

        volatile uint8_t softwareTxBuffer[SOFTWARE_SIZE];
        volatile uint8_t softwareTxBufferSize = 0;
#endif