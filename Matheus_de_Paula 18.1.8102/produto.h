#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

typedef struct produto{
    int codigo;//ID
    char nome[TAM];
    char descricao[TAM];
    TData data_fabricacao;
    char lote[TAM];
    float preco;
    int quantidade;
} TProduto;

typedef struct moduloProduto{
    TProduto vetor[TAM];
    int indice;
}TModuloProduto;

void LerProduto(TProduto *produto1);
void ImprimirProduto(TProduto produto1);
void IniciarModuloProduto(TModuloProduto *modulo);
void InserirProduto(TModuloProduto *modulo,TProduto produto);
int PesquisarProduto(TModuloProduto modulo,TProduto produto1);
void ImprimirTodosProdutos(TModuloProduto modulo);
void AlterarProduto(TModuloProduto *modulo,TProduto produto1);
void ExcluirProduto(TModuloProduto *modulo,TProduto produto1);

#endif // PRODUTO_H_INCLUDED
