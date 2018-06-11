#include <iostream>
#include <string>
using namespace std;

class Zamowienie {
private:
	string nazwa_produktu;
	double cena_produktu;
	string data_zakupu;
	int liczba_sztuk;
public:
	void zapisz_dane(string nazwa_produktu_, double cena_produktu_, string data_zakupu_, int ilosc) {
		this->nazwa_produktu = nazwa_produktu_;
		this->cena_produktu = cena_produktu_;
		this->data_zakupu = data_zakupu_;
		this->liczba_sztuk = ilosc;
	}
	void wyswietl_dane() {
		cout << "--------------------" << endl;
		cout << "Nazwa: " << this->nazwa_produktu.c_str() << endl;
		cout << "Cena: " << this->cena_produktu << endl;
		cout << "Data zakupu: " << this->data_zakupu.c_str() << endl;
		cout << "Liczba sztuk: " << this->liczba_sztuk << endl;
		cout << "Calkowity koszt: " << this->podaj_koszt() << endl;
		cout << "--------------------" << endl;
	}
	string podaj_nazwe_produktu() { return this->nazwa_produktu; }
	double podaj_cene() { return this->cena_produktu; }
	string podaj_date_zakupu() { return this->data_zakupu; }
	int podaj_liczbe_sztuk() { return this->liczba_sztuk; }
	double podaj_koszt() { return this->liczba_sztuk*this->cena_produktu; }
};

int main() {
	string nazwa = "";
	double cena = 0.0;
	string data = "";
	int sztuki = 0;
	bool good = false;
	Zamowienie pierwsze;
	cout << "Podaj nazwe zamowienia: " << endl;
	getline(cin, nazwa);
	while (!good) {
		cout << "Podaj cene: " << endl;
		cin >> cena;
		if (cena <= 0)
			cout << "Cena nie moze byc mniejsza od zera" << endl;
		if (!(cena <= 0))
			good = true;
	}
	good = false;
	cout << "Podaj date: " << endl;
	cin.ignore();
	getline(cin, data);
	cout << "Podaj ilosc: " << endl;
	cin >> sztuki;
	cin.ignore();
	pierwsze.zapisz_dane(nazwa, cena, data, sztuki);
	string nazwa_ = "";
	double cena_ = 0.0;
	string data_ = "";
	int sztuki_ = 0;
	Zamowienie drugie;
	cout << "Podaj nazwe zamowienia: " << endl;
	getline(cin, nazwa_);
	while (!good) {
		cout << "Podaj cene: " << endl;
		cin >> cena_;
		if (cena_ <= 0)
			cout << "Cena nie moze byc mniejsza od zera" << endl;
		if (!(cena_ <= 0))
			good = true;
	}
	cin.ignore();
	cout << "Podaj date: " << endl;
	getline(cin, data_);
	cout << "Podaj ilosc: " << endl;
	cin >> sztuki_;
	drugie.zapisz_dane(nazwa_, cena_, data_, sztuki_);
	system("pause");
	system("cls");
	pierwsze.wyswietl_dane();
	drugie.wyswietl_dane();
	system("pause");
}