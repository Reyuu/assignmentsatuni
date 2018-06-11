#include <iostream>
using namespace std;

//zad1
long long silnia(int n, int *pc)
{
	(*pc)++;
	if (n == 0) return 1;
	else return n*silnia(n - 1, pc);
}

//zad2
int nwd(int a, int b){
	if (a == b)
		return a;
	if (a > b){
		a = a - b;
		return nwd(a, b);
	}
	if (a < b){
		b = b - a;
		return nwd(a, b);
	}
}

//zad3
int nwd2(int a, int b){
	if (a > b){
		a = a % b;
		if (a == 0)
			return b;
		return nwd(a, b);
	}
	if (a < b){
		b = b % a;
		if (b == 0)
			return a;
		return nwd(a, b);
	}
}

int main(){
	//zad1
	int pc = 0;
	int *pc_pntr = &pc;
	int s = 0;
	cout << "Podaj liczbe do obliczenia silnii" << endl;
	cin >> s;
	cout << "Silnia: " << silnia(s, pc_pntr) << endl;
	cout << "Ilosc wywolan rekurencyjnych: " << pc << endl;
	system("pause");
	//zad2
	int a = 0;
	int t = 0;
	cout << "Podaj liczby do obliczenia NWD" << endl;
	cin >> a;
	cin >> t;
	cout << nwd(a, t) << endl;
	system("pause");
	//zad3
	int x = 0;
	int y = 0;
	cout << "Podaj liczby do obliczenia NWD" << endl;
	cin >> x;
	cin >> y;
	cout << nwd2(x, y) << endl;
	system("pause");
}