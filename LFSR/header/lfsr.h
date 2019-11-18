#ifndef LFSR_INC
#define LFSR_INC

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#define NUMBER_OF_CLASSES 64
#define SIZE_OF_INTERVAL 1024
#define SEED 0x1313
#define MASK 0x00FFFFFF

int classes[NUMBER_OF_CLASSES];
int lfsr_nums[65536];
double chi_value[NUMBER_OF_CLASSES];
double distChi = 0;

extern int lfsr_nasm ();

int lfsr();
int main(int argc, char *argv[]);
void frequenciaChiQuad();
void separadorClasses(int cont);

#endif
