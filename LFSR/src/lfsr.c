#include "../header/lfsr.h"

uint16_t shift_lsfr(uint16_t *lfsr, uint16_t mask){
    int feedback;

    feedback = *lfsr & 1;
    *lfsr >>= 1;
    if (feedback == 1) {
        *lfsr ^= mask;
    }
    return *lfsr;
}

void init_lfsrs() {
    lfsr32 = 0xABCDE;
    lfsr31 = 0x23456789;
}

uint16_t get_random() {
    shift_lsfr(&lfsr32, POLY_MASK_32);
    return (shift_lsfr(&lfsr32, POLY_MASK_32) ^ shift_lsfr(&lfsr31, POLY_MASK_31)) & 0xffff;
}

int main() {
    uint16_t random_value;
    init_lfsrs();
    random_value = get_random();
    printf("%d\n", random_value);
}
