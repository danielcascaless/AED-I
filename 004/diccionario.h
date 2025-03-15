#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "pagina.h"
#include <string>
#include <list>
using namespace std;

class DiccionariodePaginas {
private:
	list<Pagina> paginas;

public:
	void insertarPagina(const string u, const string t, int r);
	Pagina* consultarUrl(const string u);
	size_t tamano() const;
};

#endif
