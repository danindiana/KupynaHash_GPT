#include "kupyna_transform.h"
#include "kupyna_utils.h"
#include "kupyna_constants.h"

// Permutation T+
void T_plus(uint64_t* state, size_t num_blocks) {
    // For each block
    for (size_t i = 0; i < num_blocks; ++i) {
        uint64_t tmp = 0;
        // For each word in the block
        for (size_t j = 0; j < 8; ++j) {
            tmp += state[i * 8 + j];
        }
        // Write the resulting word into the state
        state[i * 8 + 7] = tmp;
    }
}

// Permutation T^
void T_xor(uint64_t* state, size_t num_blocks) {
    // For each block
    for (size_t i = 0; i < num_blocks; ++i) {
        uint64_t tmp = state[i * 8];
        // For each word in the block
        for (size_t j = 1; j < 8; ++j) {
            tmp ^= state[i * 8 + j];
        }
        // Write the resulting word into the state
        state[i * 8] = tmp;
    }
}

// AddRoundConstants adds round constants to the state
void AddRoundConstants(uint64_t* state, size_t num_blocks, size_t round) {
    for (size_t i = 0; i < num_blocks; ++i) {
        state[i * 8] ^= KUPYNA_ROUND_CONSTANTS[round] ^ (i * 0x10);
    }
}
