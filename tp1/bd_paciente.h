#include "paciente.h"

#ifndef BD_PACIENTE
#define BD_PACIENTE

typedef struct {
    Paciente** pacientes;  // Vetor de ponteiros para Paciente
    int quantidade;        // Quantidade atual de pacientes
} BDPaciente;

BDPaciente* bd_paciente_create();

void bd_paciente_free(BDPaciente* bd);

int bd_paciente_carregar_csv(BDPaciente* bd, char* nome_arquivo);

void bd_paciente_listar_todos(BDPaciente* bd);

void bd_paciente_consultar_por_nome(BDPaciente* bd, char* prefixo_nome);

void bd_paciente_consultar_por_cpf(BDPaciente* bd, char* prefixo_cpf);

#endif