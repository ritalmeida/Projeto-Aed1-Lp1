//
// Created by Rita Vieira de Almeida on 30/11/2021.
//

#include "dados.h"


CLIENTE *criarCliente(char *nomeCliente, char *moradaCliente, int contactoCliente, int nifCliente, int diaNascCliente, int mesNascCliente, int anoNascCliente, int diaRegCliente, int mesRegCliente, int anoRegCliente, int faturacao, LISTA_CLIENTES *listaClientes) {

    //alocar memória na lista para o novo cliente
    CLIENTE *novoCliente = (CLIENTE *) malloc(sizeof(CLIENTE));
    strcpy(novoCliente->nome, nomeCliente);
    strcpy(novoCliente->morada, moradaCliente);
    novoCliente->contacto = contactoCliente;
    novoCliente->nif = nifCliente;
    novoCliente->DATA_NASCIMENTO.dia = diaNascCliente;
    novoCliente->DATA_NASCIMENTO.mes = mesNascCliente;
    novoCliente->DATA_NASCIMENTO.ano = anoNascCliente;
    novoCliente->REGISTO.dia = diaRegCliente;
    novoCliente->REGISTO.mes = mesRegCliente;
    novoCliente->REGISTO.ano = anoRegCliente;
    novoCliente->faturacao = faturacao;
    novoCliente->historicoViagens.tamanho = 0;
    novoCliente->historicoViagens.viagem = NULL;        //um novo cliente ainda não tem viagens
    novoCliente->prox = NULL;

    adCLienteCabeca(listaClientes, novoCliente);
    //adCLienteCauda(listaClientes, novoCliente);
    return novoCliente;
}

void adCLienteCabeca(LISTA_CLIENTES *listaClientes, CLIENTE *cliente) {

    // se a lista estiver vazia, inserimos no nó atual. senão, criamos espaço para um novo nó e inserimos aí
    if (listaClientes->cabeca == NULL && listaClientes->tamanho == 0) {

        listaClientes->cabeca = (CLIENTE *) cliente;
        listaClientes->cauda = (CLIENTE *) cliente;
        listaClientes->tamanho++;
    } else {

        cliente->prox = (CLIENTE *)listaClientes->cabeca;
        listaClientes->cabeca = cliente;
        listaClientes->tamanho++;
    }
}

void adCLienteCauda(LISTA_CLIENTES *listaClientes, CLIENTE *cliente) {

    // se a lista de clientes estiver vazia, insere o novo cliente, senao adiciona nó na cauda da lista para novo cliente
    if (listaClientes->cabeca == NULL && listaClientes->tamanho == 0) {

        listaClientes->cabeca = (CLIENTE *) cliente;
        listaClientes->cauda = (CLIENTE *) cliente;
        listaClientes->tamanho++;
    } else {

        listaClientes->cauda->prox = (CLIENTE *) cliente;
        listaClientes->cauda = cliente;
        listaClientes->tamanho++;
    }

    listaClientes->cauda->prox = NULL;
}

LISTA_CLIENTES *apagarCliente(LISTA_CLIENTES *listaClientes, int nifCliente) {

    CLIENTE *clienteEliminar;
    CLIENTE *clienteAtual = listaClientes->cabeca;
    while (clienteAtual != NULL) {      //enquanto houver clientes na lista

        if (clienteAtual->nif == nifCliente) {      //cliente encontrado, elimina
            listaClientes->cabeca = (CLIENTE *) clienteAtual->prox;
            listaClientes->tamanho--;
            free(clienteAtual);
            printf("AVISO: O cliente foi eliminado com sucesso!\n");
            return listaClientes;
        } else {
            while (clienteAtual->prox != NULL) {

                clienteEliminar = (CLIENTE *) clienteAtual->prox;
                if (clienteEliminar->nif == nifCliente) {

                    if (clienteEliminar->prox == NULL) {

                        listaClientes->cauda = clienteAtual;
                        listaClientes->cauda->prox = clienteEliminar->prox;
                    } else
                        clienteAtual->prox = clienteEliminar->prox;
                    listaClientes->tamanho--;
                    printf("AVISO: O cliente %s foi eliminado com sucesso!\n", clienteEliminar->nome);
                    free(clienteEliminar);
                    return listaClientes;
                } else
                    clienteAtual = (CLIENTE *) clienteAtual->prox;
            }
        }
    }
    printf("ERRO: O Cliente procurado nao existe!!\n");
    return listaClientes;
}

