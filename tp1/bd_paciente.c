#include "bd_paciente.h"
#include <stdio.h>
#include <string.h>

BDPaciente* bd_paciente_create(){
    BDPaciente* bdpaciente = (BDPaciente*)malloc(sizeof(BDPaciente));
    bd_paciente_carregar_csv(bdpaciente, "bd_paciente.csv");

}

int bd_paciente_carregar_csv(BDPaciente* bd, char* nome_arquivo){
    FILE* arquivo = fopen("bd_paciente.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        return -1;
    }

    char linha[512];
    // Pular o cabeçalho
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo)) {
        
        char id, cpf[14], nome[100], data_cadastro[11]; 
        int idade, quantidade;
        id = linha[0];
        
    }

    fclose(arquivo);
}

void bd_paciente_free(){

}