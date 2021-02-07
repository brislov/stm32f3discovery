#include "main.h"

#include "stm32f3xx_hal.h"

#include <stdbool.h>
#include <stdint.h>

void Gyro_Init();

uint8_t Gyro_GetId();
uint8_t Gyro_GetTemp();
