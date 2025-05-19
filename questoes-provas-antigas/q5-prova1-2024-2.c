#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void lineariza(int **M, int linhas, int colunas, int *vetor){
    int k = 0;
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            vetor[k] = M[i][j];
            k++;
        }
    }
}

int main(){
    int linhas, colunas;
    printf("Digite o número de linhas da matriz:");
    scanf("%d", &linhas);
    printf("\nDigite o número de colunas da matriz:");
    scanf("%d", &colunas);

    int **matriz = (int**) malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++){
        int *linha = (int*) malloc(colunas * sizeof(int));
        for (int j = 0; j < colunas; j++){
            int n;
            printf("\nDigite o elemento da coluna %d da linha %d: ", j, i);
            scanf("%d", &n);
            linha[j] = n;
        }
        matriz[i] = linha;
    }
    int vetor[linhas*colunas];
    lineariza(matriz, linhas, colunas, vetor);
    printf("\n");
    for (int i = 0; i < (sizeof(vetor) / sizeof(vetor[0])); i++){
        printf("%d ", vetor[i]);
    }

    for (int i = 0; i < linhas; i ++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}