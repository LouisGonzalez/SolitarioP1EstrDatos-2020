/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OpcionesJuego.cpp
 * Author: luisGonzalez
 * 
 * Created on 27 de febrero de 2020, 10:56 PM
 */
#include "OpcionesJuego.h"
#include "Cola.h"
#include "ListasDobles.h"
#include "Pilas.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

OpcionesJuego::OpcionesJuego() {
}

void OpcionesJuego::cartasReserva(Carta *&frente, Carta *&fin, Carta *&frente2, Carta *&fin2, Cola *cola1, Cola *cola2) {
    int id, numero;
    string simbolo, dato;
    Carta *aux = frente;
    id = aux->Get_id();
    numero = aux->Get_numero();
    simbolo = aux->Get_simbolo();
    dato = aux->Get_dato();
    if (frente == fin) {
        frente = NULL;
        fin = NULL;
    } else {
        frente = frente->Get_siguiente();
    }
    delete aux;
    cola2->Agregar(frente2, fin2, id, numero, simbolo, dato);
}

void OpcionesJuego::rellenoCola(Carta *&frente, Carta *&fin, Carta *&frente2, Carta *&fin2, Cola *cola) {
    int id, numero;
    string simbolo, dato;
    Carta *aux = frente2;
    while (fin2 != NULL) {
        Carta *aux = frente2;
        if (frente2 == fin2) {
            frente2 = NULL;
            fin2 = NULL;
        } else {
            frente2 = frente2->Get_siguiente();
        }
        id = aux->Get_id();
        numero = aux->Get_numero();
        simbolo = aux->Get_simbolo();
        dato = aux->Get_dato();
        cola->Agregar(frente, fin, id, numero, simbolo, dato);
        delete aux;
    }
}

void OpcionesJuego::deReservaAMesa(Carta *&frente2, Carta *&fin2, Carta *&primero, Carta *&ultimo, ListasDobles *lista) {
    int id, numero;
    string simbolo, dato, bandera;
    if (fin2 != NULL) {
        Carta *aux = fin2;
        Carta *actual = new Carta();
        id = aux->Get_id();
        numero = aux->Get_numero();
        simbolo = aux->Get_simbolo();
        dato = aux->Get_dato();
        bandera = "SI";
        int numeroCoincidencia = numero + 1;
        if (ultimo == NULL) {
            if (numero == 13) {
                lista->insertarCarta(primero, ultimo, id, numero, simbolo, dato, bandera);
                if (frente2 == fin2) {
                    frente2 = NULL;
                    fin2 = NULL;
                } else {
                    fin2 = fin2->Get_anterior();
                }
                delete aux;
            } else {
                cout << "No puedes mover esta carta debido a su numero" << endl;
            }
        } else {
            Carta *aux2 = ultimo;
            if (aux2->Get_numero() == numeroCoincidencia) {
                if (aux2->Get_simbolo() == "Diamante" || aux2->Get_simbolo() == "Corazon") {
                    if (simbolo == "Trebol" || simbolo == "Pica") {
                        lista->insertarCarta(primero, ultimo, id, numero, simbolo, dato, bandera);
                        if (frente2 == fin2) {
                            frente2 = NULL;
                            fin2 = NULL;
                        } else {
                            fin2 = fin2->Get_anterior();
                        }
                        delete aux;
                    } else {
                        cout << "No es posible ingresar la carta debido a que la secuencia de simbolos no coincide" << endl;
                    }
                } else if (aux2->Get_simbolo() == "Trebol" || aux2->Get_simbolo() == "Pica") {
                    if (simbolo == "Diamante" || simbolo == "Corazon") {
                        lista->insertarCarta(primero, ultimo, id, numero, simbolo, dato, bandera);
                        if (frente2 == fin2) {
                            frente2 = NULL;
                            fin2 = NULL;
                        } else {
                            fin2 = fin2->Get_anterior();
                        }
                        delete aux;
                    } else {
                        cout << "No es posible ingresar la carta debido a que la secuencia de simbolos no coincide" << endl;
                    }
                }
            } else {
                cout << "No se puede ingresar la carta debido a que la secuencia de numeros no coincide" << aux2->Get_numero() << " - " << numeroCoincidencia << endl;
            }
        }
    } else {
        cout << "No hay cartas dentro del mazo para mover." << endl;
    }
}

