//
// Created by Rita Vieira de Almeida on 12/12/2021.
//

#include "ficheiros.h"

FILE *fp;

void gerarRelatorio(struct lista_clientes *listaClientes, char *nomeCliente) {

    CLIENTE *cliente = listaClientes->cabeca;

    while (cliente != NULL) {

        if (strcmp(cliente->nome, nomeCliente) == 0) {

            fp = fopen("../data/Relatorio.txt", "w");
            if (fp == NULL) {
                printf("ERRO: Impossivel abrir ficheiro!\n");
                exit(-1);
            }
            fprintf(fp, "O cliente %s ja realizou %d viagens:\n", cliente->nome, cliente->historicoViagens.tamanho);
            for (int i = 0; i < cliente->historicoViagens.tamanho; i++) {

                fprintf(fp, "O Cliente visitou: \n");
                for (int j = 0; j < cliente->historicoViagens.viagem[i].cidadesvizitadas; j++) {

                    fprintf(fp, "Cidade %s: ", cliente->historicoViagens.viagem[i].cidade[j].nome);
                    for (int k = 0; k < cliente->historicoViagens.viagem[i].cidade[j].arrPtosInteresse->tamanho; k++) {

                        fprintf(fp, "Pontos de Interesse: %s ", cliente->historicoViagens.viagem[i].cidade[j].arrPtosInteresse->pontoDeInteresse[k].nome);
                    }
                    printf("\n");
                }
            }
            fclose(fp);
            return;
        }
        cliente = (CLIENTE *) cliente->prox;
    }
    printf("ERRO: Cliente nao encontrado!\n");
}

void lerFicheiroClientes(struct lista_clientes *listaClientes) {

    char nomeCidade[30], nomePoI[50], aux[50];
    int numClientes, numViagens, numCidades, numPoIs;
    if ((fp = fopen("../data/Clientes.txt", "r")) == NULL) {

        printf("ERRO: Impossivel abrir o ficheiro!\n");
        exit(-1);
    }
    fscanf(fp, "%d\n", &numClientes);
    for (int i = 0; i < numClientes; i++) {

        CLIENTE *cliente = (CLIENTE *) malloc(sizeof (CLIENTE));
        fscanf(fp, "%[^,],", cliente->nome);
        fscanf(fp, "%[^,],", cliente->morada);
        fscanf(fp, "%[^,],", aux);
        cliente->contacto = atoi(aux);
        fscanf(fp, "%[^,],", aux);
        cliente->nif = atoi(aux);
        fscanf(fp, "%[^/]/", aux);
        cliente->DATA_NASCIMENTO.dia = atoi(aux);
        fscanf(fp, "%[^/]/", aux);
        cliente->DATA_NASCIMENTO.mes = atoi(aux);
        fscanf(fp, "%[^,],", aux);
        cliente->DATA_NASCIMENTO.ano = atoi(aux);
        fscanf(fp, "%[^/]/", aux);
        cliente->REGISTO.dia = atoi(aux);
        fscanf(fp, "%[^/]/", aux);
        cliente->REGISTO.mes = atoi(aux);
        fscanf(fp, "%[^,],", aux);
        cliente->REGISTO.ano = atoi(aux);
        fscanf(fp, "%[^\n]\n", aux);
        cliente->faturacao = atoi(aux);
        fscanf(fp, "%d\n", &numViagens);
        //printf(" num viagens: %d ", numViagens);
        cliente->historicoViagens.tamanho = numViagens;
        VIAGEM *viagem = (VIAGEM *) malloc(sizeof (VIAGEM) * numViagens);
        for (int i = 0; i < numViagens; i++) {

            fscanf(fp, "%d\n", &numCidades);
            //printf(" num cidades: %d " ,numCidades);
            viagem[i].cidadesvizitadas = numCidades;
            CIDADE *cidade = (CIDADE *) malloc(sizeof (CIDADE) * numCidades);
            for (int j = 0; j < numCidades; j++) {
                fscanf(fp, "%[^,],", nomeCidade);
                //printf(" nome cidade :%s ", nomeCidade);
                fscanf(fp, "%[^\n]\n", aux);
                numPoIs = atoi(aux);
                //printf(" num ptos : %d ", numPoIs);
                ARRAY_PoI *arrayPoIs = (ARRAY_PoI *) malloc(sizeof (ARRAY_PoI));
                arrayPoIs->tamanho = numPoIs;
                PoI *poI = (PoI *) malloc(sizeof (PoI) * numPoIs);
                for (int k = 0; k < numPoIs; k++) {

                    fscanf(fp, "%[^\n]\n", nomePoI);
                    //printf(" nome poi: %s", nomePoI);
                    arrayPoIs->pontoDeInteresse = poI;
                }
                cidade[j].arrPtosInteresse = arrayPoIs;
                viagem[i].cidade = cidade;
            }
            cliente->historicoViagens.viagem = viagem;
        }
        adCLienteCauda(listaClientes, cliente);
    }
    fclose(fp);
}

