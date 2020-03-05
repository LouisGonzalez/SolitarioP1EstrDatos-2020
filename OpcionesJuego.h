/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OpcionesJuego.h
 * Author: luisGonzalez
 *
 * Created on 27 de febrero de 2020, 10:56 PM
 */

#ifndef OPCIONESJUEGO_H
#define OPCIONESJUEGO_H
#include "Carta.h"
#include "Cola.h"
#include "ListasDobles.h"
#include "Pilas.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class OpcionesJuego {
public:
    OpcionesJuego();
    OpcionesJuego(const OpcionesJuego& orig);
    
    
    void cartasReserva(Carta*&, Carta*&, Carta*&, Carta*&, Cola*, Cola*);
    void rellenoCola(Carta*&, Carta*&, Carta*&, Carta*&, Cola*);
    void deReservaAMesa(Carta*&, Carta*&, Carta*&, Carta*&, ListasDobles*);
    void moverColumnaAColumna(Carta*&, Carta*&, Carta*&, Carta*&, int, Pilas*, Carta*&, ListasDobles*);
    void movimientoColumnas(Carta*&, Carta*&, Carta*&, Carta*&, int, bool, Pilas*, Carta*&, ListasDobles*);
    void moverColumnaAPFinal(Carta*&, Carta*&, Carta*&, Pilas*);
    void moverPFinalAColumna(Carta*&, Carta*&, Carta*&, ListasDobles*, Pilas*);
    void obtenerAnteriorSiguiente(Carta*&, Carta*&, char);
    void obtenerSiguienteCola(Carta*&, Carta*&);
    void obtenerSiguienteCola2(Carta*&, Carta*&);
    
    virtual ~OpcionesJuego();
private:

};

#endif /* OPCIONESJUEGO_H */

