/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pilas.cpp
 * Author: luisGonzalez
 * 
 * Created on 23 de febrero de 2020, 02:43 PM
 */

#include "Pilas.h"

Pilas::Pilas() {
    pila = NULL;
}

void Pilas::Set_pila(Carta* P){
    pila = P;
}

Carta* Pilas::Get_pila(){
    return pila;
}

void Pilas::Agregar(Carta *&pila, int id, int numero, string simbolo, string dato, string bandera){
    Carta *carta = new Carta();
    carta->Set_id(id);
    carta->Set_numero(numero);
    carta->Set_simbolo(simbolo);
    carta->Set_dato(dato);
    carta->Set_bandera(bandera);
    carta->Set_siguiente(pila);
    pila = carta;
}

void Pilas::Quitar(Carta *&pila){
    Carta *aux = pila;
    pila = aux->Get_siguiente();
    delete aux;
}


Pilas::Pilas(const Pilas& orig) {
}

Pilas::~Pilas() {
    Carta *aux = new Carta();
    Carta *aux2 = NULL;
    aux = pila;
    while(aux != NULL){
        aux2 = aux;
        aux = aux->Get_siguiente();
        delete aux2;
    }
}

