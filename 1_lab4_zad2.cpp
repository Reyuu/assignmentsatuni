#include <iostream>

using namespace std;

int main(){
	int a1, a2, a3, b1, b2, b3;
	cout << "Podaj predkosci robota A:" << endl;
	cin >> a1 >> a2 >> a3;
	if (a1 <= 0 || a2 <= 0 || a3 <= 0){
		cout << "Podano wartosc ujemnosc" << endl;
		system("PAUSE");
		return -1;
	}
	cout << "Podaj predkosci robota B:" << endl;
	cin >> b1 >> b2 >> b3;
	if (b1 <= 0 || b2 <= 0 || b3 <= 0){
		cout << "Podano wartosc ujemnosc" << endl;
		system("PAUSE");
		return -1;
	}
	double o1, o2, o3;
	double robota, robotb;
	o1 = 1;
	o2 = 2*o1;
	o3 = 3*o2;
	robota = (a1 / o1) + (a2 / o2) + (a3 / o3);
	robotb = (b1 / o1) + (b2 / o2) + (b3 / o3);
	if (robota > robotb){
		cout << "Wygral robot A!" << endl;
	}
	else{
		cout << "Wygral robot B!" << robotb << endl;
	}
	system("PAUSE");
	return 0;
}