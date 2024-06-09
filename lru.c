//
// Created by eferraris on 31/05/24.
//

#include "lru.h"
#include <stdio.h>
#include <stdlib.h>

Nodo *newNodo (int identificador) {
    Nodo * aux = malloc(sizeof(Nodo));

    if (aux == NULL) {
        printf("Sin memoria");
        exit (-1);
    }

    if (identificador > IDENTIFICADOR_MAX) {
        printf("El elemento no puede superar %d", IDENTIFICADOR_MAX);
        return NULL;
    }

    aux->idenficador = identificador;
    aux->sig = NULL;
    aux->ant = NULL;

    return aux;
}

Cache *newCache(int tamanio) {
    Cache * aux = malloc(sizeof(Cache));

    if (aux == NULL) {
        printf("Sin memoria");
        exit (-1);
    }

    for (int i = 0; i < IDENTIFICADOR_MAX; ++i) {
        aux->hash[i] = NULL;
    }

    aux->tamanio = tamanio;
    aux->ocupacion = 0;
    aux->cache = newLista();

    return aux;
}

Lista *newLista() {
    Lista * aux = malloc(sizeof(Lista));

    if (aux == NULL) {
        printf("Sin memoria");
        exit (-1);
    }

    aux->tamanio = 0;
    aux->cabecera = NULL;

    return aux;
}

void agregarElemento(Nodo *elemento, Lista *lista) {

    if( lista->cabecera != NULL ) {
        lista->cabecera->ant = elemento;
        elemento->sig = lista->cabecera;
    }
    lista->cabecera = elemento;

}

void imprimirLista(Lista * lista) {
    Nodo * aux = lista->cabecera;
    printf("Lista: \n");
    for (; aux != NULL; aux = aux->sig) {
        printf(" %d", aux->idenficador);
    }
    printf("\n");
}

Nodo *solicitarElemento(int identificador, Lista *lista, Cache *cache) {
    Nodo * elemento = NULL;

    if (cache->hash[identificador] != NULL) {
        //el elemento esta en la lista! Camino corto
        elemento = cache->hash[identificador];
        desasociarElemento(elemento);
        agregarElementoEnCache(elemento, cache);//este me suma a la ocupacion pero no tengo q sumar en este caso
        cache->ocupacion--;

    } else {
        //el elemento no esta en la lista! Camino largoo
        elemento = encontrar(lista, identificador);
        if ( cache->ocupacion == cache->tamanio )
            hacerEspacioEnCache(cache);

        agregarElementoEnCache(elemento, cache);
    }

    return elemento;
}

void imprimirCache(Cache *cache) {
    imprimirLista(cache->cache);
}

void desasociarElemento(Nodo *elemento) {
    if(elemento->ant != NULL) elemento->ant->sig=elemento->sig;
    if(elemento->sig != NULL) elemento->sig->ant=elemento->ant;
    elemento->sig = NULL;
    elemento->ant=NULL;
}

Nodo * encontrar(Lista *lista, int identificador) {
    Nodo * aux = lista->cabecera;
    while (aux != NULL) {
        if (aux->idenficador == identificador)
            return aux;
        aux = aux->sig;
    }
    return NULL;
}

void agregarElementoEnCache(Nodo *elemento, Cache *cache) {
    agregarElemento(elemento, cache->cache);
    cache->hash[elemento->idenficador] = elemento;
    cache->ocupacion++;
}

void hacerEspacioEnCache(Cache *cache) {
    if (cache->cache->cabecera != NULL ) {
        Nodo * nodo = cache->cache->cabecera;

        while (nodo->sig != NULL) {
            nodo = nodo->sig;
        }

        desasociarElemento(nodo);
        cache->hash[nodo->idenficador] = NULL;
        cache->ocupacion--;
    }
}