void OpcionesJuego::moverColumnaAColumna(Carta *&frente, Carta *&fin, Carta *&frente2, Carta *&fin2, int totalCartas, Pilas *pilaAuxiliar, Carta *&frenteAux, ListasDobles *lista) {
    Carta *aux = new Carta();
    int numeros[totalCartas];
    string simbolos[totalCartas];
    if (frente != NULL) {
        aux = fin;
        if (frente == fin) {
            int numeroAux = aux->Get_numero();
            string simboloAux = aux->Get_simbolo();
            numeros[0] = numeroAux;
            simbolos[0] = simboloAux;
        } else {
            for (int i = 0; i < totalCartas; i++) {
                int numeroAux;
                string simboloAux;
                if (aux == NULL) {
                    cout << "Hay menos cartas en la columna de las que deseas mover" << endl;
                    break;
                } else {
                    numeroAux = aux->Get_numero();
                    simboloAux = aux->Get_simbolo();
                    numeros[i] = numeroAux;
                    simbolos[i] = simboloAux;
                    aux = aux->Get_anterior();
                }
            }
        }
        bool comprobacion = true;
        Carta *auxColumna2 = fin2;
        if (fin2 == NULL) {
            if (numeros[totalCartas - 1] == 13) {
                if (simbolos[0] == "Pica" || simbolos[0] == "Trebol") {
                    for (int i = 1; i < totalCartas; i++) {
                        if (i % 2 == 0) {
                            if (simbolos[i] == "Pica" || simbolos[i] == "Trebol") {
                                if (numeros[i] != numeros[i - 1] + 1) {
                                    comprobacion = false;
                                    break;
                                }
                            } else {
                                comprobacion = false;
                                break;
                            }
                        } else {
                            if (simbolos[i] == "Diamante" || simbolos[i] == "Corazon") {
                                if (numeros[i] != numeros[i - 1] + 1) {
                                    comprobacion = false;
                                    break;
                                }
                            } else {
                                comprobacion = false;
                                break;
                            }
                        }
                    }
                } else if (simbolos[0] == "Corazon" || simbolos[0] == "Diamante") {
                    for (int i = 1; i < totalCartas; i++) {
                        if (i % 2 == 0) {
                            if (simbolos[i] == "Corazon" || simbolos[i] == "Diamante") {
                                if (numeros[i] != numeros[i - 1] + 1) {
                                    comprobacion = false;
                                    break;
                                }
                            } else {
                                comprobacion = false;
                                break;
                            }
                        } else {
                            if (simbolos[i] == "Pica" || simbolos[i] == "Trebol") {
                                if (numeros[i] != numeros[i - 1] + 1) {
                                    comprobacion = false;
                                    break;
                                }
                            } else {
                                comprobacion = false;
                                break;
                            }
                        }
                    }
                }
                OpcionesJuego::movimientoColumnas(frente, fin, frente2, fin2, totalCartas, comprobacion, pilaAuxiliar, frenteAux, lista);
            } else {
                cout << "No es posible este movimiento debido al numero de la carta." << endl;
            }
        } else {
            if (fin2->Get_numero() == numeros[totalCartas - 1] + 1) {
                if (((simbolos[totalCartas - 1] == "Diamante" || simbolos[totalCartas - 1] == "Corazon") && (fin2->Get_simbolo() == "Pica" || fin2->Get_simbolo() == "Trebol")) || ((simbolos[totalCartas - 1] == "Pica" || simbolos[totalCartas - 1] == "Trebol") && (fin2->Get_simbolo() == "Diamante" || fin2->Get_simbolo() == "Corazon"))) {
                    if (simbolos[0] == "Pica" || simbolos[0] == "Trebol") {
                        for (int i = 1; i < totalCartas; i++) {
                            if (i % 2 == 0) {
                                if (simbolos[i] == "Pica" || simbolos[i] == "Trebol") {
                                    if (numeros[i] != numeros[i - 1] + 1) {
                                        comprobacion = false;
                                        break;
                                    }
                                } else {
                                    comprobacion = false;
                                    break;
                                }
                            } else {
                                if (simbolos[i] == "Diamante" || simbolos[i] == "Corazon") {
                                    if (numeros[i] != numeros[i - 1] + 1) {
                                        comprobacion = false;
                                        break;
                                    }
                                } else {
                                    comprobacion = false;
                                    break;
                                }
                            }
                        }
                    } else if (simbolos[0] == "Corazon" || simbolos[0] == "Diamante") {
                        for (int i = 1; i < totalCartas; i++) {
                            if (i % 2 == 0) {
                                if (simbolos[i] == "Corazon" || simbolos[i] == "Diamante") {
                                    if (numeros[i] != numeros[i - 1] + 1) {
                                        comprobacion = false;
                                        break;
                                    }
                                } else {
                                    comprobacion = false;
                                    break;
                                }
                            } else {
                                if (simbolos[i] == "Pica" || simbolos[i] == "Trebol") {
                                    if (numeros[i] != numeros[i - 1] + 1) {
                                        comprobacion = false;
                                        break;
                                    }
                                } else {
                                    comprobacion = false;
                                    break;
                                }
                            }
                        }
                    }
                    OpcionesJuego::movimientoColumnas(frente, fin, frente2, fin2, totalCartas, comprobacion, pilaAuxiliar, frenteAux, lista);
                } else {
                    cout << "No es posible este movimiento" << endl;
                }
            } else {
                cout << "No es posible este movimientoPPPP" << endl;
            }
        }
    } else {
        cout << "No hay cartas dentro de esta columna para mover" << endl;
    }
}

