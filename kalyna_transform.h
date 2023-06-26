#ifndef KALYNA_TRANSFORM_H
#define KALYNA_TRANSFORM_H

#include <stdint.h>
#include <stddef.h>

void KalynaSubBytes(uint8_t state[], size_t stateSize);

void KalynaShiftRows(uint8_t state[], size_t stateSize);

void KalynaMixColumns(uint8_t state[], size_t stateSize);

void KalynaAddRoundKey(uint8_t state[], uint8_t roundKey[], size_t stateSize);

void KalynaKeyExpansion(const uint8_t key[], uint8_t roundKeys[][8], size_t keySize, size_t numRounds);

#endif // KALYNA_TRANSFORM_H
