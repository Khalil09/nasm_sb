#include "../header/lfsr.h"

void separadorClasses(int cont) {
    for(int i=0;i<cont;i++){
        uint32_t temp = (lfsr_nums[i]/SIZE_OF_INTERVAL);
        classes[temp]++;
    }
}

void frequenciaChiQuad(){
    double aux =0;

    for (int i = 0;  i < NUMBER_OF_CLASSES; i++) {
    aux = (pow((classes[i]-SIZE_OF_INTERVAL),2))/SIZE_OF_INTERVAL;
    chi_value[i] = aux;

    distChi += chi_value[i];
    }
}

int lfsr(){
    unsigned long int cont = 0;
    uint32_t start_state = SEED;
    uint32_t lfsr = start_state;
    uint32_t bit;

    while (cont != 65536) {
      bit  = ((lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 4) ^ (lfsr >> 13)) & 1;
      lfsr =  (lfsr >> 1) | (bit << 15);
      lfsr = lfsr & MASK;
      lfsr_nums[cont] = lfsr;
      cont++;
    }

    return cont;
}

int main(void){
    printf("%d\n", _test (85,5));
    memset(chi_value, 0, sizeof(chi_value));
    memset(classes, 0, sizeof(classes));
    int cont = lfsr();
    separadorClasses(cont);
    printf("=======> Foi gerado %lu números <=======\n", cont);
    frequenciaChiQuad();
    for (int i = 0; i < NUMBER_OF_CLASSES; i++) {
    printf("\tclasse %d: valor chi é %lf com %d números\n",i,chi_value[i], classes[i]);
    }

    printf("\n======> Valor final do chi quadrado é %lf <========\n", distChi);

    return 0;
}
