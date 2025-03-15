#ifndef INTERPRETE_H
#define INTERPRETE_H

#include <iostream>
using namespace std;


string normalizar(string entrada);

void INSERTAR();
void BUSCAR_URL();
void BUSCAR_PALABRA();
void BUSCAR_AND();
void BUSCAR_OR();
void BUSCAR_PREFIJO();
void SALIR();

void interprete (char comando);

#endif
