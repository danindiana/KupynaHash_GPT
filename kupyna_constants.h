#ifndef KUPYNA_CONSTANTS_H
#define KUPYNA_CONSTANTS_H

#include <stdint.h>

// Substitution table (S-Box) for Kupyna
static const uint8_t KUPYNA_SBOX[256] = {
    0xA7, 0x65, 0xA4, 0x5E, 0x6B, 0x45, 0x58, 0x03, 0xFA, 0x6D, 0x76, 0x4C, 0xD7, 0xCB, 0x44, 0xA3,
    // ... Fill in the rest based on the Kupyna specification
};

// Round constants for Kupyna
static const uint64_t KUPYNA_ROUND_CONSTANTS[10] = {
    0xF0D8, 0xE1C6, 0xD3B7, 0xC5A5, 0x9674, 0x7863, 0x6952, 0x5A40, 0x4C3F, 0x3E2D,
    // ... Fill in the rest based on the Kupyna specification
};

// Matrix for linear transformation (MDS matrix)
static const uint8_t KUPYNA_MDS_MATRIX[8][8] = {
    {0x01, 0x01, 0x05, 0x01, 0x08, 0x06, 0x07, 0x04},
    {0x04, 0x01, 0x01, 0x05, 0x01, 0x08, 0x06, 0x07},
    // ... Fill in the rest based on the Kupyna specification
};

#endif // KUPYNA_CONSTANTS_H