void lerFicheiroCidades(struct cidade *cidades) {

    int numCidades, numPoIs;
    char nomePoI[100], aux[5];


    if ((fp = fopen("../data/Cidades.txt", "r")) == NULL) {

        printf("ERRO: Impossivel abrir o ficheiro Cidades.txt\n");
        exit(-1);
    }
    fscanf(fp, "%d\n", &numCidades);
    cidades = (CIDADE *) malloc(sizeof (CIDADE) * numCidades);
    for (int i = 0; i < numCidades; i++) {
        fscanf(fp, "%[^,],", cidades[i].nome);
        fscanf(fp, "%[^,],", cidades[i].descricao);
        fscanf(fp, "%[^,],", aux);
        cidades[i].x = atof(aux);
        fscanf(fp, "%[^,],", aux);
        cidades[i].y = atof(aux);
        fscanf(fp, "%[^\n]\n", aux);
        numPoIs = atoi(aux);
        //printf("%d %s %s %.2f %.2f %d\n", numCidades, cidades[i].nome, cidades[i].descricao, cidades[i].x, cidades[i].y, numPoIs);
        cidades->numCidades = numCidades;
        ARRAY_PoI *arrayPoI = (ARRAY_PoI *) malloc(sizeof (ARRAY_PoI));
        arrayPoI->tamanho = numPoIs;
        PoI *poI = (PoI *) malloc(sizeof (PoI) * numPoIs);
        for (int j = 0; j < numPoIs; j++) {

            fscanf(fp, "%[^\n]\n", nomePoI);
            strcpy(poI[j].nome, nomePoI);
            //printf("%s ", nomePoI);
        }
        cidades[i].arrPtosInteresse = arrayPoI;
    }
    fclose(fp);
}

struct cidade *escreverCidadesTxt(struct cidade *cidades) {

    if ((fp = fopen("../data/escreverCidades.txt", "w")) == 0) {

        printf("ERRO: Nao e possivel aceder ao ficheiro!\n");
        exit(-1);
    }
    fprintf(fp, "%d\n", cidades->numCidades);
    for (int i = 0; i < cidades->numCidades; i++) {

        fprintf(fp,"%s,%s,%.2f,%.2f,%d\n", cidades[i].nome, cidades[i].descricao, cidades[i].x, cidades[i].y, cidades[i].arrPtosInteresse->tamanho);
        for (int j = 0; j < cidades[i].arrPtosInteresse->tamanho; j++) {

            fprintf(fp, "%s\n", cidades[i].arrPtosInteresse->pontoDeInteresse[j].nome);
        }
    }
    printf("AVISO: Cidades escritas no ficheiro!\n\n");
    fclose(fp);
}

struct lista_clientes *listaClientesParaFicheiro(struct lista_clientes *clientes) {

    CLIENTE *clienteAtual = clientes->cabeca;
    fp = fopen("../data/ListaClientes.txt", "w");

    if (fp == NULL) {

        printf("ERRO: Impossivel criar o ficheiro!\n");
        exit(-1);
    }
    fprintf(fp, "%d\n", clientes->tamanho);
    while (clienteAtual != NULL) {

        fprintf(fp, "%s,%s,%d,%d,%d/%d/%d,%d/%d/%d,%d\n", clienteAtual->nome, clienteAtual->morada, clienteAtual->contacto, clienteAtual->nif,
                clienteAtual->DATA_NASCIMENTO.dia, clienteAtual->DATA_NASCIMENTO.mes, clienteAtual->DATA_NASCIMENTO.ano,
                clienteAtual->REGISTO.dia, clienteAtual->REGISTO.mes, clienteAtual->REGISTO.ano, clienteAtual->faturacao);
        fprintf(fp, "%d\n", clienteAtual->historicoViagens.tamanho);
        for (int i = 0; i < clienteAtual->historicoViagens.tamanho; i++) {

            fprintf(fp, "%d\n", clienteAtual->historicoViagens.viagem[i].cidadesvizitadas);
            for (int j = 0; j < clienteAtual->historicoViagens.viagem[i].cidadesvizitadas; j++) {

                fprintf(fp, "%s,%d\n", clienteAtual->historicoViagens.viagem[i].cidade[j].nome, clienteAtual->historicoViagens.viagem[i].cidade[j].arrPtosInteresse->tamanho);
                for (int k = 0; k < clienteAtual->historicoViagens.viagem[i].cidade[j].arrPtosInteresse->tamanho; k++) {

                    fprintf(fp, "%s\n", clienteAtual->historicoViagens.viagem[i].cidade[j].arrPtosInteresse->pontoDeInteresse[k].nome);
                }
            }
        }
        clienteAtual = (CLIENTE *) clienteAtual->prox;
    }
    printf("AVISO: Clientes escritos no ficheiro!\n\n");
    fclose(fp);
}

void escreverCidadesBin(struct cidade *cidades) {

    char nomePoI[100];

    if ((fp == fopen("../data/Cidades.bin", "wb")) == NULL) {

        printf("ERRO! Impossivel criar o ficheiro!\n");
        exit(-1);
    }
    fwrite(&cidades->numCidades, sizeof (int), 1, fp);
    for (int i = 0; i < cidades->numCidades; i++) {

        fwrite(cidades[i].nome, sizeof (strlen(cidades[i].nome)+1), 1, fp);
        fwrite(cidades[i].descricao, sizeof (strlen(cidades[i].descricao)+1), 1, fp);
        fwrite(&cidades[i].x, sizeof (float), 1, fp);
        fwrite(&cidades[i].y, sizeof (float), 1, fp);
        fwrite(&cidades[i].arrPtosInteresse->tamanho, sizeof (int), 1, fp);
        for (int j = 0; j < cidades[i].arrPtosInteresse->tamanho; j++) {

            fwrite(cidades[i].arrPtosInteresse->pontoDeInteresse[j].nome, sizeof (strlen(cidades[i].arrPtosInteresse->pontoDeInteresse[j].nome)+1),1 ,fp);
        }
    }
    fclose(fp);
}
