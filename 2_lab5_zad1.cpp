#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

class Stozek{
public:
	Stozek();
	Stozek(double, double);
	double pole_calk(){
		double pp = M_PI*pow(this->r, 2);
		double pb = M_PI*this->r*this->l;
		return pp + pb;
	}
	double objetosc(){
		return (M_PI*pow(this->r, 2)*this->h)/3;
	}
	double daj_tworzaca(){
		this->oblicz_tworzaca();
		return this->l;
	}
private:
	double h;
	double r;
	double l;
	void oblicz_tworzaca(){
		this->l = sqrt(pow(this->r, 2) + pow(this->h, 2));
	}
};
Stozek::Stozek(){
	this->h = 5;
	this->r = 5;
	this->oblicz_tworzaca();
}
Stozek::Stozek(double height, double radius){
	this->h = height;
	this->r = radius;
	this->oblicz_tworzaca();
}

int main(){
	Stozek Pierwszy;
	cout << "Stworzono pierwszy obiekt stozka." << endl;
	double h = 0;
	double r = 0;
	cout << "Podaj wartosci drugiego stozka." << endl;
	cout << "Wysokosc: ";
	cin >> h;
	cout << "Promien: ";
	cin >> r;
	Stozek Drugi(h, r);
	cout << "Stworzono drugi obiekt stozka." << endl;
	system("cls");
	cout << "Stozek #1" << endl;
	cout << "Pole: " << Pierwszy.pole_calk() << " Objetosc: " << Pierwszy.objetosc() << " Tworzaca: " << Pierwszy.daj_tworzaca() << endl << endl;
	cout << "---------------" << endl;
	cout << "Stozek #2" << endl;
	cout << "Pole: " << Drugi.pole_calk() << " Objetosc: " << Drugi.objetosc() << " Tworzaca: " << Drugi.daj_tworzaca() << endl << endl;
	system("pause");
	return 1;
}