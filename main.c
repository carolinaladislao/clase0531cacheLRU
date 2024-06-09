#include <stdio.h>
#include "lru.h"

int main(void) {
    Lista *lista = newLista();
    /*
    Cache * cache = newCache(4);
    agregarElemento(newNodo(20),lista);
    agregarElemento(newNodo(34),lista);
    agregarElemento(newNodo(30),lista);

    solicitarElemento(30,lista,cache);
    solicitarElemento(20,lista,cache);

    imprimirLista(lista);
    imprimirCache(cache);*/


    agregarElemento(newNodo(30), lista);
    agregarElemento(newNodo(40), lista);
    agregarElemento(newNodo(5), lista);
    agregarElemento(newNodo(10), lista);
    agregarElemento(newNodo(20), lista);
    agregarElemento(newNodo(90), lista);
    agregarElemento(newNodo(110), lista);
    agregarElemento(newNodo(100), lista);


    imprimirLista(lista);

    Cache *cache = newCache(5);

    solicitarElemento(30, lista, cache);
    solicitarElemento(40, lista, cache);
    solicitarElemento(5, lista, cache);

    imprimirCache(cache); // 5 40 30

    solicitarElemento(90, lista, cache); // 90 5 40 30
    solicitarElemento(40, lista, cache); // 40 90 5 30
    solicitarElemento(110, lista, cache); // 110 40 90 5 30

    imprimirCache(cache); // 110 40 90 5 30

    solicitarElemento(30, lista, cache); // 30 110 40 90 5
    solicitarElemento(100, lista, cache); // 120 30 110 40 90

    imprimirCache(cache); // 120 30 110 40 90
    printf("La lista es:");
    imprimirLista(lista);

    solicitarElemento(10, lista, cache);
    imprimirCache(cache);//

    return 0;
}
