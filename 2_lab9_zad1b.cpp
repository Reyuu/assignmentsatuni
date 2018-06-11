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
	Osoba(const Osoba &o);
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

Osoba::Osoba(const Osoba &o) {
	this->imie = o.imie;
	this->nazwisko = o.nazwisko;
	this->wiek = o.wiek;
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
	Osoba a = Osoba("Josh", "Witecki", 24);
	Osoba b = a;
	Osoba c = Osoba(a);

	b.zmien_imie("Gosh");
	a.pokaz();
	b.pokaz();
	c.pokaz();

	cout << "--------------" << endl;

	c.zmien_imie("Leth");
	a.pokaz();
	b.pokaz();
	c.pokaz();

	system("pause");
	return 0;
}