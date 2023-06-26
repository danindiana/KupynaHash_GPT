#ifndef KUPYNA_UTILS_H
#define KUPYNA_UTILS_H

#include <stdint.h>
#include <stddef.h>

void SubBytes(uint8_t state[], size_t stateSize);

void ShiftRows(uint8_t state[], size_t stateSize);

void MixColumns(uint8_t state[], size_t stateSize);

#endif // KUPYNA_UTILS_H
