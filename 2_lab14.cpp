#include <iostream>
using namespace std;

class Silnik {
public:
	int moc;
	int pojemnosc;
	Silnik(int m, int p) {
		moc = m;
		pojemnosc = p;
	}
};

class Samochod {
public:
	Silnik silnik = Silnik(0,0);
	char* model;
	char* producent;
	Samochod(char* pr, char* md, int m, int p) {
		silnik = Silnik(m, p);
		model = md;
		producent = pr;
	}
	void wyswietl() {
		cout << "Moc: " << silnik.moc << " Pojemnosc: " << silnik.pojemnosc << endl;
		cout << "Producent: " << producent << " Model: " << model << endl;
	}
};

int main() {
	Samochod car = Samochod((char*)"Opel", (char*)"Astra", 250, 3000);
	car.wyswietl();
	system("pause");
	return 0;
}