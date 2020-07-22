#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

void LerCliente(TCliente *cliente1){
    printf("\nDigite o nome do cliente: ");
    fflush(stdin);
    fgets(cliente1->nome,TAM,stdin);
    printf("\nDigite o Tipo do Cliente(0 para pessoa fisica,1 para juridica): ");
    fflush(stdin);
    scanf("%d",&cliente1->tipo);
    if(cliente1->tipo==0){
        printf("\nDigite o CPF do cliente: ");
        fflush(stdin);
        fgets(cliente1->id,TAM,stdin);
    }else{
        printf("\nDigite o CNPJ do cliente: ");
        fflush(stdin);
        fgets(cliente1->id,TAM,stdin);
    }
    printf("\nDigite a Identidade do Cliente: ");
    fflush(stdin);
    fgets(cliente1->identidade,TAM,stdin);
    printf("\nDigite a data de nascimento do cliente: \nDia: ");
    fflush(stdin);
    scanf("%d",&cliente1->data_de_nascimento.dia);
    printf("Mes: ");
    fflush(stdin);
    scanf("%d",&cliente1->data_de_nascimento.mes);
    printf("Ano: ");
    fflush(stdin);
    scanf("%d",&cliente1->data_de_nascimento.ano);
    printf("\nDigite o endereco do cliente: \nLogradouro: ");
    fflush(stdin);
    fgets(cliente1->endereco_completo.logradouro,TAM,stdin);
    printf("Numero: ");
    fflush(stdin);
    scanf("%d",&cliente1->endereco_completo.numero);
    printf("Bairro: ");
    fflush(stdin);
    fgets(cliente1->endereco_completo.bairro,TAM,stdin);
    printf("Cidade: ");
    fflush(stdin);
    fgets(cliente1->endereco_completo.cidade,TAM,stdin);
    printf("CEP: ");
    fflush(stdin);
    fgets(cliente1->endereco_completo.cep,TAM,stdin);
}

void ImprimirCliente(TCliente cliente1){
    printf("\nNome do cliente: %s",cliente1.nome);
    if(cliente1.tipo==0){
        printf("CPF: %s",cliente1.id);
    }else{
        printf("CNPJ: %s",cliente1.id);
    }
    printf("Identidade: %s",cliente1.identidade);
    printf("Data de Nascimento: %d/%d/%d\n",cliente1.data_de_nascimento.dia,cliente1.data_de_nascimento.mes,cliente1.data_de_nascimento.ano);
    printf("Endereco: \nLogradouro: %s",cliente1.endereco_completo.logradouro);
    printf("Numero: %d\n",cliente1.endereco_completo.numero);
    printf("Bairro: %s",cliente1.endereco_completo.bairro);
    printf("Cidade: %s",cliente1.endereco_completo.cidade);
    printf("CEP: %s",cliente1.endereco_completo.cep);
}

void IniciarModuloCliente(TModuloCliente *modulo){
    modulo->indice=0;
}

void InserirCliente(TModuloCliente *modulo,TCliente cliente){
    if(modulo->indice<TAM){
        modulo->vetor[modulo->indice]=cliente;
        modulo->indice++;
        printf("\nCliente Cadastrado com Sucesso!\n");
    }else{
        printf("\nNão é possível cadastrar!\n");
    }
}

int PesquisarCliente(TModuloCliente modulo,TCliente cliente){
    int i,j;
    for(i=0;i<modulo.indice;i++){
        j=strcmp(modulo.vetor[i].id,cliente.id);
        if(j==0){
            return i;
        }
    }
    return -1;
}

void ImprimirTodosClientes(TModuloCliente modulo){
    int i;
    for(i=0;i<modulo.indice;i++){
        ImprimirCliente(modulo.vetor[i]);
    }
}

void AlterarCliente(TModuloCliente *modulo,TCliente cliente1){
    int i = PesquisarCliente(*modulo,cliente1);
    if (i!=-1){
        LerCliente(&modulo->vetor[i]);
        printf("\nCliente Alterado com sucesso!\n");
    }else{
        printf("\nNao e Possivel alterar cliente nao encontrado\n");
    }
}

void ExcluirCliente(TModuloCliente *modulo,TCliente cliente1){
    int j;
    int i = PesquisarCliente(*modulo,cliente1);
    for(j=i;j<modulo->indice;j++){
        modulo->vetor[j]=modulo->vetor[j+1];
    }
    modulo->indice--;
}
