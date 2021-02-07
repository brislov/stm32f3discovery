#include "gyro.h"

const uint8_t WHO_AM_I = 0x0F;
const uint8_t CTRL_REG1 = 0x20;
const uint8_t CTRL_REG2 = 0x21;
const uint8_t OUT_TEMP = 0x26;

const uint8_t READ_ADDRESS = 0x80;
const uint8_t READ_AND_INCREMENT_ADDRESS = 0xC0;
const uint8_t WRITE_ADDRESS = 0x00;
const uint8_t WRITE_AND_INCREMENT_ADDRESS = 0x40;

const uint32_t TIMEOUT = 10;

SPI_HandleTypeDef hspi1;


void Read(uint8_t *txData, uint8_t *rxData, uint16_t rxSize)
{
  HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_RESET);

  HAL_SPI_Transmit(&hspi1, txData, 1, TIMEOUT);
  HAL_SPI_Receive(&hspi1, rxData, rxSize, TIMEOUT*rxSize);

  HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_SET);
}

void Write(uint8_t *txData, uint16_t txSize)
{
  HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_RESET);

  HAL_SPI_Transmit(&hspi1, txData, txSize, TIMEOUT);

  HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_SET);
}

void Gyro_Init()
{
  const uint8_t txData[3] = {
      WRITE_AND_INCREMENT_ADDRESS | CTRL_REG1,
      0x0F,
      0x00
  };

  Write((uint8_t*) &txData, 3);
}

uint8_t Gyro_GetId(SPI_HandleTypeDef *handle)
{
  uint8_t txData = READ_ADDRESS | WHO_AM_I;
  uint8_t rxData;

  Read(&txData, &rxData, 1);

  return rxData;
}

uint8_t Gyro_GetTemp()
{
  uint8_t txData = READ_ADDRESS | OUT_TEMP;
  uint8_t rxData;
  Read(&txData, &rxData, 1);

  return rxData;
}
