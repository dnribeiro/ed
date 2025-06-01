#ifndef PACIENTE
#define PACIENTE

typedef struct {
    int id;
    char cpf[14];        // "123.456.789-09"
    char nome[100];
    int idade;
    char data_cadastro[11]; // "YYYY-MM-DD"
} Paciente;

Paciente* paciente_create(int id, char* cpf, char* nome, int idade, char* data_cadastro);

void paciente_free(Paciente* paciente);

void paciente_print(Paciente* paciente);

char* paciente_get_nome(Paciente* paciente);

char* paciente_get_cpf(Paciente* paciente);

char* paciente_get_idade(Paciente* paciente);

char* paciente_get_data_cadastro(Paciente* paciente);

#endif