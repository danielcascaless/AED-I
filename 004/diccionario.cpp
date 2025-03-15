#include "diccionario.h"
#include <iostream>
using namespace std;

void DiccionariodePaginas::insertarPagina(const string url, const string titulo, int relevancia) {

	list<Pagina>::iterator it = paginas.begin();
	
	while(it != paginas.end() && it->getUrl() < url) { ++it; }
	
	if (it != paginas.end() && it->getUrl() == url) {
		it -> setTitulo(titulo);
		it -> setRelevancia(relevancia);
	} else {
		paginas.insert(it, Pagina(url, titulo, relevancia));
		}
	
}


Pagina* DiccionariodePaginas::consultarUrl(const string url) {
	
	list <Pagina>::iterator it = paginas.begin();
	
	while(it != paginas.end() && it->getUrl() < url) { ++it; }
	
	if (it != paginas.end() && it->getUrl() == url) {
		return &(*it);
	}
	
	return nullptr;
	
}

size_t DiccionariodePaginas::tamano() const {
	return paginas.size();
	}
