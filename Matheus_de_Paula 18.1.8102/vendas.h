#ifndef VENDAS_H_INCLUDED
#define VENDAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

typedef struct vendas{
    char id[TAM];
    int codigo;
    TData data_venda;
    TData data_pagamento;
    float valor_total_venda;
    int pagamento;// 0 = á vista, 1 = à prazo
    float debito;
    int quantidade;
} TVendas;

typedef struct moduloVendas{
    TVendas vetor[TAM];
    int indice;
}TModuloVendas;

void LerVendas(TVendas *vendas1);
void ImprimirVendas(TVendas vendas1);
void IniciarModuloVenda(TModuloVendas *modulo);
void InserirVenda(TModuloVendas *modulo3,TVendas venda,TModuloProduto *modulo1,TModuloCliente modulo2);
int PesquisarVenda(TModuloVendas modulo,TVendas vendas);
void ImprimirTodasVendas(TModuloVendas modulo);
void AlterarVenda(TModuloVendas *modulo,TVendas venda1);
void ExcluirVenda(TModuloVendas *modulo,TVendas venda1);

#endif // VENDAS_H_INCLUDED
