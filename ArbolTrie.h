#ifndef _ARBOLTRIE_H
#define _ARBOLTRIE_H

#include <string>
#include <list>
#include <iostream>
#include "pagina.h"

using namespace std;

class NodoTrie 
{
    private:
        char car; 
        NodoTrie* sig;
        NodoTrie* hijo; 
        list<Pagina*> lista;

    public: 
        NodoTrie();
        ~NodoTrie();
        void vaciarNodo();
        NodoTrie* buscarNodo(char l); 
        void agregarNodo(char l); 
        void agregarPagina(Pagina* pagina); 
        list<Pagina*> obtenerLista(); 
        list<Pagina*> ordenarLista(list<Pagina*> paginas); 
};

class ArbolTrie 
{
    private:
        NodoTrie* raiz;
        int nElem; 

    public:
        ArbolTrie();
        ~ArbolTrie();
        void vaciar();
        void insertar(string palabra, Pagina* pag); 
        list<Pagina*> consultar(string pagina); 
        int numElem(); 
};

#endif
