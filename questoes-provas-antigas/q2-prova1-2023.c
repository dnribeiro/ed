#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int m, n;
    printf("Linhas: ");
    scanf("%d", &m);
    printf("Colunas: ");
    scanf("%d", &n);

    // Inicializa a semente para números aleatórios
    srand(time(NULL));

    // alocação de memoria da matriz
    int **matriz = (int**) malloc(m * sizeof(int*));
    if (matriz == NULL){
        printf("Erro de alocação da matriz");
        return 1;
    }
    // alocação de memoria de cada linha da matriz
    for (int i = 0; i < m; i++){
        int *linha = (int*) malloc(n * sizeof(int));
        if (linha == NULL){
            printf("Erro de alocação na linha da matriz");
            return 1;
        }
        matriz[i] = linha;
    }
    // preenche a matriz
    // Preenche a matriz com números aleatórios de 0 a 99
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100;
        }
    }
    // printa a matriz
    // Imprime a matriz
    printf("\nMatriz gerada:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    // liberação de memoria de cada linha da matriz
    for (int i = 0; i < m; i++){
        free(matriz[i]);
    }
    // liberação de memoria da matriz
    free(matriz);
    return 0;
}