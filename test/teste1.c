//
// Created by Rita Vieira de Almeida on 05/01/2022.
//

#include "teste1.h"

void teste1() {

    CIDADE *cidades = (CIDADE *) malloc(sizeof (CIDADE));
    cidades->numCidades = 0;
    lerFicheiroCidades(cidades);
    //imprimirCidades(cidades);
    //escreverCidadesTxt(cidades);
    //escreverCidadesBin(cidades);

    CIDADE *cidades2 = (CIDADE *) malloc(sizeof (CIDADE));
    adCidade(cidades2,"Porto", "Cidade das Francesinhas", 1.0, 7.0, 3);
    //imprimirCidades(cidades2);


    //criar e inicializar uma lista de clientes
    LISTA_CLIENTES *listaClientes = (LISTA_CLIENTES *) malloc(sizeof (LISTA_CLIENTES));
    listaClientes->cabeca = listaClientes->cauda = NULL;
    listaClientes->tamanho = 0;
    lerFicheiroClientes(listaClientes);

    //criar clientes
    /*CLIENTE *pedro = (CLIENTE *) malloc(sizeof (CLIENTE));
    pedro = criarCliente("Pedro Lopes", "Rua das Cores", 987654321, 220077551, 23, 04, 1991, 01, 10, 2020, 134, listaClientes);
    adCLienteCauda(listaClientes, pedro);
    CLIENTE *amelia = (CLIENTE *) malloc(sizeof (CLIENTE));
    amelia = criarCliente("Amelia Carvalho", "Rua Numero Dois", 9184756321, 178594832, 11, 03, 1982, 02, 10, 2021, 230, listaClientes);
    adCLienteCauda(listaClientes, amelia);
    CLIENTE *rui = (CLIENTE *) malloc(sizeof (CLIENTE));
    rui = criarCliente("Rui Costa", "Rua do Maestro", 9373620101, 2294009541, 04, 11, 1970, 28, 02, 2019, 222, listaClientes);
    adCLienteCauda(listaClientes, rui);*/

    imprimirListaClientes(listaClientes);

    procurarClienteNIF(listaClientes, 220077551);
    procurarClienteNome(listaClientes, "Rui Costa");

    // à cabeça
    criarCliente("Ana Silva", "Rua ao Contrario", 938509453, 220954831, 12, 12, 1987, 20, 03, 2021, 58, listaClientes);
    apagarCliente(listaClientes, 220077551);    //pedro lopes

    imprimirListaClientes(listaClientes);
    listaClientesParaFicheiro(listaClientes);

    gerarRelatorio(listaClientes, "Rui Costa");

}