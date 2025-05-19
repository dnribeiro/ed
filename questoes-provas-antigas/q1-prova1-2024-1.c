#include <stdio.h>
#define MAX 10

int busca(float M[MAX][MAX],int n_lin, int n_col, float v, int *lin, int *col){
    for (int i = 0; i < n_lin; i++){
        for (int j = 0; j < n_col; j++){
            if (M[i][j] == v){
                *lin = i;
                *col = j;
                return 1;
            }
        }
    }
    return 0;
}


int main(){
    int lin, col;
    float matriz[MAX][MAX] = {{1, 2, 1, 4}, 
                            {5, 15, 23, 23},
                            {9, -1, 4, 10}};
    if (busca(matriz, 3, 4, 23, &lin, &col)){
        printf("\nLinha %d e Coluna %d\n", lin, col);
    }
    return 0;
}