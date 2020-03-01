/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListasDobles.h
 * Author: luisGonzalez
 *
 * Created on 23 de febrero de 2020, 03:21 PM
 */

#ifndef LISTASDOBLES_H
#define LISTASDOBLES_H
#include "Carta.h"
#include "Cola.h"

using namespace std;

class ListasDobles {
public:
    ListasDobles();
    
    void Set_primero(Carta*);
    Carta* Get_primero();
    void Set_ultimo(Carta*);
    Carta* Get_ultimo();
    void insertarCarta(Carta*&,Carta*&, int, int, string, string, string);
    void desplegarListaPU(Carta*&, int);
    Carta* mostrarCartas(Carta*&, Carta*&, Carta*, int, int);
    void despleagarListaUP(Carta*&, Carta*&);
    
    ListasDobles(const ListasDobles& orig);
    virtual ~ListasDobles();
private:
    Carta *primero;
    Carta *ultimo;
};

#endif /* LISTASDOBLES_H */

