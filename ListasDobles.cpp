/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListasDobles.cpp
 * Author: luisGonzalez
 * 
 * Created on 23 de febrero de 2020, 03:22 PM
 */

#include "ListasDobles.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Cola.h";

ListasDobles::ListasDobles() {
    primero = NULL;
    ultimo = NULL;
}

void ListasDobles::Set_primero(Carta* P) {
    primero = P;
}

Carta* ListasDobles::Get_primero() {
    return primero;
}

void ListasDobles::Set_ultimo(Carta* U) {
    ultimo = U;
}

Carta* ListasDobles::Get_ultimo() {
    return ultimo;
}

void ListasDobles::insertarCarta(Carta *&primero, Carta *&ultimo, int id, int numero, string simbolo, string dato, string bandera) {
    Carta* carta = new Carta();
    carta->Set_id(id);
    carta->Set_numero(numero);
    carta->Set_simbolo(simbolo);
    carta->Set_dato(dato);
    carta->Set_bandera(bandera);
    if (primero == NULL) {
        primero = carta;
        primero->Set_siguiente(NULL);
        primero->Set_anterior(NULL);
        ultimo = primero;
    } else {
        ultimo->Set_siguiente(carta);
        carta->Set_siguiente(NULL);
        carta->Set_anterior(ultimo);
        ultimo = carta;
    }
}

void ListasDobles::desplegarListaPU(Carta *&primero, int i) {
    Carta* actual = new Carta();
    actual = primero;
    if (primero != NULL) {
        while (actual != NULL) {
            int espacio;
            espacio = i * 10;
            for (int j = 0; j < espacio; j++) {
                printf(" ");
            }
            cout << actual->Get_dato() << endl;
            actual = actual->Get_siguiente();
        }
    } else {
        cout << "La lista se encuentra vacia\n\n" << endl;
    }
}

Carta* ListasDobles::mostrarCartas(Carta *&primero, Carta *&ultimo, Carta *actual, int i, int j) {
    int espacio;
    if (primero != NULL) {
        ultimo->Set_bandera("SI");
        if (actual != NULL) {
            espacio = i * 3;
            for (int j = 0; j < espacio; j++) {
                printf(" ");
            }
            if (actual->Get_numero() == 10) {
                if (actual->Get_bandera() == "SI") {
                    cout << actual->Get_dato();
                } else {
                    cout << "xxx ";
                }
            } else {
                if (actual->Get_bandera() == "SI") {
                    cout << actual->Get_dato() << " ";
                } else {
                    cout << "xxx ";
                }
            }
            actual = actual->Get_siguiente();
        } else {
            espacio = i * 3;
            for (int j = 0; j < espacio; j++) {
                printf(" ");
            }
            cout << "    ";
        }
    } else if (primero == NULL) {
        actual = NULL;
        espacio = i * 3;
        for (int j = 0; j < espacio; j++) {
            printf(" ");
        }
        cout << "    ";

    }
    return actual;
}

void ListasDobles::despleagarListaUP(Carta *&primero, Carta*&ultimo) {
    Carta* actual = new Carta();
    actual = ultimo;
    if (primero != NULL) {
        while (actual != NULL) {
            cout << actual->Get_id() << " , " << actual->Get_numero() << " , " << actual->Get_simbolo() << "\n" << endl;
            actual = actual->Get_anterior();
        }
    } else {
        cout << "La lista se encuentra vacia\n\n" << endl;
    }
}

ListasDobles::ListasDobles(const ListasDobles& orig) {
}

ListasDobles::~ListasDobles() {
    /*Carta *aux = new Carta();
    Carta *aux2 = NULL;
    aux = ultimo;
    if (primero == ultimo) {
        primero = ultimo = NULL;
    } else {
        while (primero != NULL) {
            aux2 = aux;
            ultimo = ultimo->Get_anterior();
            ultimo->Set_siguiente(NULL);
            delete aux2;

        }
    }*/
    while(primero->Get_siguiente() != ultimo){
        Carta *aux = primero->Get_siguiente()->Get_siguiente();
        delete primero->Get_siguiente();
        primero->Set_siguiente(aux);
        aux->Set_anterior(primero);
    }
    delete primero;
    delete ultimo;
    
}