void imprimirListaClientes(LISTA_CLIENTES *listaClientes) {

    CLIENTE *clienteAtual = listaClientes->cabeca;

    printf("Lista de Clientes: \n\n");
    while (clienteAtual != NULL) {

        printf("Cliente: %s\n", clienteAtual->nome);
        printf("Morada: %s\n", clienteAtual->morada);
        printf("Contacto: %d\n", clienteAtual->contacto);
        printf("NIF: %d\n", clienteAtual->nif);
        printf("Data de Nascimento (dd/mm/aaaa): %d/%d/%d\n", clienteAtual->DATA_NASCIMENTO.dia,
               clienteAtual->DATA_NASCIMENTO.mes, clienteAtual->DATA_NASCIMENTO.ano);
        printf("Data registo: %d/%d/%d\n", clienteAtual->REGISTO.dia, clienteAtual->REGISTO.mes, clienteAtual->REGISTO.ano);
        printf("Faturacao: %d\n", clienteAtual->faturacao);
        printf("Viagens (%d): \n", clienteAtual->historicoViagens.tamanho);
        for (int i = 0; i < clienteAtual->historicoViagens.tamanho; i++) {

            VIAGEM viagem = clienteAtual->historicoViagens.viagem[i];
            printf("Viagem %d: \n", viagem.cidadesvizitadas);
            for (int j = 0; j < viagem.cidadesvizitadas; j++) {

                printf("Cidade: %s\n", viagem.cidade[j].nome);
                printf("Numero de Pontos de Interesse visitados: %d\n", viagem.cidade[j].arrPtosInteresse->tamanho);
                for (int k = 0; k < viagem.cidade[j].arrPtosInteresse->tamanho; k++) {

                    printf("Ponto de Interesse: %s\n", viagem.cidade[j].arrPtosInteresse[k].pontoDeInteresse->nome);
                }
            }
            printf("\n");
        }
        printf("\n");
        clienteAtual = (CLIENTE *) clienteAtual->prox;
    }
    /*CLIENTE *clienteAtual = listaClientes->cabeca;

    if (clienteAtual == NULL) {
        printf("A lista esta vazia!\n");
    } else {
        printf("Lista de Clientes: \n\n");
        while (clienteAtual != NULL) {

            if (clienteAtual->nif != 0) {

                printf("Cliente: %s\n", clienteAtual->nome);
                printf("Morada: %s\n", clienteAtual->morada);
                printf("Contacto: %d\n", clienteAtual->contacto);
                printf("NIF: %d\n", clienteAtual->nif);
                printf("Data de Nascimento (dd/mm/aaaa): %d/%d/%d\n", clienteAtual->DATA_NASCIMENTO.dia, clienteAtual->DATA_NASCIMENTO.mes, clienteAtual->DATA_NASCIMENTO.ano);
                printf("Data registo: %d/%d/%d\n", clienteAtual->REGISTO.dia, clienteAtual->REGISTO.mes, clienteAtual->REGISTO.ano);
                printf("Faturacao: %d\n", clienteAtual->faturacao);
                for (int i = 0; i < clienteAtual->historicoViagens.tamanho; i++) {

                    VIAGEM viagem = clienteAtual->historicoViagens.viagem[i];
                    printf("%d\n", viagem.cidadesvizitadas);
                    for (int j = 0; j < viagem.cidadesvizitadas; j++) {

                        printf("%s\n", viagem.cidade[j].nome);
                    }
                    printf("\n");
                }
            }
            printf("\n");
            clienteAtual = clienteAtual->prox;
        }
    }*/
}

CLIENTE *procurarClienteNome(LISTA_CLIENTES * listaClientes, char *nome) {

    CLIENTE *cliente;
    cliente = listaClientes->cabeca;

    //percorre os nós da lista
    while (cliente != NULL) {

        if (strcmp(cliente->nome, nome) == 0) {          //o cliente atual tem o nome do procurado
            printf("AVISO: Existe um cliente com esse nome:\n");
            printf("Cliente: %s\n", cliente->nome);
        }
        cliente = cliente->prox;
    }
    return cliente;
}

CLIENTE *procurarClienteNIF(LISTA_CLIENTES *listaClientes, int nif) {

    CLIENTE *cliente = listaClientes->cabeca;

    while (cliente != NULL) {

        if (cliente->nif == nif) {

            printf("AVISO: Existe um cliente com esse NIF: \n");
            printf("Cliente: %s, NIF: %d\n", cliente->nome, cliente->nif);
        }
        cliente = cliente->prox;
    }
    return cliente;
}

