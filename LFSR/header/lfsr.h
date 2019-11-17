#ifndef LFSR_INC
#define LFSR_INC

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#define NUMBER_OF_CLASSES 64
#define SIZE_OF_INTERVAL 1024
#define SEED 0x13131
#define MASK 0x00FFFFFF

int classes[NUMBER_OF_CLASSES];
int lfsr_nums[65536];
double chi_value[NUMBER_OF_CLASSES];
double distChi = 0;

// extern unsigned int _test (unsigned int, unsigned int);

int lfsr();
int main(void);
void frequenciaChiQuad();
void separadorClasses(int cont);

#endif
