#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "pagina.h"
#include "tabla_hash.h"
#include "ArbolTrie.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class DiccionariodePaginas {
private:
	TablaHash tabla;
	ArbolTrie arbolPalabras;
	
public:
	DiccionariodePaginas(int tamano = 10000); // iniciamos con un tamaño grande por si acaso
	Pagina* insertarPagina(Pagina nueva);//Insertar pagina
	void insertar(string palabra, Pagina* referencia);
	Pagina* consultarUrl(const string& u);//Consultar si hay una pagina con una url
	list<Pagina*> buscarPalabra(const string& palabra);
	size_t tamano() const;//Consultar tamano
};

#endif
