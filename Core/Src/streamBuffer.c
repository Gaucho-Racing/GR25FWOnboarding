#include <stdint.h>
#include <string.h>
#include "streamBuffer.h"

volatile uint8_t hardwareRxBuffer[HARDWARE_SIZE];
volatile uint8_t hardwareTxBuffer[HARDWARE_SIZE];

volatile uint8_t softwareRxBuffer[SOFTWARE_SIZE];
volatile uint8_t softwareRxBufferSize = 0;

volatile uint8_t softwareTxBuffer[SOFTWARE_SIZE];
volatile uint8_t softwareTxBufferSize = 0;

/**
  * @brief Write to either rx or tx buffer depending on rt
  * @retval None
  */
void addToBuffer(uint8_t *addBuffer, uint8_t size, char rt)
{
        if (rt == 'r') {
                while (size + softwareRxBufferSize >= SOFTWARE_SIZE);

                memcpy(&softwareRxBuffer[softwareRxBufferSize], addBuffer, size);
                softwareRxBufferSize += size;
        } else if (rt == 't') {
                while (size + softwareTxBufferSize >= SOFTWARE_SIZE);

                memcpy(&softwareTxBuffer[softwareTxBufferSize], addBuffer, size);
                softwareTxBufferSize += size;
        }
}

void updateHardwareBuffer(char rt)
{
        if (rt == 'r') {
                memcpy(hardwareRxBuffer, softwareRxBuffer, HARDWARE_SIZE - 1);

                for (int i = 0; i < HARDWARE_SIZE; i++) {
                        softwareRxBuffer[i] = softwareRxBuffer[HARDWARE_SIZE + i];
                }

                softwareRxBufferSize -= HARDWARE_SIZE;
        } else if (rt == 't') {
                memcpy(hardwareTxBuffer, softwareTxBuffer, HARDWARE_SIZE - 1);

                for (int i = 0; i < HARDWARE_SIZE; i++) {
                        softwareTxBuffer[i] = softwareTxBuffer[HARDWARE_SIZE + i];
                }
                softwareTxBufferSize -= HARDWARE_SIZE;
        }
}