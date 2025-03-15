#include "pagina.h"
#include <string>


using namespace std;

Pagina::Pagina(const string u, const string t, int r) : url(u), titulo(t), relevancia(r) {}

const string Pagina::getUrl() const {
	return url;
}

const string Pagina::getTitulo() const {
	return titulo;
}

int Pagina::getRelevancia() const {
	return relevancia;
}

void Pagina::setTitulo(const string t) {
	titulo = t;
}	

void Pagina::setRelevancia(int r) {
	relevancia = r;
}
