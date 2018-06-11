#include <iostream>
using namespace std;

class Osoba {
private:
	char* imie = new char[32];
	char* nazwisko = new char[32];
	int wiek = 0;
public:
	Osoba();
	Osoba(const char*, const char*, int);
	~Osoba();
	void pokaz();
	void zmien_imie(const char*);
};

Osoba::Osoba() {
	cout << "Konstruktor Osoba @" << this << endl;
	fill(imie, imie + 32, 0);
	fill(nazwisko, nazwisko + 32, 0);
}

Osoba::Osoba(const char* i, const char* n, int w) {
	Osoba();
	this->imie = (char*)i;
	this->nazwisko = (char*)n;
	this->wiek = w;
}

Osoba::~Osoba() {
	cout << "Destruktor Osoba @" << this << endl;
}

void Osoba::pokaz() {
	cout << this->imie << " " << this->nazwisko << " " << this->wiek << endl;
}

void Osoba::zmien_imie(const char* i) {
	this->imie = (char*)i;
}

int main() {
	Osoba a = Osoba("Adi", "Marzewski", 20);
	Osoba b = a;
	b.zmien_imie("Rob");
	a.pokaz();
	cout << "---------" << endl;
	b.pokaz();
	system("pause");
	return 0;
}