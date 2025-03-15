#include "diccionario.h"
#include <iostream>

using namespace std;

DiccionariodePaginas::DiccionariodePaginas(int tamano) : tabla(tamano){}


// Insertar una pagina
void DiccionariodePaginas::insertarPagina(const string& url, const string& titulo, int relevancia) {

	tabla.insertar(Pagina(url, titulo,relevancia));
	
}

// Consultar una pagina por una URL
Pagina* DiccionariodePaginas::consultarUrl(const string& url) {
	
	return tabla.consultar(url);
}

// Consultar al tamano de paginas que tiene el diccionario
size_t DiccionariodePaginas::tamano() const {
	return tabla.getNumElem();
	}
