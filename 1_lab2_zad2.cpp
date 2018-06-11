/*
	Objetosc i powierzchnie calkowita graniastoslupa foremnego o podstawie szesciokata
*/
#pragma warning (disable : 4996)
#include <math.h>
#include <iostream>

#define pole_podstawy(a) ((3*sqrt(3)*pow(a, 2.0))/2)
using namespace std;

int main(){
	double a = 0.0;
	double h = 0.0;
	double v = 0.0;
	double p = 0.0;
	cout << "Program liczy objetosc i powierzchnie calkowita graniastoslupa foremnego o podstawie szesciokata" << endl;
	cout << "Podaj dlugosc krawedzi" << endl;
	cin >> a;
	if (a <= 0){
		cout << "Liczba mniejsza od 0." << endl;
		system("pause");
		return 0;
	}
	cout << "Podaj wysokosc graniastoslupa";
	cin >> h;
	if (h <= 0){
		cout << "Liczba mniejsza od 0." << endl;
		system("pause");
		return 0;
	}
	v = pole_podstawy(a)*h;
	cout << "Objetosc wynosi: " << v << endl;
	system("pause");
	return 0;
}