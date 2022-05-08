//
// Created by Rita Vieira de Almeida on 02/01/2022.
//

#include <tgmath.h>
#include "algoritmoGenetico.h"

GERACAO *criarGeracao(VIAGEM *viagem, CIDADE *cidades) {

    GERACAO *geracao = (GERACAO *) malloc(sizeof (GERACAO));
    geracao->id = 0;
    geracao->viagem = viagem;
}

//para a geraçao
float distanciaCidades(float x1, float y1, float x2, float y2) {

    float x = x2-x1;
    float y = y2-y1;

    float distancia = sqrt(pow(x, 2) + pow(y, 2));

    return distancia;
}

void procurarGeracaoID(GERACAO *geracao, int ID, int tamanho) {

    while (geracao != NULL) {

        printf("ID: %d\n", geracao->id);
        for (int i = 0; i < tamanho; i++) {

            printf("Aptidao: %d\n", geracao->aptidao[i]);
        }
        /**
         * INCOMPLETO
         */
    }
}
