#include <iostream>
#include <string>
#include <cctype>
#include "pagina.h"
#include "diccionario.h"
#include "interprete.h"



using namespace std;


int main(){

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
