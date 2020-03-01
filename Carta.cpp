
/* 
 * File:   Carta.cpp
 * Author: luisGonzalez
 * 
 * Created on 22 de febrero de 2020, 04:00 PM
 */

#include "Carta.h"

Carta::Carta() {
    id = 0;
    numero = 0;
    color = " ";
    simbolo = " ";
    dato = " "; 
    bandera = " ";
    siguiente = NULL;
    anterior = NULL;
}

void Carta::Set_id(int I){
    id = I;
}

void Carta::Set_numero(int N){
    numero = N;
}

void Carta::Set_simbolo(string S){
    simbolo = S;
}

void Carta::Set_color(string C){
    color = C;
}

void Carta::Set_siguiente(Carta* S){
    siguiente = S;
}

void Carta::Set_bandera(string B){
    bandera = B;
}

void Carta::Set_dato(string D){
    dato = D;
}

string Carta::Get_dato(){
    return dato;
}

int Carta::Get_id(){
    return id;
}

int Carta::Get_numero(){
    return numero;
}

string Carta::Get_color(){
    return color;
}

string Carta::Get_simbolo(){
    return simbolo;
}

string Carta::Get_bandera(){
    return bandera;
}

Carta* Carta::Get_siguiente(){
    return siguiente;
}

void Carta::Set_anterior(Carta* A){
    anterior = A;
}

Carta* Carta::Get_anterior(){
    return anterior;
}

Carta::Carta(const Carta& orig) {
}

Carta::~Carta() {
}

