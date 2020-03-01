/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BarajaInicial.cpp
 * Author: luisGonzalez
 * 
 * Created on 22 de febrero de 2020, 04:00 PM
 */

#include "BarajaInicial.h"

BarajaInicial::BarajaInicial() {
    Cabeza = NULL;
}

void BarajaInicial::Set_cabeza(Carta *C){
    Cabeza = C;
}

Carta* BarajaInicial::Get_cabeza(){
    return Cabeza;
}

Carta* BarajaInicial::Get_ultimo(){
    Carta *ultimo = Get_cabeza();
    while(ultimo->Get_siguiente()!=NULL){
        ultimo=ultimo->Get_siguiente();
    }
    return ultimo;
}

void BarajaInicial::Agregar(Carta *Nuevo){
    if(Get_cabeza()==NULL){
        Set_cabeza(Nuevo);
    } else {
        Get_ultimo()->Set_siguiente(Nuevo);
    }
}

Carta* BarajaInicial::Buscar(int id){
    Carta *busqueda = Get_cabeza();
    while((busqueda!=NULL)and(busqueda->Get_id()!=id)){
        busqueda = busqueda->Get_siguiente();
    }
    return busqueda;
}

void BarajaInicial::Eliminar(int id){
    Carta *busqueda = Get_cabeza();
    Carta *anterior = NULL;
    if(busqueda->Get_id()==id){
        Set_cabeza(Get_cabeza()->Get_siguiente());
    } else {
        while((busqueda!=NULL)and(busqueda->Get_id()!=id)){
            anterior=busqueda;
            busqueda=busqueda->Get_siguiente();
        }
        if(busqueda!=NULL){
            anterior->Set_siguiente(busqueda->Get_siguiente());
        }
    }
    delete busqueda;
}

BarajaInicial::BarajaInicial(const BarajaInicial& orig) {
}

BarajaInicial::~BarajaInicial() {
}

