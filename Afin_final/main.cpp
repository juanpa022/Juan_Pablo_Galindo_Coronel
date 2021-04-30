#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <random>

using namespace std;
class algoX
{
    int clave01, clave02;
	int inverT;
    public:
    string cifrar(string);
	string descifrar(string);
	string alfa= "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ.,_-0123456789";
	algoX();
	algoX(int, int);
	int mod(int, int);
	int valor(int);
	int exten(int, int);
	int euclide(int, int);
	int inver(int, int);
	void genera(int&, int&);
	void impri();
};
void algoX::genera(int& a, int& b) {
	srand(time(NULL));
	b = mod(rand(), alfa.length());
	do {
		a = rand() % alfa.length();
	} while (euclide(a, alfa.length()) != 1);
}

void algoX::impri() {
	cout << "\n Clave 1: " << clave01 ;
	cout << "\n Clave 2: " << clave02 ;
}

int algoX::mod(int a, int b) {
	if(a>=0)
        return a-(a/b)*b;
    else
        return a-((a/b)-1)*b;
}

int algoX::valor(int a) {
	if (a < 0)
		a = a * -1;
	return a;
}

int algoX::exten(int a, int n) {
	int s1 = 1;
	int s2 = 0;
	while (n > 0) {
		int q = a / n;
		int r = a - q * n;
		a = n;
		n = r;
		int s = s1 - q * s2;
		s1 = s2;
		s2 = s;
	}
	return s1;
}

int algoX::euclide(int a, int b) {
    int residuo;
    residuo = mod(a, b);
    if(residuo == 0){
        return b;
    }else {
        while (residuo != 0) {
            a = b;
            b = residuo;
            residuo = mod(a, b);
            if (mod(a, b) == 0) {
                return b;
            }
        }
    }
}

int algoX::inver(int a, int n) {
	if (euclide(a, n) == 1) {
		int invert = exten(a, n);
		if (invert < 0)
			invert = invert + n;
		return invert;
	}
	else
		cout << "No hay\n";
}

algoX::algoX() {
	genera(clave01, clave02);
}

algoX::algoX(int a, int b) {
	clave01 = a;
	clave02 = b;
	inverT = inver(a, alfa.length());
}

string algoX::cifrar(string mensaje) {
	string mcifrado;
	int tem;
	for (int i = 0; i < mensaje.length(); i++) {
		tem = alfa.find(mensaje.at(i));
		int x = mod((clave01 * tem) + clave02, alfa.length());
		mcifrado += alfa.at(x);
	}
	return mcifrado;
}

string algoX::descifrar(string mensaje_cifra) {
	string mdescifrado;
	int tem;
	for (int i = 0; i < mensaje_cifra.length(); i++) {
		tem = alfa.find(mensaje_cifra.at(i));
		int x = mod(inverT * (tem - clave02), alfa.length());
		mdescifrado += alfa.at(x);
	}
	return mdescifrado;
}
int main() {

    algoX emisor;
    string x,y;
	cout << "Escribe tu mensaje: ";
	getline(cin,x);
	string mcifrado = emisor.cifrar(x);
	cout << "\nMensaje: " << mcifrado;
	emisor.impri();
    cout << "\n Escribe tu mensaje: ";
    getline(cin, y);
	int a,b;
	cout << "\n  La clave 1: ";cin >> a;
	cout << "\n  La clave 2: ";cin >> b;
	algoX receptor(a, b);
	string mdescifrado = receptor.descifrar(y);
	cout << "\n Mensaje descifrado: " << mdescifrado;


}

