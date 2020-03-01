/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cola.h
 * Author: luisGonzalez
 *
 * Created on 22 de febrero de 2020, 06:29 PM
 */

#ifndef COLA_H
#define COLA_H
#include "Carta.h"

using namespace std;

class Cola {
public:
    Cola();
    
    void Set_frente(Carta*);
    Carta* Get_frente();
    void Set_fin(Carta*);
    Carta* Get_fin();
    void Agregar(Carta*&, Carta*&, int, int, string, string);
    bool Cola_vacia(Carta*);
    void Suprimir_cola(Carta*&, Carta*&);
    void Suprimir_cola_final(Carta*&, Carta*&);

    Cola(const Cola& orig);
    virtual ~Cola();
private:
    Carta *frente;
    Carta *fin;

};

#endif /* COLA_H */

