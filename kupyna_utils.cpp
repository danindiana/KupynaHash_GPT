#include "kupyna_utils.h"
#include "kupyna_constants.h"

// SubBytes replaces each byte in the state with the corresponding byte from the S-Box
void SubBytes(uint8_t state[], size_t stateSize) {
    for (size_t i = 0; i < stateSize; ++i) {
        state[i] = KUPYNA_SBOX[state[i]];
    }
}

// ShiftRows circularly shifts the bytes in each row of the state
void ShiftRows(uint8_t state[], size_t stateSize) {
    // Assuming stateSize is a square matrix dimension (e.g., 64 for an 8x8 matrix)
    size_t n = (size_t) sqrt(stateSize);

    for (size_t row = 1; row < n; ++row) {
        uint8_t tempRow[n];
        for (size_t col = 0; col < n; ++col) {
            tempRow[col] = state[row * n + (col + row) % n];
        }
        for (size_t col = 0; col < n; ++col) {
            state[row * n + col] = tempRow[col];
        }
    }
}

// MixColumns mixes the columns of the state using the MDS matrix
void MixColumns(uint8_t state[], size_t stateSize) {
    // Assuming stateSize is a square matrix dimension (e.g., 64 for an 8x8 matrix)
    size_t n = (size_t) sqrt(stateSize);

    uint8_t tempState[stateSize];

    // Matrix multiplication
    for (size_t row = 0; row < n; ++row) {
        for (size_t col = 0; col < n; ++col) {
            uint8_t sum = 0;
            for (size_t k = 0; k < n; ++k) {
                // Multiplication and addition in GF(2^8) go here
                // ...
            }
            tempState[row * n + col] = sum;
        }
    }

    // Copy tempState into state
    for (size_t i = 0; i < stateSize; ++i) {
        state[i] = tempState[i];
    }
}
