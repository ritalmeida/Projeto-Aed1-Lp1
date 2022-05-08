//
// Created by Rita Vieira de Almeida on 12/12/2021.
//

#ifndef PROJETO_AED_LP_FICHEIROS_H
#define PROJETO_AED_LP_FICHEIROS_H

#include "dados.h"

/**
 * função para gerar num ficheiro um cliente e as suas viagens
 * @param listaClientes - lista dos clientes
 * @param nomeCliente - nome do cliente que queremos gerar o relatório
 */
void gerarRelatorio(struct lista_clientes *listaClientes, char *nomeCliente);

/**
 * ler o ficheiro Clientes.txt e passar para uma lista ligada de clientes
 * @param listaClientes - a lista ligada de clientes
 */
void lerFicheiroClientes(struct lista_clientes *listaClientes);

/**
 * ler o ficheiro Cidades.txt e passar para um array de cidades
 * @param cidades - o array das cidades
 */
void lerFicheiroCidades(struct cidade *cidades);

/**
 * escrever as cidades de um array para um ficheiro de texto
 * @param cidades - o array das cidades
 * @return
 */
struct cidade *escreverCidadesTxt(struct cidade *cidades);

/**
 * passa uma lista ligada para um ficheiro de texto
 * @param clientes - a lista dos clientes
 * @return
 */
struct lista_clientes *listaClientesParaFicheiro(struct lista_clientes *clientes);

/**
 * escrever um array de cidades para o ficheiro bin
 * @param cidades
 */
void escreverCidadesBin(struct cidade *cidades);


#endif //PROJETO_AED_LP_FICHEIROS_H
