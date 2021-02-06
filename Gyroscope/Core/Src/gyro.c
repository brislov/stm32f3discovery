#include "gyro.h"

SPI_HandleTypeDef hspi1;

uint8_t GyroGetId(SPI_HandleTypeDef *handle)
{
  const uint8_t WHO_AM_I = 0x0F;

  uint8_t txData = 0x80 | WHO_AM_I;
  uint8_t rxData;

  HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_RESET);

  HAL_SPI_Transmit(&hspi1, &txData, 1, 10);
  HAL_SPI_Receive(&hspi1, &rxData, 1, 10);

  HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_SET);

  return rxData;
}
