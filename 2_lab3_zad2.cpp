#include <string>
#include <iostream>

using namespace std;


int wiekszy(int a, int b){
	if (a > b) return 1;
	if (a < b) return 2;
	if (a == b) return 0;
}

int wiekszy(double a, double b){
	a = a * 10000;
	a = floor(a) / 10000;
	b = b * 10000;
	b = floor(b) / 10000;
	if (a > b) return 1;
	if (a < b) return 2;
	if (a == b) return 0;
}

int wiekszy(char *a, char *b){
	int result = strcmp(a, b);
	if (result == 1) return 1;
	if (result == -1) return 2;
	if (result == 0) return 0;
}

void check_what_is_wiekszy(int a){
	if (a == 1)
		cout << "Pierwszy argument jest wiekszy" << endl;
	if (a == 2)
		cout << "Drugi argument jest wiekszy" << endl;
	if (a == 0)
		cout << "Oba argumenty sa rowne" << endl;
}

int main(){
	cout << "Podaj pierwszy ciag znakow ";
	char *a;
	a = new char[256];
	cin >> a;
	cout << "Podaj drugi ciag znakow ";
	char *b;
	b = new char[256];
	cin >> b;
	check_what_is_wiekszy(wiekszy(a, b));
	
	double c, d;
	cout << "Podaj pierwsza liczbe rzeczywista ";
	cin >> c;
	cout << "Podaj druga liczbe rzeczywista ";
	cin >> d;
	check_what_is_wiekszy(wiekszy(c, d));

	int e, f;
	cout << "Podaj pierwsza liczbe calkowita ";
	cin >> e;
	cout << "Podaj druga liczbe calkowita ";
	cin >> f;
	check_what_is_wiekszy(wiekszy(e, f));
	system("pause");
	return 0;
}