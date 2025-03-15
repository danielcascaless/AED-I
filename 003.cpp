#include <iostream>
using namespace std;

int contador = 0;

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



void INSERTAR(){
::contador ++;
int relevancia;
string URL;
string titulo;
string palabra;
int i=0;

cin>>relevancia;
cin.ignore();
getline(cin, URL);
getline(cin, titulo);
cin>>palabra;
while(normalizar(palabra)!="findepagina"){
i++;
cin>>palabra;
}
cout<<contador<<". "<<URL<<", "<<titulo<<", Rel. "<<relevancia<<endl;
cout<<i<<" palabras"<<endl;

}

void BUSCAR_URL(){
string URL;
cin>>URL;
cout<<"u "<<URL<<endl;
cout<<"Total: 0 resultados"<<endl;

}

void BUSCAR_PALABRA(){
string palabra;
cin>>palabra;
cout<<"b "<<normalizar(palabra)<<endl;
cout<<"Total: 0 resultados"<<endl;
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


int main()

{

char comando;
string palabra;

while(cin>>comando && comando!='s'){
	interprete(comando);
	
	}
	if(comando=='s'){
		SALIR();
	}	

return 0;

}
