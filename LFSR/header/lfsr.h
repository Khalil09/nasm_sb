#ifndef LFSR_INC
#define LFSR_INC

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

extern unsigned int _test (unsigned int, unsigned int);

void inicializaClasses();
void inicializaChiQuad();
void calcFreq();
void separaClasses(uint32_t);
void lfsr();

#endif
