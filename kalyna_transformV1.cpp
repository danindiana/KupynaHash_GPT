#include "kalyna_transform.h"
#include "kalyna_constants.h"

// ... other functions ...

// This function performs multiplication in GF(2^8) used in key expansion
static uint8_t GaloisMultiply(uint8_t a, uint8_t b) {
    uint8_t p = 0;
    while (b) {
        if (b & 1) p ^= a;
        if (a & 0x80) a = (a << 1) ^ 0x011d; // modulo with the irreducible polynomial
        else a <<= 1;
        b >>= 1;
    }
    return p;
}

static void XorRoundKey(uint8_t state[], uint8_t roundKey[], size_t stateSize) {
    for (size_t i = 0; i < stateSize; ++i) {
        state[i] ^= roundKey[i];
    }
}

void KalynaKeyExpansion(const uint8_t key[], uint8_t roundKeys[][8], size_t keySize, size_t block_size, size_t numRounds) {
    if (keySize != 16 && keySize != 32 && keySize != 64) {
        return; // Invalid key size
    }

    uint8_t kt[block_size];
    uint8_t temp[block_size];

    // Initialize the intermediate key (Kt) with the key
    for (size_t i = 0; i < keySize; ++i) {
        kt[i] = key[i];
    }

    // First part of the expansion: expand intermediate key (Kt)
    XorRoundKey(kt, KALYNA_MDS_MATRIX[0], block_size); // Perform Kt = Kt (+) round_constant;
    KalynaSubBytes(kt, block_size);
    KalynaShiftRows(kt, block_size);
    KalynaMixColumns(kt, block_size);
    XorRoundKey(kt, key, block_size); // Perform Kt = Kt (+) key;

    // Second part of the expansion: generate round keys
    for (size_t i = 0; i < numRounds + 1; ++i) {
        // Generate the round key for round i
        for (size_t j = 0; j < block_size; ++j) {
            temp[j] = kt[j];
        }
        XorRoundKey(temp, KALYNA_MDS_MATRIX[i % 8], block_size); // Perform temp = temp (+) round_constant_i;
        KalynaSubBytes(temp, block_size);
        KalynaShiftRows(temp, block_size);
        KalynaMixColumns(temp, block_size);
        XorRoundKey(temp, kt, block_size); // Perform temp = temp (+) kt;

        // Store the round key
        for (size_t j = 0; j < block_size; ++j) {
            roundKeys[i][j] = temp[j];
        }
    }
}

// ... other functions ...
