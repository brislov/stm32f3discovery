#include "main.h"

#include "stm32f3xx_hal.h"

#include <stdbool.h>
#include <stdint.h>


void Gyro_Init();
void Gyro_Read(uint8_t* txData, uint8_t* rxData, uint16_t rxSize);
void Gyro_Write(uint8_t* txData, uint16_t txSize);

int16_t Gyro_GetAngularData();
uint8_t Gyro_GetId();
uint8_t Gyro_GetTemp();
