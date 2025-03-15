#include <iostream>
#include <string>
#include <list>
#include "pagina.h"
#include "tabla_hash.h"
#include <cmath>

using namespace std;

// Constructor: Inicializa la tabla con el tamaño dado
TablaHash::TablaHash(int tamano) {
	tam=tamano;
	numElem=0;
	
    lista = new list<Pagina>[tam];
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

// Insertar una nueva página en la tabla
void TablaHash::insertar(const Pagina& nueva) {
	
    int indice = funcionDispersion(nueva.getUrl());
    
    list<Pagina>&Indice = lista[indice];
    list<Pagina>::iterator it = Indice.begin();
    bool encontrado = false;
    
    while(it!= Indice.end()&&!encontrado){
		
		if(it->getUrl() == nueva.getUrl()){
			it->setTitulo(nueva.getTitulo());
			it->setRelevancia(nueva.getRelevancia());
			encontrado = true;
			}
		it++;
		}
    if(!encontrado){
		Indice.push_back(nueva);
		numElem++;
		}
}


// Consultar una página por URL
Pagina* TablaHash::consultar(const string& url) {
    int indice = funcionDispersion(url);
    list<Pagina>&Indice = lista[indice];
    
    list<Pagina>::iterator it = Indice.begin();
    
    while(it != Indice.end()){
		if(it->getUrl()==url){
			return&(*it);
			}
		it++;
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

// Obtener una referencia a la lista en un índice
list<Pagina>& TablaHash::getLista(int indice) {
    return lista[indice];
}
