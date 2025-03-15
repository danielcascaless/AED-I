#include "pagina.h"
#include <string>
#include <iostream>


using namespace std;

Pagina::Pagina(const string u, const string t, int r) : url(u), titulo(t), relevancia(r) {}

void Pagina::leer()
{
    cin >> relevancia;
    cin.ignore();
    getline(cin, url);
    getline(cin, titulo);
}

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

bool operator==(const Pagina &p1, const Pagina &p2)
{
   return p1.getUrl() == p2.getUrl();
}
