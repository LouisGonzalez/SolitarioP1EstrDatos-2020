/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CartasPantalla.h
 * Author: luisGonzalez
 *
 * Created on 27 de febrero de 2020, 10:42 AM
 */

#ifndef CARTASPANTALLA_H
#define CARTASPANTALLA_H
#include "Carta.h"
#include "BarajaInicial.h"
#include "ListasDobles.h"

using namespace std;


class CartasPantalla {
public:
    CartasPantalla();
    CartasPantalla(const CartasPantalla& orig);
    virtual ~CartasPantalla();
    void mostrarTablero1(Carta*&, Carta*&, Carta*, int);
    void mostrarTablero2(Carta*&, Carta*&, Carta*, int);
    void espacios();
    void agregarCartasListas(int, Carta*&, Carta*&, BarajaInicial*, ListasDobles*);
    void mostrarPilasFinales(Carta*&);
private:

};

#endif /* CARTASPANTALLA_H */

