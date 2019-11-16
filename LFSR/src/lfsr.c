#include <stdint.h>
#include <stdio.h>
#include <math.h>
#define NN 256
#define SEED 0x8016
#define MASK 0x00FFFFFF

//vetor de classes
int classes[NN];
double chiQuad[NN];
double distChi = 0;

//declarações de funções
void inicializaClasses();
void inicializaChiQuad();
void calcFreq();
void separaClasses(uint32_t);
void lfsr();

//corpo das funções
void inicializaClasses(){
  for (int i = 0;  i < NN; i++) {
    classes[i] = 0;
  }
}

void inicializaChiQuad() {
  for (int i = 0;  i < NN; i++) {
    chiQuad[i] = 0;
  }
 }

void separaClasses(uint32_t a) {
  uint32_t aux = (a/NN);
  classes[aux]++;
}

void calcFreq(){
  double aux =0;

  for (int i = 0;  i < NN; i++) {
    aux = (pow((classes[i]-NN),2))/NN;
    chiQuad[i] = aux;

    distChi += chiQuad[i];
  }
}
/*
função que gera os números pseudo aleatórios adaptada de:
https://en.wikipedia.org/wiki/Linear-feedback_shift_register
*/
void lfsr(){
  uint32_t start_state = SEED;  /* Any nonzero start state will work. */
  uint32_t lfsr = start_state;
  uint32_t bit;                    /* Must be 16bit to allow bit<<15 later in the code */
  unsigned period = 0;
  unsigned long int contador = 0;

  do
  {
      /* taps: 16 14 13 11; feedback polynomial: x^16 + x^14 + x^13 + x^11 + 1 */
      bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ^ (lfsr >> 7)  ^ (lfsr >> 13) ^ (lfsr >> 17)) & 1;
      lfsr =  (lfsr >> 1) | (bit << 15);
      ++period;
      contador++;
      lfsr = lfsr & MASK;
      separaClasses(lfsr);
  } while (/*lfsr != start_state && */contador != (NN*NN-1));

  printf("\n\n\t gerou %lu números\n",contador);



}

int main(void){
  inicializaChiQuad();
  inicializaClasses();
  lfsr();
  calcFreq();
  for (int i = 0; i < NN; i++) {
    printf("classe %d tem %d elementos e o valor chi da classe %d é %lf\n",i,classes[i],i,chiQuad[i]);
  }

  printf("\tvalor chi quadrado é %lf\n", distChi);

  getchar();
  return 0;
}