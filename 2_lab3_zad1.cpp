#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

//circle, triangle, 4, 5, 6

int obwod(int a){
	return 2*M_PI*a;
}

int obwod(int a, int b, int c){
	return a+b+c;
}

int obwod(int a, int b, int c, int d){
	return a+b+c+d;
}

int obwod(int a, int b, int c, int d, int e){
	return a+b+c+d+e;
}

int obwod(int a, int b, int c, int d, int e, int f){
	return a+b+c+d+e+f;
}

int main(){
	int a, b, c, d, e, f;
	cout << "Podaj radius kola" << endl;
	cin >> a;
	cout << "L =";
	cout << obwod(a) << endl;
	cout << "Podaj boki trojkata" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	cout << "L =";
	cout << obwod(a, b, c) << endl;
	cout << "Podaj boki czworokata" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cout << "L =";
	cout << obwod(a, b, c, d) << endl;
	cout << "Podaj boki pieciokata" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cin >> e;
	cout << "L =";
	cout << obwod(a, b, c, d, e) << endl;
	cout << "Podaj boki pieciokata" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cin >> e;
	cin >> f;
	cout << "L =";
	cout << obwod(a, b, c, d, f) << endl;
	system("pause");
}
