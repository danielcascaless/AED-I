#include "diccionario.h"
#include "interprete.h"
#include <iostream>
#include <cctype>


using namespace std;

DiccionariodePaginas::DiccionariodePaginas(int tamano) : tabla(tamano){}


// Insertar una pagina
Pagina* DiccionariodePaginas::insertarPagina(Pagina nueva){
	
	return tabla.insertar(nueva);
			
}

void DiccionariodePaginas::insertar(string palabra, Pagina *referencia)
{
    arbolPalabras.insertar(palabra, referencia);
}

// Consultar una pagina por una URL
Pagina* DiccionariodePaginas::consultarUrl(const string& url) {
	
	return tabla.consultar(url);
}

list<Pagina*>DiccionariodePaginas::buscarPalabra(const string& palabra){
	return arbolPalabras.consultar(palabra);
	}

// Consultar al tamano de paginas que tiene el diccionario
size_t DiccionariodePaginas::tamano() const {
	return tabla.getNumElem();
	}