void OpcionesJuego::movimientoColumnas(Carta *&frente, Carta *&fin, Carta *&frente2, Carta *&fin2, int totalCartas, bool comprobacion, Pilas *pilaAuxiliar, Carta *&frenteAux, ListasDobles *lista) {
    if (comprobacion == true) {
        for (int i = 0; i < totalCartas; i++) {
            Carta *aux = fin;
            int id, numero;
            string simbolo, dato, bandera;
            id = aux->Get_id();
            numero = aux->Get_numero();
            simbolo = aux->Get_simbolo();
            dato = aux->Get_dato();
            bandera = aux->Get_bandera();
            pilaAuxiliar->Agregar(frenteAux, id, numero, simbolo, dato, bandera);
            if (frente == fin) {
                frente = NULL;
                fin = NULL;
            } else {
                fin = fin->Get_anterior();
                fin->Set_bandera("SI");
                fin->Set_siguiente(NULL);
            }
            delete aux;
        }
        while (frenteAux != NULL) {
            Carta *auxPila = frenteAux;
            int id, numero;
            string simbolo, dato, bandera;
            id = auxPila->Get_id();
            numero = auxPila->Get_numero();
            simbolo = auxPila->Get_simbolo();
            dato = auxPila->Get_dato();
            bandera = auxPila->Get_bandera();
            lista->insertarCarta(frente2, fin2, id, numero, simbolo, dato, bandera);
            pilaAuxiliar->Quitar(frenteAux);
        }
    } else {
        cout << "No es posible este movimiento debido al orden de las cartas." << endl;
    }
}

void OpcionesJuego::moverColumnaAPFinal(Carta *&frente, Carta *&fin, Carta *&frentePila, Pilas *pilaFinal) {
    int id, numero;
    string dato, simbolo, bandera;
    if (fin != NULL) {
        Carta *aux = fin;
        id = aux->Get_id();
        numero = aux->Get_numero();
        dato = aux->Get_dato();
        bandera = aux->Get_bandera();
        simbolo = aux->Get_simbolo();
        if (frentePila == NULL) {
            if (numero == 1) {
                if (frente == fin) {
                    frente = NULL;
                    fin = NULL;
                } else {
                    fin = fin->Get_anterior();
                    fin->Set_bandera("SI");
                    fin->Set_siguiente(NULL);
                }
                pilaFinal->Agregar(frentePila, id, numero, simbolo, dato, bandera);
                delete aux;
            } else {
                cout << "No se puede agregar la carta, debe iniciar con A." << endl;
            }
        } else {
            Carta *auxPila = frentePila;
            if (numero == auxPila->Get_numero() + 1) {
                if (aux->Get_simbolo() == auxPila->Get_simbolo()) {
                    if (frente == fin) {
                        frente = NULL;
                        fin = NULL;
                    } else {
                        fin = fin->Get_anterior();
                        fin->Set_bandera("SI");
                        fin->Set_siguiente(NULL);
                    }
                    pilaFinal->Agregar(frentePila, id, numero, simbolo, dato, bandera);
                    delete aux;
                } else {
                    cout << "No se puede agregar la carta, (diferente simbolo)." << endl;
                }
            } else {
                cout << "No se puede agregar la carta, el numero de las cartas debe ser secuencial." << endl;
            }
        }
    } else {
        cout << "No hay cartas dentro de este mazo." << endl;
    }
}

