#ifndef LFSR_INC
#define LFSR_INC

#include <stdio.h>
#include <stdint.h>

#define POLY_MASK_32 0xB4BCD35C
#define POLY_MASK_31 0x7A5BC2E3

typedef unsigned int uint;

uint16_t lfsr32, lfsr31;

uint16_t get_random();
void init_lfsrs();
uint16_t shift_lsfr(uint16_t *lfsr, uint16_t mask);

#endif
