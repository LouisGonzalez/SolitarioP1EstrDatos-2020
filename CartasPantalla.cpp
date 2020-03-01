/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CartasPantalla.cpp
 * Author: luisGonzalez
 * 
 * Created on 27 de febrero de 2020, 10:42 AM
 */

#include "CartasPantalla.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Cola.h";
#include "Carta.h"
#include "ListasDobles.h"
#include "BarajaInicial.h"

CartasPantalla::CartasPantalla() {
}

void CartasPantalla::mostrarTablero1(Carta *&frente, Carta *&fin, Carta *actual, int i) {
    int espacio;
    Carta *temp = new Carta();
    espacio = i * 3;
    for (int j = 0; j < espacio; j++) {
        printf(" ");
    }
    if (fin == NULL) {
        cout << "--- ";
    } else {
        temp = frente;
        while (temp != NULL) {
            if (temp == frente) {
                if (temp->Get_numero() > 9) {
                    cout << temp->Get_dato();
                } else {
                    cout << temp->Get_dato() << " ";
                }

            }
            temp = temp->Get_siguiente();
        }
    }
}

void CartasPantalla::mostrarTablero2(Carta *&frente, Carta *&fin, Carta *actual, int i) {
    int espacio;
    Carta *temp = new Carta();
    espacio = i * 3;
    for (int j = 0; j < espacio; j++) {
        printf(" ");
    }
    if (fin == NULL) {
        cout << "--- ";
    } else {
        temp = frente;
        while (temp != NULL) {
            if (temp == fin) {
                if (temp->Get_numero() > 9) {
                    cout << temp->Get_dato();
                } else {
                    cout << temp->Get_dato() << " ";
                }

            }
            temp = temp->Get_siguiente();
        }
    }
}

void CartasPantalla::espacios() {
    cout << "     ";
}

void CartasPantalla::mostrarPilasFinales(Carta *&pila) {
    Carta *temp = new Carta();
    if (pila != NULL) {
        temp = pila;
        while (temp != NULL) {
            if (temp == pila) {
                if (temp->Get_numero() > 9) {
                    cout << temp->Get_dato();
                } else {
                    cout << temp->Get_dato() + " ";
                }
            }
            temp = temp->Get_siguiente();
        }
    } else {
        cout << "--- ";
    }
}

void CartasPantalla::agregarCartasListas(int i, Carta *&primero, Carta *&ultimo, BarajaInicial *baraja, ListasDobles *lista) {
    int aleatorio;
    for (int j = 1; j <= i; j++) {
        Carta *temp2 = NULL;
        do {
            aleatorio = 1 + rand() % (53 - 1);
            temp2 = baraja->Buscar(aleatorio);
        } while (temp2 == NULL);
        lista->insertarCarta(primero, ultimo, temp2->Get_id(), temp2->Get_numero(), temp2->Get_simbolo(), temp2->Get_dato(), "NO");
        baraja->Eliminar(aleatorio);
    }

}

CartasPantalla::CartasPantalla(const CartasPantalla& orig) {
}

CartasPantalla::~CartasPantalla() {
}