LISTA_CLIENTES *adViagem(LISTA_CLIENTES * listaClientes, char *nomeCliente) {

    CLIENTE *cliente = listaClientes->cabeca;
    int numCidades = 0;
    char cidadeVisitada[20];

    while (cliente != NULL) {   //vai percorrer a lista dos clientes até encontrar o que queremos

        if (strcmp(nomeCliente, cliente->nome) == 0) {

            int i = cliente->historicoViagens.tamanho++;
            HISTORICO_VIAGENS *historicoViagens = (HISTORICO_VIAGENS *) malloc(sizeof (HISTORICO_VIAGENS)*i);
            historicoViagens->tamanho = i;

            if (cliente->historicoViagens.viagem != NULL) {

                cliente->historicoViagens.viagem = (VIAGEM *) realloc(cliente->historicoViagens.viagem, sizeof (VIAGEM)*i);
            } else
                cliente->historicoViagens.viagem = (VIAGEM *) malloc(sizeof (VIAGEM));

            //dar a dimensão do array
            printf("Quantas cidades visitou o cliente %s?\n", cliente->nome);
            scanf("%d", numCidades);
            /*if (cliente->historicoViagens.tamanho == 1) {
                cliente->historicoViagens.viagem->cidadesvizitadas = numViagens;
            } else*/
            cliente->historicoViagens.viagem[i].cidadesvizitadas = numCidades;
            printf("Insira as cidades visitadas pelo cliente %s:\n", cliente->nome);
            CIDADE *cidade = (CIDADE *) malloc(sizeof (CIDADE)*numCidades);
            for (int j = 0; j < numCidades; j++) {

                gets(cidadeVisitada);
                cidade[j] = procurarCidade(cidadeVisitada);
            }
            cidade->arrPtosInteresse->tamanho = 0;
            cidade->arrPtosInteresse->pontoDeInteresse = NULL;
            cliente->historicoViagens.viagem[i].cidade = cidade;

            return listaClientes;
        }
        cliente = (CLIENTE * )cliente->prox;
    }
    printf("ERRO: O cliente nao foi encontrado!\n");
    return listaClientes;
}

CIDADE procurarCidade(char *nomeCidade) {

    CIDADE *cidades;

    for (int i = 0; i < cidades->numCidades; i++) {

        if (strcmp(cidades[i].nome, nomeCidade) == 0) {
            return cidades[i];
        }
    }
    printf("ERRO: Cidade nao encontrada!\n");
    exit(-1);
}

LISTA_CLIENTES *eliminarViagem(LISTA_CLIENTES *listaClientes, char *nomeCliente) {

    CLIENTE *cliente = listaClientes->cabeca;
    while (cliente != NULL) {

        if (strcmp(cliente->nome, nomeCliente) == 0) {

            printf("O cliente %s realizou %d viagens: \n", nomeCliente, cliente->historicoViagens.tamanho);
            for (int i = 0; i < cliente->historicoViagens.tamanho; i++) {

                printf("Viagem[%d]: ", i);
                VIAGEM *viagem = cliente->historicoViagens.viagem;
                for (int j = 0; j < viagem[i].cidadesvizitadas; j++) {
                    printf("%s\n", viagem[i].cidade[j].nome);
                }
                printf("\n");
            }
            printf("Que viagem quer eliminar?\n");
            int id = 0;
            scanf("%d\n", &id);
            for (int i = id; i < cliente->historicoViagens.tamanho; i++) {

                cliente->historicoViagens.viagem[i] = cliente->historicoViagens.viagem[i+1];    //avança 1 posição
            }
            cliente->historicoViagens.tamanho--;
            realloc(cliente->historicoViagens.viagem, sizeof (VIAGEM) * cliente->historicoViagens.tamanho);
        }
        cliente = (CLIENTE *) cliente->prox;
    }
    return listaClientes;
}

CIDADE *adCidade(CIDADE *listaCidades, char *nomeCidade, char *descricao, float x, float y, int numPoIs) {

    int tamanho = listaCidades->numCidades;
    listaCidades = realloc(listaCidades, sizeof (CIDADE)*(tamanho+1));
    listaCidades[tamanho].arrPtosInteresse = malloc(sizeof (ARRAY_PoI));
    strcpy(listaCidades[tamanho].nome, nomeCidade);
    strcpy(listaCidades[tamanho].descricao, descricao);
    listaCidades[tamanho].x = x;
    listaCidades[tamanho].y = y;
    listaCidades[tamanho].arrPtosInteresse->tamanho = numPoIs;
    listaCidades[tamanho].arrPtosInteresse->pontoDeInteresse = NULL;
    listaCidades->numCidades++;
    printf("AVISO: A cidade %s foi adicionada com sucesso!\n", nomeCidade);
    return listaCidades;
 }

 void imprimirCidades(CIDADE *arrCidades) {

     //printf(" %d ", arrCidades->numCidades);
     printf("Cidades: \n\n");
     for (int i = 0; i < 7; i++) {

         printf("\nCidade: %s\n", arrCidades[i].nome);
         printf("Descricao: %s\n", arrCidades[i].descricao);
         printf("Coordenadas: (%.2f,%.2f)\n", arrCidades[i].x, arrCidades[i].y);
         printf("Pontos de interesse: \n", arrCidades[i].arrPtosInteresse->pontoDeInteresse);
         for (int j = 0; j < arrCidades[i].arrPtosInteresse->tamanho; j++) {

             printf("%s \n", arrCidades[i].arrPtosInteresse[j].pontoDeInteresse->nome);
         }
     }
}

