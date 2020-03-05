/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: luisGonzalez
 *
 * Created on 22 de febrero de 2020, 03:58 PM
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "Carta.h"
#include "BarajaInicial.h"
#include "Cola.h"
#include "ListasDobles.h"
#include "Pilas.h"
#include "CartasPantalla.h"
#include "OpcionesJuego.h"

using namespace std;

/*
 * 
 */

void AgregarCartas(Carta*&, Carta*&, int, int, string);

int main() {
    Carta *aux = NULL, *temp = NULL, *temp2 = NULL;
    BarajaInicial *baraja = new BarajaInicial();
    Cola *cola = new Cola();
    Cola *colaSecundaria = new Cola();
    CartasPantalla *mostrar = new CartasPantalla();
    OpcionesJuego *opciones = new OpcionesJuego();
    ListasDobles *lista1 = new ListasDobles();
    ListasDobles *lista2 = new ListasDobles();
    ListasDobles *lista3 = new ListasDobles();
    ListasDobles *lista4 = new ListasDobles();
    ListasDobles *lista5 = new ListasDobles();
    ListasDobles *lista6 = new ListasDobles();
    ListasDobles *lista7 = new ListasDobles();
    Pilas *pilaPicas = new Pilas();
    Pilas *pilaDiamantes = new Pilas();
    Pilas *pilaTreboles = new Pilas();
    Pilas *pilaCorazones = new Pilas();
    Pilas *pilaAuxiliar = new Pilas();
    Carta *frenteAuxiliar = NULL;
    Carta *pila1 = NULL, *pila2 = NULL, *pila3 = NULL, * pila4 = NULL;
    Carta *primero1 = NULL, *primero2 = NULL, *primero3 = NULL, *primero4 = NULL, *primero5 = NULL, *primero6 = NULL, *primero7 = NULL;
    Carta *ultimo1 = NULL, *ultimo2 = NULL, *ultimo3 = NULL, *ultimo4 = NULL, *ultimo5 = NULL, *ultimo6 = NULL, *ultimo7 = NULL;
    Carta *pila = NULL, *frente = NULL, *fin = NULL;
    Carta *frente2 = NULL, *fin2 = NULL;
    srand(time(NULL));
    int aleatorio;
    char opcionesMenu;
    int x = 1;
    for (int i = 1; i <= 52; i++) {
        stringstream ss;
        string convertido;
        if (i > 13 * x) {
            x++;
        }
        aux = new Carta();
        aux->Set_id(i);
        if (x == 1) {
            aux->Set_numero(i);
            ss << i;
            ss>>convertido;
            if(convertido == "1"){
                aux->Set_dato("A ♠");
                
            } else if(convertido == "11"){
                aux->Set_dato("J ♠");
            
            } else if(convertido == "12"){
                aux->Set_dato("Q ♠");
            
            } else if(convertido ==  "13"){
                aux->Set_dato("K ♠");
            
            } else {
                aux->Set_dato(convertido + " ♠");
            }
            aux->Set_simbolo("Pica");
        } else if (x == 2) {
            aux->Set_numero(i - 13);
            ss << i - 13;
            ss>>convertido;
            if(convertido == "1"){
                aux->Set_dato("A ♥");
                
            } else if(convertido ==  "11"){
                aux->Set_dato("J ♥");
            
            } else if(convertido == "12"){
                aux->Set_dato("Q ♥");
            
            } else if(convertido == "13"){
                aux->Set_dato("K ♥");
            
            } else {
                aux->Set_dato(convertido + " ♥");
            }
            aux->Set_simbolo("Corazon");
        } else if (x == 3) {
            aux->Set_numero(i - 26);
            ss << i - 26;
            ss>>convertido;
            if(convertido == "1"){
                aux->Set_dato("A ♦");
                
            } else if(convertido == "11"){
                aux->Set_dato("J ♦");
            
            } else if(convertido ==  "12"){
                aux->Set_dato("Q ♦");
            
            } else if(convertido == "13"){
                aux->Set_dato("K ♦");
            
            } else {
                aux->Set_dato(convertido + " ♦");
            }
            aux->Set_simbolo("Diamante");
        } else if (x == 4) {
            aux->Set_numero(i - 39);
            ss << i - 39;
            ss>>convertido;
            if(convertido == "1"){
                aux->Set_dato("A ♣");
                
            } else if(convertido == "11"){
                aux->Set_dato("J ♣");
            
            } else if(convertido ==  "12"){
                aux->Set_dato("Q ♣");
            
            } else if(convertido == "13"){
                aux->Set_dato("K ♣");
            
            } else {
                aux->Set_dato(convertido + " ♣");
            }
            aux->Set_simbolo("Trebol");
        }
        baraja->Agregar(aux);
    }
    //AGREGA LAS 24 CARTAS INICIALES A LA COLA 1
    for (int i = 1; i <= 24; i++) {
        Carta *temp2 = NULL;
        do {
            aleatorio = 1 + rand() % (53 - 1);
            temp2 = baraja->Buscar(aleatorio);
        } while (temp2 == NULL);
        // cout<<aleatorio<<" , "<<temp2->Get_id()<<endl;
        cola->Agregar(frente, fin, temp2->Get_id(), temp2->Get_numero(), temp2->Get_simbolo(), temp2->Get_dato());
        baraja->Eliminar(aleatorio);
    }
    //AGREGA EL RESTO DE CARTAS A LAS LISTAS DOBLES 
    //LLENA LA LISTA 1
    mostrar->agregarCartasListas(1, primero1, ultimo1, baraja, lista1);
    //LLENA LA LISTA 2
    mostrar->agregarCartasListas(2, primero2, ultimo2, baraja, lista2);
    //LLENA LA LISTA 3
    mostrar->agregarCartasListas(3, primero3, ultimo3, baraja, lista3);
    //LLENA LA LISTA 4
    mostrar->agregarCartasListas(4, primero4, ultimo4, baraja, lista4);
    //LLENA LA LISTA 5
    mostrar->agregarCartasListas(5, primero5, ultimo5, baraja, lista5);
    //LLENA LA LISTA 6
    mostrar->agregarCartasListas(6, primero6, ultimo6, baraja, lista6);
    //LLENA LA LISTA 7
    mostrar->agregarCartasListas(7, primero7, ultimo7, baraja, lista7);
    int jugadas = 0;
    while (primero1 != NULL || primero2 != NULL || primero3 != NULL || primero4 != NULL || primero5 != NULL || primero6 != NULL || primero7 != NULL) {
        Carta* actual1 = primero1;
        Carta* actual2 = primero2;
        Carta* actual3 = primero3;
        Carta* actual4 = primero4;
        Carta* actual5 = primero5;
        Carta* actual6 = primero6;
        Carta* actual7 = primero7;
        Carta* cola24 = new Carta();
        cola24 = frente;
        Carta* cola2 = new Carta();
        cola2 = frente2;
        for (int i = 0; i < 9; i++) {
            switch (i) {
                case 0:
                    mostrar->mostrarTablero1(frente, fin, cola24, i);
                    break;
                case 1:
                    mostrar->mostrarTablero2(frente2, fin2, cola2, i);
                    break;
                case 2:
                    mostrar->espacios();
                    break;
                case 3:
                    mostrar->espacios();
                    break;
                case 4:
                    mostrar->espacios();
                    break;
                case 5:
                    mostrar->mostrarPilasFinales(pila1);
                    break;
                case 6:
                    mostrar->mostrarPilasFinales(pila2);
                    break;
                case 7:
                    mostrar->mostrarPilasFinales(pila3);
                    break;
                case 8:
                    mostrar->mostrarPilasFinales(pila4);
                    break;
            }
        }
        printf("\n\n");
        cout << "1.     2.        3.           4.              5.                 6.                    7." << endl;
        printf("\n");
        for (int j = 0; j < 19; j++) {
            for (int i = 0; i < 7; i++) {
                switch (i) {
                    case 0:
                        actual1 = lista1->mostrarCartas(primero1, ultimo1, actual1, i, j);
                        break;
                    case 1:
                        actual2 = lista2->mostrarCartas(primero2, ultimo2, actual2, i, j);
                        break;
                    case 2:
                        actual3 = lista3->mostrarCartas(primero3, ultimo3, actual3, i, j);
                        break;
                    case 3:
                        actual4 = lista4->mostrarCartas(primero4, ultimo4, actual4, i, j);
                        break;
                    case 4:
                        actual5 = lista5->mostrarCartas(primero5, ultimo5, actual5, i, j);
                        break;
                    case 5:
                        actual6 = lista6->mostrarCartas(primero6, ultimo6, actual6, i, j);
                        break;
                    case 6:
                        actual7 = lista7->mostrarCartas(primero7, ultimo7, actual7, i, j);
                        break;
                }
            }
            printf("\n");
        }
        cout << "Jugadas: " << jugadas << endl;
        printf("\n");
        cout << "Seleccione cualquiera de los siguientes movimientos: " << endl;
        cout << "1.Jalar una carta de la mano de reserva." << endl;
        cout << "2.Usar carta de la mano de reserva." << endl;
        cout << "3.Mover de una columna a otra." << endl;
        cout << "4.Mover de una columna a alguna de las columnas finales." << endl;
        cout << "5.Mover de una columna final a alguna columna del juego." << endl;
        cout << "6. Saber el siguiente o anterior de alguna carta del juego." << endl;
        cout << "7. Rendirse." << endl;
        cin>>opcionesMenu;
        switch (opcionesMenu) {
            case '1':
                if (fin == NULL) {
                    opciones->rellenoCola(frente, fin, frente2, fin2, colaSecundaria);
                } else {
                    opciones->cartasReserva(frente, fin, frente2, fin2, cola, colaSecundaria);
                }
                break;
            case '2':
                char noPila;
                cout << "A que pila desea mover la carta?" << endl;
                cin>>noPila;
                switch (noPila) {
                    case '1':
                        opciones->deReservaAMesa(frente2, fin2, primero1, ultimo1, lista1);
                        break;
                    case '2':
                        opciones->deReservaAMesa(frente2, fin2, primero2, ultimo2, lista2);
                        break;
                    case '3':
                        opciones->deReservaAMesa(frente2, fin2, primero3, ultimo3, lista3);
                        break;
                    case '4':
                        opciones->deReservaAMesa(frente2, fin2, primero4, ultimo4, lista4);
                        break;
                    case '5':
                        opciones->deReservaAMesa(frente2, fin2, primero5, ultimo5, lista5);
                        break;
                    case '6':
                        opciones->deReservaAMesa(frente2, fin2, primero6, ultimo6, lista6);
                        break;
                    case '7':
                        opciones->deReservaAMesa(frente2, fin2, primero7, ultimo7, lista7);
                        break;
                    default:
                        cout << "Has ingresado una opcion invalida" << endl;
                        jugadas--;
                        break;
                }
                break;
            case '3':
                int noCartas;
                char columnaQuitar, columnaPoner;
                ListasDobles *auxL, *auxL2;
                Carta *auxPrimero, *auxUltimo, *auxPrimero2, *auxUltimo2;
                cout << "No. de columna donde desea mover: " << endl;
                cin>>columnaQuitar;
                cout << "No. de cartas que desea mover: " << endl;
                cin>>noCartas;
                cout << "No. de columna donde desea agregar: " << endl;
                cin>>columnaPoner;
                if (columnaPoner != columnaQuitar) {
                    switch (columnaQuitar) {
                        case '1':
                            switch (columnaPoner) {
                                case '1':
                                    opciones->moverColumnaAColumna(primero1, ultimo1, primero1, ultimo1, noCartas, pilaAuxiliar, frenteAuxiliar, lista1);
                                    break;
                                case '2':
                                    opciones->moverColumnaAColumna(primero1, ultimo1, primero2, ultimo2, noCartas, pilaAuxiliar, frenteAuxiliar, lista2);
                                    break;
                                case '3':
                                    opciones->moverColumnaAColumna(primero1, ultimo1, primero3, ultimo3, noCartas, pilaAuxiliar, frenteAuxiliar, lista3);
                                    break;
                                case '4':
                                    opciones->moverColumnaAColumna(primero1, ultimo1, primero4, ultimo4, noCartas, pilaAuxiliar, frenteAuxiliar, lista4);
                                    break;
                                case '5':
                                    opciones->moverColumnaAColumna(primero1, ultimo1, primero5, ultimo5, noCartas, pilaAuxiliar, frenteAuxiliar, lista5);
                                    break;
                                case '6':
                                    opciones->moverColumnaAColumna(primero1, ultimo1, primero6, ultimo6, noCartas, pilaAuxiliar, frenteAuxiliar, lista6);
                                    break;
                                case '7':
                                    opciones->moverColumnaAColumna(primero1, ultimo1, primero7, ultimo7, noCartas, pilaAuxiliar, frenteAuxiliar, lista7);
                                    break;
                                default:
                                    cout << "Has ingresado una opcion invalida." << endl;
                                    jugadas--;
                                    break;
                            }
                            break;
                        case '2':
                            switch (columnaPoner) {
                                case '1':
                                    opciones->moverColumnaAColumna(primero2, ultimo2, primero1, ultimo1, noCartas, pilaAuxiliar, frenteAuxiliar, lista1);
                                    break;
                                case '2':
                                    opciones->moverColumnaAColumna(primero2, ultimo2, primero2, ultimo2, noCartas, pilaAuxiliar, frenteAuxiliar, lista2);
                                    break;
                                case '3':
                                    opciones->moverColumnaAColumna(primero2, ultimo2, primero3, ultimo3, noCartas, pilaAuxiliar, frenteAuxiliar, lista3);
                                    break;
                                case '4':
                                    opciones->moverColumnaAColumna(primero2, ultimo2, primero4, ultimo4, noCartas, pilaAuxiliar, frenteAuxiliar, lista4);
                                    break;
                                case '5':
                                    opciones->moverColumnaAColumna(primero2, ultimo2, primero5, ultimo5, noCartas, pilaAuxiliar, frenteAuxiliar, lista5);
                                    break;
                                case '6':
                                    opciones->moverColumnaAColumna(primero2, ultimo2, primero6, ultimo6, noCartas, pilaAuxiliar, frenteAuxiliar, lista6);
                                    break;
                                case '7':
                                    opciones->moverColumnaAColumna(primero2, ultimo2, primero7, ultimo7, noCartas, pilaAuxiliar, frenteAuxiliar, lista7);
                                    break;
                                default:
                                    cout << "Has ingresado una opcion invalida." << endl;
                                    jugadas--;
                                    break;
                            }
                            break;
                        case '3':
                            switch (columnaPoner) {
                                case '1':
                                    opciones->moverColumnaAColumna(primero3, ultimo3, primero1, ultimo1, noCartas, pilaAuxiliar, frenteAuxiliar, lista1);

                                    break;
                                case '2':
                                    opciones->moverColumnaAColumna(primero3, ultimo3, primero2, ultimo2, noCartas, pilaAuxiliar, frenteAuxiliar, lista2);
                                    break;
                                case '3':
                                    opciones->moverColumnaAColumna(primero3, ultimo3, primero3, ultimo3, noCartas, pilaAuxiliar, frenteAuxiliar, lista3);
                                    break;
                                case '4':
                                    opciones->moverColumnaAColumna(primero3, ultimo3, primero4, ultimo4, noCartas, pilaAuxiliar, frenteAuxiliar, lista4);
                                    break;
                                case '5':
                                    opciones->moverColumnaAColumna(primero3, ultimo3, primero5, ultimo5, noCartas, pilaAuxiliar, frenteAuxiliar, lista5);
                                    break;
                                case '6':
                                    opciones->moverColumnaAColumna(primero3, ultimo3, primero6, ultimo6, noCartas, pilaAuxiliar, frenteAuxiliar, lista6);
                                    break;
                                case '7':
                                    opciones->moverColumnaAColumna(primero3, ultimo3, primero7, ultimo7, noCartas, pilaAuxiliar, frenteAuxiliar, lista7);
                                    break;
                                default:
                                    cout << "Has ingresado una opcion invalida." << endl;
                                    jugadas--;
                                    break;
                            }
                            break;
                        case '4':
                            switch (columnaPoner) {
                                case '1':
                                    opciones->moverColumnaAColumna(primero4, ultimo4, primero1, ultimo1, noCartas, pilaAuxiliar, frenteAuxiliar, lista1);
                                    break;
                                case '2':
                                    opciones->moverColumnaAColumna(primero4, ultimo4, primero2, ultimo2, noCartas, pilaAuxiliar, frenteAuxiliar, lista2);
                                    break;
                                case '3':
                                    opciones->moverColumnaAColumna(primero4, ultimo4, primero3, ultimo3, noCartas, pilaAuxiliar, frenteAuxiliar, lista3);
                                    break;
                                case '4':
                                    opciones->moverColumnaAColumna(primero4, ultimo4, primero4, ultimo4, noCartas, pilaAuxiliar, frenteAuxiliar, lista4);
                                    break;
                                case '5':
                                    opciones->moverColumnaAColumna(primero4, ultimo4, primero5, ultimo5, noCartas, pilaAuxiliar, frenteAuxiliar, lista5);
                                    break;
                                case '6':
                                    opciones->moverColumnaAColumna(primero4, ultimo4, primero6, ultimo6, noCartas, pilaAuxiliar, frenteAuxiliar, lista6);
                                    break;
                                case '7':
                                    opciones->moverColumnaAColumna(primero4, ultimo4, primero7, ultimo7, noCartas, pilaAuxiliar, frenteAuxiliar, lista7);
                                    break;
                                default:
                                    cout << "Has ingresado una opcion invalida." << endl;
                                    jugadas--;
                                    break;
                            }
                            break;
                        case '5':
                            switch (columnaPoner) {
                                case '1':
                                    opciones->moverColumnaAColumna(primero5, ultimo5, primero1, ultimo1, noCartas, pilaAuxiliar, frenteAuxiliar, lista1);
                                    break;
                                case '2':
                                    opciones->moverColumnaAColumna(primero5, ultimo5, primero2, ultimo2, noCartas, pilaAuxiliar, frenteAuxiliar, lista2);
                                    break;
                                case '3':
                                    opciones->moverColumnaAColumna(primero5, ultimo5, primero3, ultimo3, noCartas, pilaAuxiliar, frenteAuxiliar, lista3);
                                    break;
                                case '4':
                                    opciones->moverColumnaAColumna(primero5, ultimo5, primero4, ultimo4, noCartas, pilaAuxiliar, frenteAuxiliar, lista4);
                                    break;
                                case '5':
                                    opciones->moverColumnaAColumna(primero5, ultimo5, primero5, ultimo5, noCartas, pilaAuxiliar, frenteAuxiliar, lista5);
                                    break;
                                case '6':
                                    opciones->moverColumnaAColumna(primero5, ultimo5, primero6, ultimo6, noCartas, pilaAuxiliar, frenteAuxiliar, lista6);
                                    break;
                                case '7':
                                    opciones->moverColumnaAColumna(primero5, ultimo5, primero7, ultimo7, noCartas, pilaAuxiliar, frenteAuxiliar, lista7);
                                    break;
                                default:
                                    cout << "Has ingresado una opcion invalida." << endl;
                                    jugadas--;
                                    break;
                            }
                            break;
                        case '6':
                            switch (columnaPoner) {
                                case '1':
                                    opciones->moverColumnaAColumna(primero6, ultimo6, primero1, ultimo1, noCartas, pilaAuxiliar, frenteAuxiliar, lista1);
                                    break;
                                case '2':
                                    opciones->moverColumnaAColumna(primero6, ultimo6, primero2, ultimo2, noCartas, pilaAuxiliar, frenteAuxiliar, lista2);
                                    break;
                                case '3':
                                    opciones->moverColumnaAColumna(primero6, ultimo6, primero3, ultimo3, noCartas, pilaAuxiliar, frenteAuxiliar, lista3);
                                    break;
                                case '4':
                                    opciones->moverColumnaAColumna(primero6, ultimo6, primero4, ultimo4, noCartas, pilaAuxiliar, frenteAuxiliar, lista4);
                                    break;
                                case '5':
                                    opciones->moverColumnaAColumna(primero6, ultimo6, primero5, ultimo5, noCartas, pilaAuxiliar, frenteAuxiliar, lista5);
                                    break;
                                case '6':
                                    opciones->moverColumnaAColumna(primero6, ultimo6, primero6, ultimo6, noCartas, pilaAuxiliar, frenteAuxiliar, lista6);
                                    break;
                                case '7':
                                    opciones->moverColumnaAColumna(primero6, ultimo6, primero7, ultimo7, noCartas, pilaAuxiliar, frenteAuxiliar, lista7);
                                    break;
                                default:
                                    cout << "Has ingresado una opcion invalida." << endl;
                                    jugadas--;
                                    break;
                            }
                            break;
                        case '7':
                            switch (columnaPoner) {
                                case '1':
                                    opciones->moverColumnaAColumna(primero7, ultimo7, primero1, ultimo1, noCartas, pilaAuxiliar, frenteAuxiliar, lista1);
                                    break;
                                case '2':
                                    opciones->moverColumnaAColumna(primero7, ultimo7, primero2, ultimo2, noCartas, pilaAuxiliar, frenteAuxiliar, lista2);
                                    break;
                                case '3':
                                    opciones->moverColumnaAColumna(primero7, ultimo7, primero3, ultimo3, noCartas, pilaAuxiliar, frenteAuxiliar, lista3);
                                    break;
                                case '4':
                                    opciones->moverColumnaAColumna(primero7, ultimo7, primero4, ultimo4, noCartas, pilaAuxiliar, frenteAuxiliar, lista4);
                                    break;
                                case '5':
                                    opciones->moverColumnaAColumna(primero7, ultimo7, primero5, ultimo5, noCartas, pilaAuxiliar, frenteAuxiliar, lista5);
                                    break;
                                case '6':
                                    opciones->moverColumnaAColumna(primero7, ultimo7, primero6, ultimo6, noCartas, pilaAuxiliar, frenteAuxiliar, lista6);
                                    break;
                                case '7':
                                    opciones->moverColumnaAColumna(primero7, ultimo7, primero7, ultimo7, noCartas, pilaAuxiliar, frenteAuxiliar, lista7);
                                    break;
                                default:
                                    cout << "Has ingresado una opcion invalida." << endl;
                                    jugadas--;
                                    break;
                            }
                            break;
                        default:
                            cout << "Has ingresado una opcion invalida." << endl;
                            jugadas--;
                            break;
                    }
                } else {
                    cout << "No es posible mover cartas de una columna a si misma." << endl;
                    jugadas--;
                }

                break;
            case '4':
                char noColumna, noPilaFinal;
                cout << "Numero de columna donde desea mover su carta:" << endl;
                cin>>noColumna;
                cout << "Numero de pila donde desea trasladar la carta:" << endl;
                cin>>noPilaFinal;
                switch (noColumna) {
                    case '1':
                        switch (noPilaFinal) {
                            case '1':
                                opciones->moverColumnaAPFinal(primero1, ultimo1, pila1, pilaPicas);
                                break;
                            case '2':
                                opciones->moverColumnaAPFinal(primero1, ultimo1, pila2, pilaCorazones);
                                break;
                            case '3':
                                opciones->moverColumnaAPFinal(primero1, ultimo1, pila3, pilaDiamantes);
                                break;
                            case '4':
                                opciones->moverColumnaAPFinal(primero1, ultimo1, pila4, pilaTreboles);
                                break;
                            default:
                                cout << "Numero de pila invalido." << endl;
                                jugadas--;
                                break;
                        }
                        break;
                    case '2':
                        switch (noPilaFinal) {
                            case '1':
                                opciones->moverColumnaAPFinal(primero2, ultimo2, pila1, pilaPicas);
                                break;
                            case '2':
                                opciones->moverColumnaAPFinal(primero2, ultimo2, pila2, pilaCorazones);
                                break;
                            case '3':
                                opciones->moverColumnaAPFinal(primero2, ultimo2, pila3, pilaDiamantes);
                                break;
                            case '4':
                                opciones->moverColumnaAPFinal(primero2, ultimo2, pila4, pilaTreboles);
                                break;
                            default:
                                cout << "Numero de pila invalido." << endl;
                                jugadas--;
                                break;
                        }
                        break;
                    case '3':
                        switch (noPilaFinal) {
                            case '1':
                                opciones->moverColumnaAPFinal(primero3, ultimo3, pila1, pilaPicas);
                                break;
                            case '2':
                                opciones->moverColumnaAPFinal(primero3, ultimo3, pila2, pilaCorazones);
                                break;
                            case '3':
                                opciones->moverColumnaAPFinal(primero3, ultimo3, pila3, pilaDiamantes);
                                break;
                            case '4':
                                opciones->moverColumnaAPFinal(primero3, ultimo3, pila4, pilaTreboles);
                                break;
                            default:
                                cout << "Numero de pila invalido." << endl;
                                jugadas--;
                                break;
                        }
                        break;
                    case '4':
                        switch (noPilaFinal) {
                            case '1':
                                opciones->moverColumnaAPFinal(primero4, ultimo4, pila1, pilaPicas);
                                break;
                            case '2':
                                opciones->moverColumnaAPFinal(primero4, ultimo4, pila2, pilaCorazones);
                                break;
                            case '3':
                                opciones->moverColumnaAPFinal(primero4, ultimo4, pila3, pilaDiamantes);
                                break;
                            case '4':
                                opciones->moverColumnaAPFinal(primero4, ultimo4, pila4, pilaTreboles);
                                break;
                            default:
                                cout << "Numero de pila invalido." << endl;
                                jugadas--;
                                break;
                        }
                        break;
                    case '5':
                        switch (noPilaFinal) {
                            case '1':
                                opciones->moverColumnaAPFinal(primero5, ultimo5, pila1, pilaPicas);
                                break;
                            case '2':
                                opciones->moverColumnaAPFinal(primero5, ultimo5, pila2, pilaCorazones);

                                break;
                            case '3':
                                opciones->moverColumnaAPFinal(primero5, ultimo5, pila3, pilaDiamantes);

                                break;
                            case '4':
                                opciones->moverColumnaAPFinal(primero5, ultimo5, pila4, pilaTreboles);

                                break;
                            default:
                                cout << "Numero de pila invalido." << endl;
                                jugadas--;
                                break;
                        }
                        break;
                    case '6':
                        switch (noPilaFinal) {
                            case '1':
                                opciones->moverColumnaAPFinal(primero6, ultimo6, pila1, pilaPicas);
                                break;
                            case '2':
                                opciones->moverColumnaAPFinal(primero6, ultimo6, pila2, pilaCorazones);
                                break;
                            case '3':
                                opciones->moverColumnaAPFinal(primero6, ultimo6, pila3, pilaDiamantes);
                                break;
                            case '4':
                                opciones->moverColumnaAPFinal(primero6, ultimo6, pila4, pilaTreboles);
                                break;
                            default:
                                cout << "Numero de pila invalido." << endl;
                                jugadas--;
                                break;
                        }
                        break;
                    case '7':
                        switch (noPilaFinal) {
                            case '1':
                                opciones->moverColumnaAPFinal(primero7, ultimo7, pila1, pilaPicas);
                                break;
                            case '2':
                                opciones->moverColumnaAPFinal(primero7, ultimo7, pila2, pilaCorazones);
                                break;
                            case '3':
                                opciones->moverColumnaAPFinal(primero7, ultimo7, pila3, pilaDiamantes);
                                break;
                            case '4':
                                opciones->moverColumnaAPFinal(primero7, ultimo7, pila4, pilaTreboles);
                                break;
                            default:
                                cout << "Numero de pila invalido." << endl;
                                jugadas--;
                                break;
                        }
                        break;
                    default:
                        cout << "Numero de columna invalido." << endl;
                        jugadas--;
                        break;
                }
                break;
            case '5':
                char noPilaFinal2, noColumna2;
                cout << "No. de mazo final donde desea remover su carta:" << endl;
                cin>>noPilaFinal2;
                cout << "No. de columna a donde desea mover dicha carta:" << endl;
                cin>>noColumna2;
                switch (noPilaFinal2) {
                    case '1':
                        switch (noColumna2) {
                            case '1':
                                opciones->moverPFinalAColumna(primero1, ultimo1, pila1, lista1, pilaPicas);
                                break;
                            case '2':
                                opciones->moverPFinalAColumna(primero2, ultimo2, pila1, lista2, pilaPicas);

                                break;
                            case '3':
                                opciones->moverPFinalAColumna(primero3, ultimo3, pila1, lista3, pilaPicas);

                                break;
                            case '4':
                                opciones->moverPFinalAColumna(primero4, ultimo4, pila1, lista4, pilaPicas);

                                break;
                            case '5':
                                opciones->moverPFinalAColumna(primero5, ultimo5, pila1, lista5, pilaPicas);

                                break;
                            case '6':
                                opciones->moverPFinalAColumna(primero6, ultimo6, pila1, lista6, pilaPicas);

                                break;
                            case '7':
                                opciones->moverPFinalAColumna(primero7, ultimo7, pila1, lista7, pilaPicas);

                                break;
                            default:
                                cout << "Numero de columna invalido." << endl;
                                jugadas--;
                                break;
                        }
                        break;
                    case '2':
                        switch (noColumna2) {
                            case '1':
                                opciones->moverPFinalAColumna(primero1, ultimo1, pila2, lista1, pilaCorazones);
                                break;
                            case '2':
                                opciones->moverPFinalAColumna(primero2, ultimo2, pila2, lista2, pilaCorazones);

                                break;
                            case '3':
                                opciones->moverPFinalAColumna(primero3, ultimo3, pila2, lista3, pilaCorazones);

                                break;
                            case '4':
                                opciones->moverPFinalAColumna(primero4, ultimo4, pila2, lista4, pilaCorazones);

                                break;
                            case '5':
                                opciones->moverPFinalAColumna(primero5, ultimo5, pila2, lista5, pilaCorazones);

                                break;
                            case '6':
                                opciones->moverPFinalAColumna(primero6, ultimo6, pila2, lista6, pilaCorazones);

                                break;
                            case '7':
                                opciones->moverPFinalAColumna(primero7, ultimo7, pila2, lista7, pilaCorazones);

                                break;
                            default:
                                cout << "Numero de columna invalido." << endl;
                                jugadas--;
                                break;
                        }
                        break;
                    case '3':
                        switch (noColumna2) {
                            case '1':
                                opciones->moverPFinalAColumna(primero1, ultimo1, pila3, lista1, pilaDiamantes);
                                break;
                            case '2':
                                opciones->moverPFinalAColumna(primero2, ultimo2, pila3, lista2, pilaDiamantes);

                                break;
                            case '3':
                                opciones->moverPFinalAColumna(primero3, ultimo3, pila3, lista3, pilaDiamantes);

                                break;
                            case '4':
                                opciones->moverPFinalAColumna(primero4, ultimo4, pila3, lista4, pilaDiamantes);

                                break;
                            case '5':
                                opciones->moverPFinalAColumna(primero5, ultimo5, pila3, lista5, pilaDiamantes);

                                break;
                            case '6':
                                opciones->moverPFinalAColumna(primero6, ultimo6, pila3, lista6, pilaDiamantes);

                                break;
                            case '7':
                                opciones->moverPFinalAColumna(primero7, ultimo7, pila3, lista7, pilaDiamantes);

                                break;
                            default:
                                cout << "Numero de columna invalido." << endl;
                                jugadas--;
                                break;
                        }

                        break;
                    case '4':
                        switch (noColumna2) {
                            case '1':
                                opciones->moverPFinalAColumna(primero1, ultimo1, pila4, lista1, pilaTreboles);
                                break;
                            case '2':
                                opciones->moverPFinalAColumna(primero2, ultimo2, pila4, lista2, pilaTreboles);

                                break;
                            case '3':
                                opciones->moverPFinalAColumna(primero3, ultimo3, pila4, lista3, pilaTreboles);

                                break;
                            case '4':
                                opciones->moverPFinalAColumna(primero4, ultimo4, pila4, lista4, pilaTreboles);

                                break;
                            case '5':
                                opciones->moverPFinalAColumna(primero5, ultimo5, pila4, lista5, pilaTreboles);

                                break;
                            case '6':
                                opciones->moverPFinalAColumna(primero6, ultimo6, pila4, lista6, pilaTreboles);

                                break;
                            case '7':
                                opciones->moverPFinalAColumna(primero7, ultimo7, pila4, lista7, pilaTreboles);

                                break;
                            default:
                                cout << "Numero de columna invalido." << endl;
                                jugadas--;
                                break;
                        }
                        break;
                    default:
                        cout << "Numero de pila invalido." << endl;
                        jugadas--;
                        break;
                }
                break;
            case '6':
                char eleccion;
                cout << "Eliga donde desea hacer su revision: " << endl;
                cout << "1. Columnas del juego." << endl;
                cout << "2. Mazo de 24 cartas." << endl;
                cout << "3. 2do mazo de 24 cartas." << endl;
                cin>>eleccion;
                if (eleccion == '1') {
                    char columnaConsulta, cartaConsulta;
                    cout << "No. columna: " << endl;
                    cin>>columnaConsulta;
                    cout << "No. carta: " << endl;
                    cin>>cartaConsulta;
                    switch (columnaConsulta) {
                        case '1':
                            opciones->obtenerAnteriorSiguiente(primero1, ultimo1, cartaConsulta);
                            break;
                        case '2':
                            opciones->obtenerAnteriorSiguiente(primero2, ultimo2, cartaConsulta);

                            break;
                        case '3':
                            opciones->obtenerAnteriorSiguiente(primero3, ultimo3, cartaConsulta);

                            break;
                        case '4':
                            opciones->obtenerAnteriorSiguiente(primero4, ultimo4, cartaConsulta);

                            break;
                        case '5':
                            opciones->obtenerAnteriorSiguiente(primero5, ultimo5, cartaConsulta);

                            break;
                        case '6':
                            opciones->obtenerAnteriorSiguiente(primero6, ultimo6, cartaConsulta);

                            break;
                        case '7':
                            opciones->obtenerAnteriorSiguiente(primero7, ultimo7, cartaConsulta);
                            break;
                    }
                } else if (eleccion == '2') {
                    opciones->obtenerSiguienteCola(frente, fin);
                } else if (eleccion == '3'){
                    opciones->obtenerSiguienteCola2(frente2, fin2);
                }
                break;
            case '7':
                pilaPicas->~Pilas();
                pilaDiamantes->~Pilas();
                pilaTreboles->~Pilas();
                pilaCorazones->~Pilas();
                cout << "Juego finalizado, has realizado un total de " << jugadas << " movimientos" << endl;
                lista1->~ListasDobles();
                lista2->~ListasDobles();
                lista3->~ListasDobles();
                lista4->~ListasDobles();
                lista5->~ListasDobles();
                lista6->~ListasDobles();
                lista7->~ListasDobles();
                break;
            default:
                cout << "Opcion invalida, porfavor intente denuevo" << endl;
                jugadas--;
        }
        jugadas++;
        system("sleep 2");
        system("clear");
    }
    cout << "Juego finalizado, has ganado con " << jugadas << " movimientos" << endl;
    pilaPicas->~Pilas();
    pilaDiamantes->~Pilas();
    pilaTreboles->~Pilas();
    pilaCorazones->~Pilas();
    lista1->~ListasDobles();
    lista2->~ListasDobles();
    lista3->~ListasDobles();
    lista4->~ListasDobles();
    lista5->~ListasDobles();
    lista6->~ListasDobles();
    lista7->~ListasDobles();
    return 0;
}





