/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Carta.h
 * Author: luisitopapurey
 *
 * Created on 22 de febrero de 2020, 04:00 PM
 */

#ifndef CARTA_H
#define CARTA_H
#include <string>

using namespace std;

class Carta {
public:
    Carta();
    Carta(const Carta& orig);
    
    void Set_id(int);
    void Set_numero(int);
    void Set_simbolo(string);
    void Set_color(string);
    void Set_dato(string);
    void Set_bandera(string);
    void Set_siguiente(Carta*);
    void Set_anterior(Carta*);
    int Get_numero();
    int Get_id();
    string Get_dato();
    string Get_color();
    string Get_simbolo();
    string Get_bandera();
    Carta* Get_siguiente();
    Carta* Get_anterior();
    
    virtual ~Carta();
private:
    int id;
    int numero;
    string simbolo;
    string color;   
    string dato;
    string bandera;
    Carta *siguiente;
    Carta *anterior;

};

#endif /* CARTA_H */

