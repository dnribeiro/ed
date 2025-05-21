#include <stdio.h>
#include "dynvec.h"

int main(){
    DynVec *dv1 = dv_create();
    DynVec *dv2 = dv_create();
    DynVec *dv_uniao;
    DynVec *dv_intersecao;

    for (int i = 0; i < 10; i++){
        dv_insert(dv1, i);
    }
    for (int i = 5; i < 20; i++){
        dv_insert(dv2, i);
    }

    dv_uniao = dv_union(dv1, dv2);
    dv_intersecao = dv_intersection(dv1, dv2);

    printf("Dynamic Vector de União:\n");
    dv_print_values(dv_uniao);
    printf("\nDynamic Vector de Interseção\n");
    dv_print_values(dv_intersecao);

    dv_free(dv1);
    dv_free(dv2);
    dv_free(dv_uniao);
    dv_free(dv_intersecao);

    return 0;
}