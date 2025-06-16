#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// verifica se um caractere é de abertura
int is_opening(char c) {
    return (c == '(' || c == '[' || c == '{');
}

// verifica se um caractere é de fechamento
int is_closing(char c) {
    return (c == ')' || c == ']' || c == '}');
}

// verifica se os caracteres de abertura e fechamento fazem par
int is_matching(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '[' && closing == ']') ||
            (opening == '{' && closing == '}'));
}

// verifica se os delimitadores estão balanceados (abriu, fechou)
int check_balanced(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro: Não foi possível abrir o arquivo %s\n", filename);
        return 0;
    }
    
    Stack *stack = s_create();
    char c;
    int balanced = 1; // incialmente o arquivo ta aberto e fechado certo
    
    // lê o arquivo caractere por caractere
    while ((c = fgetc(file)) != EOF && balanced) {
        if (is_opening(c)) { // se é um caractere de abertura, empilha
            s_push(stack, (float)c);
        } else if (is_closing(c)) { // se é um caractere de fechamento
            if (s_is_empty(stack)) { // pilha vazia mas encontrou um fechamento = não balanceado
                balanced = 0;
            } else {
                // Verifica se o topo da pilha combina com o fechamento
                char opening = (char)s_pop(stack);
                if (!is_matching(opening, c)) {
                    balanced = 0;
                }
            }
        }
    }
    
    // Verifica se ainda há caracteres de abertura não fechados
    if (balanced && !s_is_empty(stack)) {
        balanced = 0;
    }
    
    fclose(file);
    s_free(stack);
    
    return balanced;
}

int main() {
    char filename[256];

    printf("Digite o nome do arquivo: ");
    scanf("%255s", filename);
    
    if (check_balanced(filename)) {
        printf("success\n");
    } else {
        printf("fail\n");
    }
    
    return 0;
}