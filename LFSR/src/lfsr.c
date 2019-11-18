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
    int cont = 0;
    uint32_t start_state = SEED;
    uint32_t lfsr = start_state;
    uint32_t bit;

    while (cont != 16777216) {
      bit  = ((lfsr >> 1) ^ (lfsr >> 5) ^ (lfsr >> 7) ^ (lfsr >> 13)) & 1;
      lfsr = (lfsr >> 1) | (bit << 23);
      lfsr_nums[cont] = lfsr;
      cont++;
    }

    return cont;
}

int main(int argc, char *argv[]){
    clock_t start, end;
    int cont;
    memset(chi_value, 0, sizeof(chi_value));
    memset(classes, 0, sizeof(classes));
    if(argc == 2) {
        start = clock();
        cont = lfsr_nasm(lfsr_nums);
        end = clock();
        printf("Dez primeiros numeros aleatorios: \n");
        for(int i = 0; i < 10; i++){
            printf("%d ", lfsr_nums[i]);
        }
    } else {
        start = clock();
        cont = lfsr();
        end = clock();
        printf("Dez primeiros numeros aleatorios: \n");
        for(int i = 0; i < 10; i++){
            printf("%d ", lfsr_nums[i]);
        }
    }
    separadorClasses(cont);
    printf("\n=======> Foram gerados %d números <=======\n", cont);
    frequenciaChiQuad();
    for (int i = 0; i < NUMBER_OF_CLASSES; i++) {
    printf("\tclasse %d: valor chi é %lf com %d números\n",i,chi_value[i], classes[i]);
}

    printf("\n======> Valor final do chi quadrado é %lf <========\n", distChi);

    printf("Tempo Usado %lf\n", ((double)(end - start)) / CLOCKS_PER_SEC );

    return 0;
}
