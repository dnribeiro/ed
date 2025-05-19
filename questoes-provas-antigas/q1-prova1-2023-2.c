#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Quantas linhas e colunas a matriz deve ter?");
    scanf("%d", &n);
    // alocando memoria para matriz
    int **matriz = (int**) malloc(n * sizeof(int*));
    if (matriz == NULL){
        printf("Erro ao alocar a memoria da matriz");
        return 1;
    }
    // alocando memoria para cada linha
    for (int i = 0; i < n; i++){
        int *linha = (int*) malloc((i + 1) * sizeof(int));
        if (linha == NULL){
            printf("Erro ao alocar a memoria da linha %d", i + 1);
            return 1;
        }
        // preenchendo as linhas
        for (int j = 0; j < i + 1; j ++){
            linha[j] = 1;
        }
        // colocando a linha na matriz
        matriz[i] = linha;
    }
    
    // printa a matriz
    printf("\nMatriz gerada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    // liberando a memoria para cada linha
    for (int i = 0; i < n; i ++){
        free(matriz[i]);
    }
    // liberando a memoria da matriz
    free(matriz);
    return 0;
}