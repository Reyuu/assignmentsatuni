#include <string>
#include <iostream>
using namespace std;

class Urzadzenie{
protected:
	string firma;
	int obroty;
public:
	Urzadzenie(){};
	Urzadzenie(string, int);
	string daj_firme(){
		return firma;
	}
	int daj_obroty(){
		return obroty;
	}
	void pokaz_opis(){
		cout << "Firma: " << firma.c_str() << "\nObroty: " << obroty << endl;
	}
};

Urzadzenie::Urzadzenie(string f, int o){
	firma = f;
	obroty = o;
}

class SzlifierkaKatowa : public Urzadzenie{
private:
	int moc;
	int tarcza;
public:
	SzlifierkaKatowa(string, int, int, int);
	int daj_moc(){ return moc; }
	int daj_tarcze(){ return tarcza; }
	void pokaz_opis(){
		Urzadzenie::pokaz_opis();
		cout << "Moc: " << moc << endl;
		cout << "Tarcza: " << tarcza << endl;
	}
};

SzlifierkaKatowa::SzlifierkaKatowa(string f, int o, int m, int t) : Urzadzenie(f, o){
	moc = m;
	tarcza = t;
}

class WiertarkoWkretarka : public Urzadzenie{
private:
	double napiecie;
	string bateria;
	int czas_ladow;
public:
	WiertarkoWkretarka::WiertarkoWkretarka(string, int, double, string, int);
	double daj_napiecie(){ return napiecie; }
	string daj_baterie(){ return bateria; }
	int daj_czas_ladow(){ return czas_ladow; }
	void pokaz_opis(){
		Urzadzenie::pokaz_opis();
		cout << "Napiecie: " << napiecie << endl;
		cout << "Bateria: " << bateria << endl;
		cout << "Czas ladowania: " << czas_ladow << endl;
	}
};


WiertarkoWkretarka::WiertarkoWkretarka(string f, int o, double n, string b, int c) : Urzadzenie(f, o){
	napiecie = n;
	bateria = b;
	czas_ladow = c;
}

int main(){
	const int SIZE = 4;
	SzlifierkaKatowa a("Pez", 1450, 550, 14);
	SzlifierkaKatowa b("Rozczep", 2300, 350, 14);
	SzlifierkaKatowa c("Pil", 1600, 300, 16);
	SzlifierkaKatowa d("Rozczep", 1000, 200, 14);
	SzlifierkaKatowa arr_szli[SIZE] = { a, b, c, d };

	WiertarkoWkretarka e("Qill", 3000, 12.0, "LiIo", 600);
	WiertarkoWkretarka f("Loren", 2500, 12.5, "LiIo", 1200);
	WiertarkoWkretarka g("Ilen", 5000, 16.0, "LiMg", 2400);
	WiertarkoWkretarka h("Qill", 3400, 12.0, "LiIo", 500);
	WiertarkoWkretarka arr_wier[SIZE] = { e, f, g, h };

	int najkrotsza = 0;
	int najkrotsza_index = 0;
	int najwieksza = 0;
	int najwieksza_index = 0;
	for (int i = 0; i < SIZE; i++){
		if (arr_szli[i].daj_obroty() > najwieksza){
			najwieksza = arr_szli[i].daj_obroty();
			najwieksza_index = i;
		}
		if (i == 0){
			najkrotsza = arr_wier[i].daj_czas_ladow();
			najkrotsza_index = i;
		}
		if (arr_wier[i].daj_czas_ladow() < najkrotsza){
			najkrotsza = arr_szli[i].daj_obroty();
			najkrotsza_index = i;
		}
	}
	arr_wier[najkrotsza_index].pokaz_opis();
	cout << "--------------" << endl;
	arr_szli[najwieksza_index].pokaz_opis();
	system("pause");
}