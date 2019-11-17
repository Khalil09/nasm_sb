#include "../header/lfsr.h"
#define NUMBER_OF_CLASSES 64
#define SIZE_OF_INTERVAL 1024
#define SEED 0x13131
#define MASK 0x00FFFFFF

int classes[NUMBER_OF_CLASSES];
double chi_value[NUMBER_OF_CLASSES];
double distChi = 0;

void separadorClasses(uint32_t random) {
    uint32_t temp = (random/SIZE_OF_INTERVAL);
    classes[temp]++;
}

void frequenciaChiQuad(){
    double aux =0;

    for (int i = 0;  i < NUMBER_OF_CLASSES; i++) {
    aux = (pow((classes[i]-SIZE_OF_INTERVAL),2))/SIZE_OF_INTERVAL;
    chi_value[i] = aux;

    distChi += chi_value[i];
    }
}

void lfsr(){
    unsigned long int cont = 0;
    uint32_t start_state = SEED;
    uint32_t lfsr = start_state;
    uint32_t bit;
    unsigned period = 0;

    while (cont != 65536) {
      bit  = ((lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 4) ^ (lfsr >> 13)) & 1;
      lfsr =  (lfsr >> 1) | (bit << 15);
      ++period;
      cont++;
      lfsr = lfsr & MASK;
      separadorClasses(lfsr);
    }

    printf("=======> Foi gerado %lu números <=======\n", cont);
}

int main(void){
    printf("%d\n", _test (85,5));
    memset(chi_value, 0, sizeof(chi_value));
    memset(classes, 0, sizeof(classes));
    lfsr();
    frequenciaChiQuad();
    for (int i = 0; i < NUMBER_OF_CLASSES; i++) {
    printf("\tclasse %d: valor chi é %lf com %d números\n",i,chi_value[i], classes[i]);
    }

    printf("\n======> Valor final do chi quadrado é %lf <========\n", distChi);

    return 0;
}
