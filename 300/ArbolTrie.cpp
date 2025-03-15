#include "ArbolTrie.h"

using namespace std;

NodoTrie::NodoTrie() 
{
    sig = nullptr;
    hijo = nullptr;
}

NodoTrie::~NodoTrie() 
{
    NodoTrie* aux = hijo;
    while (aux)
    {
        NodoTrie* siguiente = aux->sig;
        delete aux;
        aux = siguiente;
    }
}

void NodoTrie::vaciarNodo() 
{
    NodoTrie* aux = hijo;
    while (aux)
    {
        NodoTrie* siguiente = aux->sig;
        aux->vaciarNodo();
        delete aux;
        aux = siguiente;
    }
    hijo = nullptr;
}

NodoTrie* NodoTrie::buscarNodo(char l)
{
    NodoTrie* aux = hijo;
    while (aux && aux->car != l) 
    {
        aux = aux->sig;
    }
    return aux;
}

void NodoTrie::agregarNodo(char l)
{
    NodoTrie* aux = new NodoTrie();
    aux->car = l;
    if (!hijo) 
    {
        hijo = aux;
    } 

    else 
    {
        NodoTrie* ultimo = hijo;
        while (ultimo->sig) 
        {
            ultimo = ultimo->sig;
        }
        ultimo->sig = aux;
    }
}

void NodoTrie::agregarPagina(Pagina* pagina) 
{
    NodoTrie* aux = this;
    list<Pagina*>::iterator it = aux->lista.begin();
    while (it != aux->lista.end() && (*it)->getUrl() != pagina->getUrl())
    {
        it++;
    }

    if (it == aux->lista.end()) 
    {
        lista.push_back(pagina);
        aux->lista = ordenarLista(lista);
        
    } 
    else 
    {
		
        (*it)->setTitulo(pagina->getTitulo());
        (*it)->setRelevancia(pagina->getRelevancia());
    }
}

list<Pagina*> NodoTrie::obtenerLista() 
{
    return lista;
}

list<Pagina*> NodoTrie::ordenarLista(list<Pagina*> paginas) 
{
    list<Pagina*>::iterator it = paginas.begin();
    list<Pagina*>::iterator it2 = paginas.begin();
    while (it2 != paginas.end()) 
    {
        it = it2;
        it++;
        while (it != paginas.end()) 
        {
            if ((*it2)->getRelevancia() < (*it)->getRelevancia() || ((*it2)->getRelevancia() == (*it)->getRelevancia() && (*it2)->getUrl() > (*it)->getUrl())) 
            {
                Pagina* tmp = *it2;
                *it2 = *it;
                *it = tmp;
            }
            it++;
        }
        it2++;
    }
    return paginas;
}

ArbolTrie::ArbolTrie() 
{
    raiz = new NodoTrie();
    nElem = 0;
}

ArbolTrie::~ArbolTrie() 
{
    raiz->vaciarNodo();
    delete raiz;
}

void ArbolTrie::insertar(string palabra, Pagina* pag) 
{
    NodoTrie* aux = raiz;
    for (char letra : palabra) 
    {
        NodoTrie* siguiente = aux->buscarNodo(letra);
        if (!siguiente) 
        {
            aux->agregarNodo(letra);
            siguiente = aux->buscarNodo(letra);
        }
        aux = siguiente;
    }
    
    if (!aux->buscarNodo('$')) 
    {
        aux->agregarNodo('$');
        nElem++;
    }
    aux = aux->buscarNodo('$');
    aux->agregarPagina(pag);
}

list<Pagina*> ArbolTrie::consultar(string palabra) 
{
    NodoTrie* aux = raiz;
    list<Pagina*> listaVacia;
    for (char letra : palabra)
    {
        aux = aux->buscarNodo(letra);
        if (!aux) 
        {
            return listaVacia;
        }
    }
    NodoTrie* final = aux->buscarNodo('$');
    if (final) 
    {
        return final->obtenerLista();
    } 
    else 
    {
        return listaVacia;
    }
}

void ArbolTrie::vaciar() 
{
    delete raiz;
    raiz = new NodoTrie();
    nElem = 0;
}

int ArbolTrie::numElem() 
{
    return nElem;
}
