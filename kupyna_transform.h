#ifndef KUPYNA_TRANSFORM_H
#define KUPYNA_TRANSFORM_H

#include <stdint.h>
#include <stddef.h>

void T_plus(uint64_t* state, size_t num_blocks);

void T_xor(uint64_t* state, size_t num_blocks);

void AddRoundConstants(uint64_t* state, size_t num_blocks, size_t round);

#endif // KUPYNA_TRANSFORM_H
