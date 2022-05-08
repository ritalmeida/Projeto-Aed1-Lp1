//
// Created by Rita Vieira de Almeida on 02/01/2022.
//

#ifndef PROJETO_AED_LP_ALGORITMOGENETICO_H
#define PROJETO_AED_LP_ALGORITMOGENETICO_H

#include "dados.h"
#include "ficheiros.h"
#include "main.h"
#include "test/teste1.h"

typedef struct parametrizacao {

    int tamanho;
    int numCidades;
    int populacao; //conjunto trajetos possiveis
}PARAMETRIZACAO;

//trajeto entre as cidades
typedef struct individuo {

    double *aptidao;    //aferor qual melhor/pior trajeto
    struct individuo *proxIndividuo;
}INDIVIDUO;

typedef struct geracao {

    int id;
    double *aptidao;
    struct geracao *prox;
    VIAGEM *viagem;
}GERACAO;

#endif //PROJETO_AED_LP_ALGORITMOGENETICO_H
