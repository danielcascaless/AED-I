#include <iostream>
using namespace std;

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

int main(){

string palabra;
int i=1;
while(cin>>palabra){
cout<<i<<". "<<palabra<<" -> "<<normalizar(palabra)<<endl;
i++;
}

}
