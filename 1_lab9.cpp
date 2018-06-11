#include <iostream>
#include <math.h>
const int MAX_ARGS = 3;
/*
suma, ró¿nica, iloczyn, iloraz(nie da siê przez zero), wartoœæ bezwzglêdna, pierwiastek kwadratowy(ujemna te¿), potêga

err_codes:
- 0 - not ok - NO STOP
- 1 - ok - proceed
- 2 - potêga 0
*/
using namespace std;
int is_result_possible(char operrand[], double a);
int is_result_possible(char operrand[], double a, double b);
int is_result_possible(char operrand[], double a, double b, double c);
void suma(double a, double b);
void roznica(double a, double b);
void iloczyn(double a, double b);
void iloraz(double a, double b);
void bezwzg(double a);
void potega(double a, double b);
void pierwiastek(double a);
void main();

int is_result_possible(char operrand[], double a){
	if (operrand == "s"){
		if (a < 0){
			return 0;
		}
		return 1;
	}
	return 1;
}

int is_result_possible(char operrand[], double a, double b){
	if (operrand == "/"){
		if (b == 0){
			cout << "Nie dziel przez 0! Dzialanien nie moze byc wykonane" << endl;
			return 0;
		}
		return 1;
	}
	if (operrand == "^"){
		if (b == 0){
			return 2;
		}
		if (a == 0 && b < 0){
			cout << "Nie pierwiastkuj zera przez liczby ujemne! Dzialanien nie moze byc wykonane" << endl;
			return 0;
		}
		return 1;
	}
	return 1;
}

void suma(double a, double b, int& result){
	if (result == 1){
		cout << a + b << endl;
	}
}

void roznica(double a, double b, int& result){
	if (result == 1){
		cout << a - b << endl;
	}
}

void iloczyn(double a, double b, int& result){
	if (result == 1){
		cout << a * b << endl;
	}
}

void iloraz(double a, double b, int& result){
	if (result == 1){
		cout << a / b << endl;
	}
}

void bezwzg(double a, int& result){
	if (result == 1){
		cout << abs(a) << endl;
	}
}

void potega(double a, double b, int& result){
	if (result == 1){
		cout << pow(a, b) << endl;
	}
}

void pierwiastek(double a, int& result){
	if (result == 1){
		cout << sqrt(a) << endl;
	}
}

void main(){
	bool wyjscie = false;
	while (wyjscie == false){
		int num;
		double a = 0;
		double b = 0;
		double c = 0;
		int result_code = 1;
		cout << "Wybierz dzialanie:\n [1] Dodawanie, [2] Odejmowanie, [3] Mnozenie, [4] Dzielenie,\n[5] Wartosc bezwzgledna, [6] Potegowanie, [7] Pierwiastkowanie kwadratowe\n[8] Wyjscie" << endl;
		cin >> num;
		switch (num)
		{
		default:
			cout << "Nie wybrano dzialania." << endl;
			break;
		case 1:
			cin >> a;
			cin >> b;
			result_code = is_result_possible("+", a, b);
			suma(a, b, result_code);
			break;
		case 2:
			cin >> a;
			cin >> b;
			result_code = is_result_possible("-", a, b);
			roznica(a, b, result_code);
			break;
		case 3:
			cin >> a;
			cin >> b;
			result_code = is_result_possible("*", a, b);
			iloczyn(a, b, result_code);
			break;
		case 4:
			cin >> a;
			cin >> b;
			result_code = is_result_possible("/", a, b);
			iloraz(a, b, result_code);
			break;
		case 5:
			cin >> a;
			result_code = is_result_possible("a", a);
			bezwzg(a, result_code);
			break;
		case 6:
			cin >> a;
			cin >> b;
			result_code = is_result_possible("^", a, b);
			potega(a, b, result_code);
			break;
		case 7:
			cin >> a;
			result_code = is_result_possible("s", a);
			pierwiastek(a, result_code);
			break;
		case 8:
			wyjscie = true;
			break;
		}
	}
}