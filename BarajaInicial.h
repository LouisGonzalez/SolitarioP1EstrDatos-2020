/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BarajaInicial.h
 * Author: luisGonzalez
 *
 * Created on 22 de febrero de 2020, 04:00 PM
 */

#ifndef BARAJAINICIAL_H
#define BARAJAINICIAL_H
#include "Carta.h"

using namespace std;
    
class BarajaInicial {
public:
    BarajaInicial();
    
    void Set_cabeza(Carta*);
    Carta* Get_cabeza();
    Carta* Get_ultimo();
    void Agregar(Carta*);
    Carta* Buscar(int);
    void Eliminar(int);
    
    BarajaInicial(const BarajaInicial& orig);
    virtual ~BarajaInicial();
private:
    Carta *Cabeza;
};

#endif /* BARAJAINICIAL_H */

