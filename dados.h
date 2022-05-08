//
// Created by Rita Vieira de Almeida on 30/11/2021.
//

#ifndef PROJETO_AED_LP_DADOS_H
#define PROJETO_AED_LP_DADOS_H

#include "test/teste1.h"
#include "main.h"
#include <stdlib.h>
#include <printf.h>
#include <string.h>
#include "ficheiros.h"

typedef struct poi {

    char nome[100];
}PoI;

typedef struct arrayPoI {

    PoI *pontoDeInteresse;
    int tamanho;
}ARRAY_PoI;

typedef struct cidade {

    char nome[50];
    char descricao[100];
    float x, y;
    ARRAY_PoI *arrPtosInteresse;
    int numCidades;
}CIDADE;

/**
 *
 */
typedef struct viagem {

    int cidadesvizitadas;
    struct dataInicio {
        int dia, mes, ano;
    }DATAINICIO;
    struct dataFim {
        int dia, mes, ano;
    }DATAFIM;
    CIDADE *cidade;
}VIAGEM;

/**
 *
 */
typedef struct historico_viagens {

    VIAGEM *viagem;
    int tamanho;
}HISTORICO_VIAGENS;

/**
 *
 */
typedef struct cliente {

    char nome[50];
    char morada[100];
    int contacto;
    int nif;
    struct dataNascimento {
        int dia, mes, ano;
    }DATA_NASCIMENTO;
    struct registo {
        int dia, mes, ano;
    }REGISTO;
    HISTORICO_VIAGENS historicoViagens;
    int faturacao;
    struct cliente *prox;
}CLIENTE;

/**
 *
 */
typedef struct lista_clientes {

    CLIENTE *cabeca;
    CLIENTE *cauda;
    int tamanho;
}LISTA_CLIENTES;


/**
 * FUNÇÕES PARA
 * MANIPULAR CLIENTES
 */

/**
 * função para criar um cliente que depois adicionamos à lista através de funções
 * auxiliares para adicionar à cabeça ou à cauda da lista ligada de clientes. recebe os atributos
 * do cliente e a lista ligada
 * @param nomeCliente
 * @param moradaCliente
 * @param contactoCliente
 * @param nifCliente
 * @param diaNascCliente
 * @param mesNascCliente
 * @param anoNascCliente
 * @param diaRegCliente
 * @param mesRegCliente
 * @param anoRegCliente
 * @param faturacao
 * @param listaClientes
 * @return o novo cliente
 */
CLIENTE *criarCliente(char *nomeCliente, char *moradaCliente, int contactoCliente, int nifCliente, int diaNascCliente, int mesNascCliente, int anoNascCliente, int diaRegCliente, int mesRegCliente, int anoRegCliente, int faturacao, LISTA_CLIENTES *listaClientes);

/**
 * adiciona o clinete à cabeça da lista ligada. usada na função cirarCliente
 * @param listaClientes - a lista onde adicionamos o cliente
 * @param cliente - o cliente que queremos adicionar à lista
 */
void adCLienteCabeca(LISTA_CLIENTES *listaClientes, CLIENTE *cliente);

/**
 * adiciona o clinete à cauda da lista ligada. usada na função cirarCliente
 * @param listaClientes - a lista onde adicionamos o cliente
 * @param cliente - o cliente que queremos adicionar à lista
 */
void adCLienteCauda(LISTA_CLIENTES *listaClientes, CLIENTE *cliente);

/**
 * procura o cliente que queremos eliminar através do seu NIF e elimina-mos
 * @param listaClientes - lista onde está o cliente
 * @param nifCliente - nif do cliente a eliminar
 * @return a lista ligada atualizada
 */
LISTA_CLIENTES *apagarCliente(LISTA_CLIENTES *listaClientes, int nifCliente);

/**
 * imprime a lista ligada dos clientes
 * @param listaClientes - a lista ligada que queremos imprimir
 */
void imprimirListaClientes(LISTA_CLIENTES *listaClientes);

/**
 * procura um cliente numa lista ligada, pelo nome do cliente
 * @param listaClientes - a lista onde está o clientes
 * @param nome - nome do cliente que queremos encontrar
 * @return o cliente procurado
 */
CLIENTE *procurarClienteNome(LISTA_CLIENTES * listaClientes, char *nome);

/**
 * procurar um cliente numa lista ligada, percorrendo-a até encontrar um nif correspondente
 * @param listaClientes - a lista onde famos fazer a pesquisa
 * @param nif - o nif correspondente ao cliente que queremos procurar
 * @return o cliente que procuramos
 */
CLIENTE *procurarClienteNIF(LISTA_CLIENTES *listaClientes, int nif);

/**
 * adiciona uma viagem a um cliente
 * @param listaClientes - a lista onde está o cliente
 * @param nomeCliente - o nome do cliente que queremos adicionar uma viagem
 * @return a lista de clientes atualizada
 */
LISTA_CLIENTES *adViagem(LISTA_CLIENTES * listaClientes, char *nomeCliente);

/**
 * procura uma cidade
 * @param nomeCidade - nome da cidade a procurar
 * @return a cidade encontrada
 */
CIDADE procurarCidade(char *nomeCidade);

/**
 * eliminar uma viagem de um cliente
 * @param listaClientes - a lista dos clientes
 * @param nomeCliente - o nome do cliente a quem queremos eliminar uma viagem
 * @return a lista de clientes atualizada
 */
LISTA_CLIENTES *eliminarViagem(LISTA_CLIENTES *listaClientes, char *nomeCliente);

/**
 * adiciona uma cidade ao array das cidades, passando os parametros para os atributos
 * correspondetes de Cidade
 * @param listaCidades
 * @param nomeCidade
 * @param descricao
 * @param x
 * @param y
 * @param numPoIs
 * @return a nova cidade
 */
CIDADE *adCidade(CIDADE *listaCidades, char *nomeCidade, char *descricao, float x, float y, int numPoIs);

/**
 * imprime o array das cidades
 * @param arrCidades - o array das cidades
 */
void imprimirCidades(CIDADE *arrCidades);

/**
 * imprime uma cidade e tudo o que a compõe
 * @param cidade - o nome da cidade que queremos imprimir
 */
void imprimirCidade(char *cidade);

/**
 * edita a descrição de uma cidade
 * @param arrCidade - o array das cidades
 * @param nome - o nome da cidade que queremos alterar
 * @param descricaoNova - a nova descrição da cidade
 */
void editaDescricaoCidade(CIDADE *arrCidade, char *nome, char *descricaoNova);

/**
 * adiciona um Ponto de Interesse a uma cidade
 * @param arrCidades - o array das cidades
 * @param nomeCidade - o nome da cidade a quem queremos adicionar um PoI
 * @param nomePoI - o nome do PoI
 */
void adPoI(CIDADE *arrCidades, char *nomeCidade, char *nomePoI);

/**
 * elimina um Ponto de Interesse numa cidade
 * @param arrCidades - o array das cidades
 * @param nomeCidade - o nome da cidade onde queremos eliminar um PoI
 * @param nomePoI - o nome do PoI a ser eliminado
 */
void eliminarPoI(CIDADE *arrCidades, char *nomeCidade, char *nomePoI);

/**
 * função para procurar um Ponto de Interesse
 * @param cidades - o array das cidades
 * @param nomePoI - o ponto de interesse que queremos procurar
 */
void procurarPoI(CIDADE *cidades, char *nomePoI);


#endif //PROJETO_AED_LP_DADOS_H
