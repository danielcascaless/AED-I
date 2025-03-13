#include <iostream>
#include <string>
#include <cctype>
#include "pagina.h"
#include "diccionario.h"
#include "interprete.h"
#include "ArbolTrie.h"

using namespace std;



int contador_paginas_global = 0;


//Normalizacion de cadenas(002)
string normalizar (string entrada){
string salida;
char c;
for(unsigned i=0; i<entrada.length();i++){
if(isalpha(entrada[i])){
c = tolower(entrada[i]);
salida = salida + c;
}
else if(entrada[i] == (char)0xC3)  {
				switch(entrada[i+1]){

				case (char)0xA1: case (char)0x81: salida += 'a'; break;
                case (char)0xA9: case (char)0x89: salida += 'e'; break;
                case (char)0xAD: case (char)0x8D: salida += 'i'; break;
                case (char)0xB3: case (char)0x93: salida += 'o'; break;
                case (char)0xBA: case (char)0x9A: case (char)0xBC: case (char)0x9C: salida += 'u'; break;
                case (char)0xB1: case (char)0x91: salida += "ñ"; break;

default:
salida = salida + entrada[i] + entrada[i+1];
break;

}
i++;
}
else {
salida = salida + entrada[i];
}
}
return salida;
}



DiccionariodePaginas diccionario;

//Insertar en un diccionario
void INSERTAR(){
	
	int relevancia;
	string url;
	string titulo;
	string palabra;
	string contenido;
	int cont_palabras=0;

	cin >> relevancia;
    cin.ignore();
    getline(cin, url);
    getline(cin, titulo);
	Pagina nueva(url,titulo,relevancia);
	
	Pagina* referencia = diccionario.insertarPagina(nueva);
	
	while(cin>>palabra && normalizar(palabra)!="findepagina"){
		cont_palabras++;
		diccionario.insertar(normalizar(palabra), referencia);
	}
	
	contador_paginas_global = diccionario.tamano();
		
	cout<<contador_paginas_global<<". "<<url<<", "<<titulo<<", Rel. "<<relevancia<<endl;
	cout<<cont_palabras<<" palabras"<<endl;

}



void BUSCAR_URL(){
string url;
cin>>url;

cout << "u " << url << endl;

Pagina* pagina = diccionario.consultarUrl(url);
    if (pagina) {
		cout << "1. " << pagina->getUrl() << ", " << pagina->getTitulo() << ", Rel. " << pagina->getRelevancia() << endl;
		cout << "Total: 1 resultados" << endl;
	} else {
		cout << "Total: 0 resultados" << endl;
		}
}


void BUSCAR_PALABRA() {
    string palabra;
    cin >> palabra;
    palabra = normalizar(palabra);
    
    list<Pagina*> resultados = diccionario.buscarPalabra(palabra);

    // Ordenar la lista con los resultados por relevancia y URL
    resultados.sort([](Pagina* a, Pagina* b) {
        if (a->getRelevancia() != b->getRelevancia())
            return a->getRelevancia() > b->getRelevancia(); // Mayor relevancia primero
        return a->getUrl() < b->getUrl(); // Alfabético por URL
    });

    // Mostrar los resultados
    cout << "b " << palabra << endl;
    
    int contador = 1;
    for (list<Pagina*>::iterator it = resultados.begin(); it != resultados.end(); it++) {
        Pagina* pagina = *it;
        cout << contador++ << ". " << pagina->getUrl() << ", " << pagina->getTitulo()
             << ", Rel. " << pagina->getRelevancia() << endl;
    }
    cout << "Total: " << resultados.size() << " resultados" << endl;
}



void BUSCAR_AND(){
string frase;
cin.ignore();
getline(cin, frase);
cout<<"a "<<normalizar(frase)<<endl;
cout<<"Total: 0 resultados"<<endl;
}

void BUSCAR_OR(){
string frase;
cin.ignore();
getline(cin, frase);
cout<<"o "<<normalizar(frase)<<endl;
cout<<"Total: 0 resultados"<<endl;
}

void BUSCAR_PREFIJO(){
string palabra;
cin>>palabra;
cout<<"p "<<normalizar(palabra)<<endl;
cout<<"Total: 0 resultados"<<endl;
}
void SALIR(){
	cout<<"Saliendo..."<<endl;
}


//Interpretador de comandos 
void interprete (char comando){
switch (comando){
case 'i':
INSERTAR();
break;

case 'u':
BUSCAR_URL();
break;

case 'b':
BUSCAR_PALABRA();
break;

case 'a':
BUSCAR_AND();
break;

case 'o':
BUSCAR_OR();
break;

case 'p':
BUSCAR_PREFIJO();
break;

case 's':
SALIR();
break;

default:
break;
}
}

