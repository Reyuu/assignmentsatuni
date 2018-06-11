#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double a, b, c;
	double x1, x2;
	double delta;
	double im, re;
	cout << "Pierwiastki trojmianu kwadratowego" << endl;
	cout << "Wspoilczynnik a:" << endl;
	cin >> a;
	if (a == 0){
		printf("Niepoprawna wartosc a!");
		system("PAUSE");
		return (-1);
	}
	cout << "Wspolczynnik b:" << endl;
	cin >> b;
	cout << "Wyraz wolny c:" << endl;
	cin >> c;
	delta = b * b - 4 * a * c;
	cout << "*** Wyniki obliczen ***" << endl;
	if (delta > 0){
		x1 = (-b - sqrt(delta)) / (2 * a);
		x2 = (-b + sqrt(delta)) / (2 * a);
		cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
	}
	else if (delta == 0){
		x1 = -b / (2 * a);
		cout << "x0 = " << x1 << endl;
	}
	else{
		re = -b / (2 * a);
		im = sqrt(abs(delta)) / (2 * a);
		cout << "x1 = " << re << " + (" << im << "*i)" <<endl;
		cout << "x2 = " << re << " - (" << im << "*i)" << endl;
	}
	system("PAUSE");
} 