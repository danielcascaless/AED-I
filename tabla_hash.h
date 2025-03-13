#ifndef TABLA_HASH_H
#define TABLA_HASH_H

#include <iostream>
#include <list>
#include <string>
#include "pagina.h"

using namespace std;

class TablaHash {
private:
    int tam;
    list<Pagina>* lista; 
    int numElem;
    int funcionDispersion(const string& url);

public:

    TablaHash(int tamano);    // Constructor
    ~TablaHash();             // Destructor
    
    Pagina* insertar(Pagina nueva);   // Insertar una nueva página
    Pagina* consultar(const string url); // Consultar una página
    void destruirDic();       // Destruir el diccionario
    int getTamano();          // Obtener el tamaño del diccionario
    int getNumElem()const;         // Obtener el número de elementos
    void setTamano(int nuevoTamano); // Ajustar el tamaño del diccionario
    list<Pagina*>& getLista(int indice); // Obtener la lista en un índice
};

#endif
