/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cola.cpp
 * Author: luisGonzalez
 * 
 * Created on 22 de febrero de 2020, 06:29 PM
 */

#include "Cola.h"

Cola::Cola() {
    frente = NULL;
    fin = NULL;
}

void Cola::Set_frente(Carta *F){
    frente = F;
}

void Cola::Set_fin(Carta* F){
    fin = F;
}

Carta* Cola::Get_frente(){
    return frente;
}

Carta* Cola::Get_fin(){
    return fin;
}

void Cola::Agregar(Carta *&frente, Carta *&fin, int id, int numero, string simbolo, string dato){
    Carta *carta = new Carta();
    carta->Set_id(id);
    carta->Set_numero(numero);
    carta->Set_simbolo(simbolo);
    carta->Set_dato(dato);
    carta->Set_siguiente(NULL);
    if(Cola::Cola_vacia(frente)){
        frente = carta;
        carta->Set_anterior(NULL);
    } else {
   
        fin->Set_siguiente(carta);
         carta->Set_anterior(fin);
    }
    fin = carta;
    
}

bool Cola::Cola_vacia(Carta *frente){
    return (frente == NULL)? true : false;
}

void Cola::Suprimir_cola(Carta *&frente, Carta *&fin){
    Carta *aux = frente;
    if(frente==fin){
        frente == NULL;
        fin == NULL;
    } else {
        frente = frente->Get_siguiente();
    }
    delete aux;
}

void Cola::Suprimir_cola_final(Carta *&frente, Carta *&fin){
    Carta *aux = fin;
    if(frente == fin){
        frente == NULL;
        fin == NULL;
    } else {
        fin = fin->Get_anterior();
    }
    delete aux;
}







Cola::Cola(const Cola& orig) {
}

Cola::~Cola() {
}

