#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define TAM 50

typedef struct data{
    int dia;
    int mes;
    int ano;
}TData;

typedef struct endereco{
    char logradouro[TAM];
    char bairro[TAM];
    char cidade[TAM];
    char cep[TAM];
    int numero;
}TEndereco;

typedef struct cliente{
    char nome[TAM];
    char id[TAM];//CPF ou CNPJ
    int tipo;//0:Física, 1: Jurídica
    char identidade[TAM];
    TEndereco endereco_completo;
    TData data_de_nascimento;
} TCliente;

typedef struct moduloCliente{
    TCliente vetor[TAM];
    int indice;
}TModuloCliente;

void LerCliente(TCliente *cliente1);
void ImprimirCliente(TCliente cliente1);
void IniciarModuloCliente(TModuloCliente *modulo);
void InserirCliente(TModuloCliente *modulo,TCliente cliente);
int PesquisarCliente(TModuloCliente modulo,TCliente cliente);
void ImprimirTodosClientes(TModuloCliente modulo);
void AlterarCliente(TModuloCliente *modulo,TCliente cliente1);
void ExcluirCliente(TModuloCliente *modulo,TCliente cliente1);


#endif // CLIENTE_H_INCLUDED