void imprimirCidade(char *cidade) {

    CIDADE *arrCidades;

    for (int i = 0; i < arrCidades->numCidades; i++) {

        if (strcmp(arrCidades[i].nome, cidade) == 0) {

            printf("\nCidade: %s\n", arrCidades[i].nome);
            printf("Descricao: %s\n", arrCidades[i].descricao);
            printf("Coordenadas: (%.2f,%.2f)\n", arrCidades[i].x, arrCidades[i].y);
            printf("Pontos de interesse: \n", arrCidades[i].arrPtosInteresse->pontoDeInteresse);
            for (int j = 0; j < arrCidades[i].arrPtosInteresse->tamanho; j++) {

                printf("%s \n", arrCidades[i].arrPtosInteresse[j].pontoDeInteresse->nome);
            }
            return;
        }
    }
    printf("ERRO: A cidade %s nao existe na base de dados!\n", cidade);
}

void editaDescricaoCidade(CIDADE *arrCidade, char *nome, char *descricaoNova) {

    for (int i = 0; i < arrCidade->numCidades; i++) {

        if (strcmp(arrCidade[i].nome, nome) == 0) {
            strcpy(arrCidade[i].descricao, descricaoNova);
        } else
            printf("ERRO! A cidade pretendida nao existe!\n");
    }
}

void adPoI(CIDADE *arrCidades, char *nomeCidade, char *nomePoI) {

    for (int i = 0; i < arrCidades->numCidades; i++) {

        if (strcmp(arrCidades[i].nome, nomeCidade) == 0) {

            int aux = arrCidades[i].arrPtosInteresse->tamanho;
            arrCidades->arrPtosInteresse->tamanho++;
            arrCidades[i].arrPtosInteresse->pontoDeInteresse = (PoI *) realloc(arrCidades[i].arrPtosInteresse->pontoDeInteresse, sizeof (PoI) * arrCidades[i].arrPtosInteresse->tamanho);
            strcpy(arrCidades[i].arrPtosInteresse->pontoDeInteresse[aux].nome, nomePoI);
            return;
        }
    }
    printf("ERRO: A cidade nao existe!\n");
    exit(-1);
}

void eliminarPoI(CIDADE *arrCidades, char *nomeCidade, char *nomePoI) {
    int i;
    for ( i = 0; i < arrCidades->numCidades; i++) {

        if (strcmp(arrCidades[i].nome, nomeCidade) == 0)
            break;
    }
    for (int j = 0; j < arrCidades[j].arrPtosInteresse->tamanho; j++) {

        if (strcmp(arrCidades[i].arrPtosInteresse->pontoDeInteresse[j].nome, nomePoI) == 0) {

            for (int k = j; k < arrCidades[i].arrPtosInteresse->tamanho; k++) {
                arrCidades[i].arrPtosInteresse->pontoDeInteresse[k] = arrCidades[i].arrPtosInteresse->pontoDeInteresse[k+1];
            }
            arrCidades[i].arrPtosInteresse->tamanho--;
            realloc(arrCidades[i].arrPtosInteresse->pontoDeInteresse, sizeof (PoI) * arrCidades[i].arrPtosInteresse->tamanho);
            return;
        }
    }
}

void procurarPoI(CIDADE *cidades, char *nomePoI) {

for (int i = 0; i < cidades->numCidades; i++) {

    for (int j = 0; j < cidades[i].arrPtosInteresse->tamanho; j++) {

        if (strcmp(cidades[i].arrPtosInteresse->pontoDeInteresse[j].nome, nomePoI) == 0) {

            printf("A cidade %s tem o ponto de interesse %s\n", cidades[i].nome, nomePoI);
            return;
        }
    }
}
    printf("ERRO: Este ponto de interesse nao existe!\n");
}