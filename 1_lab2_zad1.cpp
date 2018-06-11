#pragma warning (disable : 4996)
#include <math.h>
#include <iostream>

using namespace std;

int main(){
	double a = 0.0;
	double b = 0.0;
	double w = 0.0;
	cout << "Podaj liczbe a:" << endl;
	cin >> a;
	cout << "Podaj liczbe b:" << endl;
	cin >> b;
	//1. 
	w = pow(pow(a, 2.0) - pow(b, 2.0), 4.0) * pow(pow(a, 3.0) + pow(b, 3.0), 6.0);
	cout << "Wynik 1: " << w << endl;
	//2.
	if (a == 0 && b == 0){
		cout << "Wynik 2: brak, poniewa¿ a i b równe 0" << w << endl;
	}
	else{
		w = sqrt(pow(pow(a, 2.0) + pow(b, 2.0), 3.0));
		cout << "Wynik 2: " << w << endl;
	}
	//3.
	w = (1.0 / 231.0)*(pow(a, 2.0) + (a*b) + pow(b, 2.0));
	cout << "Wynik 3: " << w << endl;
	//4.
	w = (7.0 / 8.0)*(a + (b* (1.0+(a*(a+b)))) + (a*b));
	cout << "Wynik 4: " << w << endl;
	//5.
	if (((4 + pow(b, 2.0)) == 0)){
		cout << "Wynik 5: brak, poniewa¿ 4+b^2 = 0" << w << endl;
	}
	else if((1+pow(a, 2.0)) == 0){
		cout << "Wynik 5: brak, poniewa¿ 1+a^2 = 0" << w << endl;
	}
	else{
		w = ((1.0 - pow(a, 2.0)) / (1.0 + pow(a, 2.0)))*sqrt((4 + pow(b, 2.0)));
		cout << "Wynik 5: " << w << endl;
	}
	//6.
	if ((4.0 - pow(b, 2.0)) == 0){
		cout << "Wynik 6: brak, poniewa¿ 4-b^2 = 0" << endl;
	}
	else if ((1.0 - pow(a, 2.0)) == 0){
		cout << "Wynik 6: brak, poniewa¿ 1-a^2 = 0" << endl;
	}
	else{
		w = ((4.0 + pow(b, 2.0)) / (4 - pow(b, 2.0))) * ((1.0 + pow(a, 2.0)) / (1.0 - pow(a, 2.0)));
		cout << "Wynik 6: " << w << endl;
	}
	system("pause");
	return 0;
}