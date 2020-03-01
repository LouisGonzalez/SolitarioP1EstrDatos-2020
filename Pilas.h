/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pilas.h
 * Author: luisGonzalez
 *
 * Created on 23 de febrero de 2020, 02:43 PM
 */

#ifndef PILAS_H
#define PILAS_H
#include "Carta.h"

using namespace std;

class Pilas {
public:
    Pilas();
    void Set_pila(Carta*);
    Carta* Get_pila();
    void Agregar(Carta*&, int, int, string, string, string);
    void Quitar(Carta*&);
    
    Pilas(const Pilas& orig);
    virtual ~Pilas();
private:
    Carta *pila;
};

#endif /* PILAS_H */

