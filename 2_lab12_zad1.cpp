#include <iostream>
using namespace std;

class Nazwisko {
private:
	char* nazwisko;
public:
	Nazwisko(char* n) {
		nazwisko = n;
		cout << "Konstruktor Nazwisko ze zmienna:\t" << nazwisko << endl;
	};
	~Nazwisko() {
		cout << "Destruktor Nazwisko ze zmienna:\t" << nazwisko << endl;
		if (nazwisko != NULL) {
			delete nazwisko;
			nazwisko = NULL;
		}
	}
};

class Pelne : public Nazwisko {
private:
	char* imie;
public:
	Pelne(char* i, char* n) : Nazwisko(n){
		imie = i;
		cout << "Konstruktor Imie ze zmienna:\t" << imie << endl;
	};
	~Pelne(){
		cout << "Destruktor Imie ze zmienna:\t" << imie << endl;
		if (imie != NULL) {
			delete imie;
			imie = NULL;
		}
	};
};

int main() {
	Nazwisko* a = new Pelne((char*)"John", (char*)"Smith");
	delete a;
	system("pause");
	return 0;
}