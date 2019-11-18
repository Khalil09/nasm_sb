#ifndef LFSR_INC
#define LFSR_INC

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define NUMBER_OF_CLASSES 16
#define SIZE_OF_INTERVAL 1048576
#define SEED 0x1313

int classes[NUMBER_OF_CLASSES];
uint32_t lfsr_nums[16777216];
double chi_value[NUMBER_OF_CLASSES];
double distChi = 0;

extern int lfsr_nasm (uint32_t *vec);

int lfsr();
int main(int argc, char *argv[]);
void frequenciaChiQuad();
void separadorClasses(int cont);

#endif