void OpcionesJuego::moverPFinalAColumna(Carta *&frente, Carta *&fin, Carta *&frentePila, ListasDobles *lista, Pilas *pilaFinal) {
    int id, numero;
    string simbolo, dato, bandera;
    if (frentePila != NULL) {
        Carta *auxPila = frentePila;
        id = auxPila->Get_id();
        numero = auxPila->Get_numero();
        simbolo = auxPila->Get_simbolo();
        dato = auxPila->Get_dato();
        bandera = auxPila->Get_bandera();
        Carta *aux = fin;
        if (fin == NULL) {
            if (numero == 13) {
                lista->insertarCarta(frente, fin, id, numero, simbolo, dato, bandera);
                pilaFinal->Quitar(frentePila);
            } else {
                cout << "Solo una carta K puede ser insertada en una columna sin cartas." << endl;
            }
        } else {
            if (aux->Get_numero() == numero + 1) {
                if (aux->Get_simbolo() == "Trebol" || aux->Get_simbolo() == "Pica") {
                    if (simbolo == "Diamante" || simbolo == "Corazon") {
                        lista->insertarCarta(frente, fin, id, numero, simbolo, dato, bandera);
                        pilaFinal->Quitar(frentePila);
                    } else {
                        cout << "No es posible este movimiento" << endl;
                    }
                } else if (aux->Get_simbolo() == "Diamante" || aux->Get_simbolo() == "Corazon") {
                    if (simbolo == "Trebol" || simbolo == "Pica") {
                        lista->insertarCarta(frente, fin, id, numero, simbolo, dato, bandera);
                        pilaFinal->Quitar(frentePila);
                    } else {
                        cout << "No es posible este movimiento" << endl;
                    }
                }
            } else {
                cout << "No es posible este movimiento, el numero de cartas debe ser secuencial." << endl;
            }
        }
    } else {
        cout << "No hay cartas dentro de este mazo." << endl;
    }
}

void OpcionesJuego::obtenerAnteriorSiguiente(Carta *&primero, Carta *&ultimo, char noCarta) {
    bool comprobacion = true;
    int noCartaConv = (int)noCarta - 48;
    string dato;
    string datos[noCartaConv+1];
    if (primero != NULL) {
        Carta *aux = ultimo;
        if(primero == ultimo){
            datos[0] = aux->Get_dato();
            cout<<"Este mazo solo tiene una carta y es: "<<datos[0]<<endl;
        } else {
            int cont = 0;
            for (int i = 0; i < noCartaConv + 1; i++) {
                Carta *aux2 = aux;
                if (aux2 == NULL) {
                    comprobacion = false;
                    break;
                }
                dato = aux->Get_dato();
                datos[i] = dato;
                aux = aux->Get_anterior();
                cont++;
            }
        if(noCartaConv > 1){
            if (comprobacion == true) {
                cout << "La carta siguiente es " << datos[noCartaConv] << endl;
                cout << "La carta que indicas es " << datos[noCartaConv - 1] << endl;
               cout << "La carta anterior es " << datos[noCartaConv - 2] << endl;
             } else {
                if(cont == noCartaConv){
                    cout<<"La carta que indicas es "<< datos[noCartaConv - 1] << endl;
                    cout<<"La carta anterior es "<< datos[noCartaConv - 2] <<endl;
                } else {
                    cout << "El numero de carta que buscas no existe dentro del mazo." << endl;
                }
            }
        } else {
            if(comprobacion == true){
                cout << "La carta siguiente es " << datos[noCartaConv] << endl;
                cout << "La carta que indicas es " << datos[noCartaConv - 1] << endl;
            } else {
                cout << "El numero de carta que buscas no existe dentro del mazo." << endl;
            }
        }
    }
    } else {
        cout << "No hay cartas dentro del mazo que indicas." << endl;
    }
}

void OpcionesJuego::obtenerSiguienteCola(Carta *&frente, Carta *&fin){
    if(frente!=NULL){
        Carta *aux = frente;
        if(aux->Get_siguiente()!= NULL){
            cout<<"La carta siguiente es: "<<aux->Get_siguiente()->Get_dato()<<endl;
            cout<<"La carta actual es: "<<aux->Get_dato()<<endl;
        } else {
            cout<<"La carta actual es: "<<aux->Get_dato()<<endl;
            
        }
    } else {
        cout<<"No hay cartas dentro del mazo."<<endl;
    }
}

void OpcionesJuego::obtenerSiguienteCola2(Carta *&frente, Carta *&fin){
    if(frente!=NULL){
        Carta *aux = fin;
        if(aux->Get_anterior() != NULL){
            cout<<"La carta anterior es: "<<aux->Get_anterior()->Get_dato()<<endl;
            cout<<"La carta actual es: "<<aux->Get_dato()<<endl;
        } else {
            cout << "La carta actual es: "<<aux->Get_dato()<<endl;
        }
    } else {
        cout<<"No hay cartas dentro del mazo."<<endl;
    }
}

OpcionesJuego::OpcionesJuego(const OpcionesJuego& orig) {
}

OpcionesJuego::~OpcionesJuego() {
}

