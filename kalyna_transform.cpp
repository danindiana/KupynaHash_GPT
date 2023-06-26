#include "kalyna_transform.h"
#include "kalyna_constants.h"

// Kalyna SubBytes transformation
void KalynaSubBytes(uint8_t state[], size_t stateSize) {
    for (size_t i = 0; i < stateSize; ++i) {
        size_t sbox_idx = i % 4; // Select one of the four S-boxes
        switch (sbox_idx) {
            case 0:
                state[i] = KALYNA_SBOX_0[state[i]];
                break;
            case 1:
                state[i] = KALYNA_SBOX_1[state[i]];
                break;
            case 2:
                state[i] = KALYNA_SBOX_2[state[i]];
                break;
            case 3:
                state[i] = KALYNA_SBOX_3[state[i]];
                break;
        }
    }
}

// Kalyna ShiftRows transformation
void KalynaShiftRows(uint8_t state[], size_t stateSize) {
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

// Kalyna MixColumns transformation
void KalynaMixColumns(uint8_t state[], size_t stateSize) {
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

// Kalyna AddRoundKey transformation
void KalynaAddRoundKey(uint8_t state[], uint8_t roundKey[], size_t stateSize) {
    for (size_t i = 0; i < stateSize; ++i) {
        state[i] ^= roundKey[i];
    }
}

// Kalyna Key Expansion
void KalynaKeyExpansion(const uint8_t key[], uint8_t roundKeys[][8], size_t keySize, size_t numRounds) {
    // ... Implement key expansion algorithm based on Kalyna specification
}
