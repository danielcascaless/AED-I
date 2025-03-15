#include <iostream>
#include <string>
#include <list>
#include "pagina.h"
#include "tabla_hash.h"
#include <cmath>

using namespace std;

// Constructor: Inicializa la tabla con el tamaño dado
TablaHash::TablaHash(int tamano) {
	
	numElem=0;
	tam = tamano;
    lista = new list<Pagina>[tamano];
}

// Destructor: Libera la memoria asignada para la tabla
TablaHash::~TablaHash() {
    destruirDic();
    delete[] lista;
}

// Función de dispersión: Devuelve un índice para una URL
int TablaHash::funcionDispersion(const string& url) {
    unsigned long hash = 0;
    
    for (int i=0; i<(int)url.length();++i) {
        hash = (hash *31 + url[i])%tam;
    }
    return hash ;
}

Pagina* TablaHash::insertar (Pagina nueva)
{
    int posicion = funcionDispersion(nueva.getUrl());
	list<Pagina>::iterator it = lista[posicion].begin();
	
	while(it != lista[posicion].end() && nueva.getUrl() != (*it).getUrl())
    {
		it++;
	}
	if (it == lista[posicion].end())
    {
		numElem++;
		lista[posicion].push_back(nueva);
	} 
    else 
    {
		(*it).setRelevancia(nueva.getRelevancia());
		(*it).setTitulo(nueva.getTitulo());
	}
	
	return consultar(nueva.getUrl());
	
}


Pagina* TablaHash::consultar(string URL)
{
    int posicion = funcionDispersion(URL);
    list<Pagina>::iterator it = lista[posicion].begin();
    while (it != lista[posicion].end() && it->getUrl() != URL)
    {
        ++it;
    }

    if (it != lista[posicion].end())
    {
        return &(*it);
    }

    return nullptr;
}

// Destruir el diccionario (vaciar todas las listas)
void TablaHash::destruirDic() {
    for (int i = 0; i < tam; i++) {
        lista[i].clear();
    }
    numElem = 0;
}

// Obtener el número de elementos en la tabla
int TablaHash::getNumElem() const {
    return numElem;
}

// Ajustar el tamaño de la tabla
void TablaHash::setTamano(int nuevoTamano) {
    destruirDic();
    delete[] lista;
    tam = nuevoTamano;
    lista = new list<Pagina>[tam];
}

// Obtener el tamaño de la tabla
int TablaHash::getTamano() {
    return tam;
}
/*
// Obtener una referencia a la lista en un índice
list<Pagina*>& TablaHash::getLista(int indice) {
    return lista[indice];
}
*/
