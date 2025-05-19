#include <stdio.h>

int* aloca_vetor(int n){
    int *vetor_dinamico = (int*) malloc(n * sizeof(int));
    if (vetor_dinamico == NULL) printf("Erro ao alocar memória");
    return vetor_dinamico;
}

int main(){

    return 0;
}