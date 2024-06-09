//
// Created by eferraris on 31/05/24.
//

#ifndef INC_20240531_LRU_H
#define INC_20240531_LRU_H

#include <stdbool.h>

#define IDENTIFICADOR_MAX 150

typedef struct nodo {
    int idenficador;
    struct nodo * sig;
    struct nodo * ant;
} Nodo;

typedef struct lista {
    int tamanio;
    Nodo * cabecera;
} Lista;

typedef struct cache {
    int tamanio;
    int ocupacion;
    Lista * cache;
    Nodo * hash[IDENTIFICADOR_MAX];
} Cache;

Nodo * newNodo(int identificador);
Cache * newCache(int tamanio);
Lista * newLista();
void imprimirLista(Lista * lista);
void desasociarElemento(Nodo * elemento);
Nodo * encontrar(Lista * lista, int identificador);
void imprimirCache(Cache * cache);
Nodo * solicitarElemento(int identificador, Lista * lista, Cache * cache);
void agregarElemento(Nodo * elemento, Lista * lista);
void agregarElementoEnCache(Nodo * elemento, Cache * cache);
void hacerEspacioEnCache(Cache * cache);


#endif //INC_20240531_LRU_H
