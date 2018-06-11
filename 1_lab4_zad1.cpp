#include <iostream>
#include <array>

using namespace std;
int main(){
	int w1, w2, w3;
	cout << "Wpisz pierwsza liczbe " << endl;
	cin >> w1;
	cout << "Wpisz druga liczbe " << endl;
	cin >> w2;
	cout << "Wpisz trzecia liczbe " << endl;
	cin >> w3;
	if (w1 < 0 || w2 < 0 || w3 < 0){
		cout << "Jedna z liczb jest ujemna" << endl;
		system("pause");
		return -1;
	}
	//Rozwi¹zanie array
	array<int, 3> nums = { w1 % 10, w2 % 10, w3 % 10 };
	array<int, 3>::iterator itr1 = nums.begin();
	array<int, 3>::iterator itr2 = nums.end();
	sort(itr1, itr2);
	cout << "Odpowiedz (array) to: " << nums[0] << endl;
	//Rozwi¹zanie warunkowo
	if (w1 > 0 && w2 > 0 && w3 > 0) {
		int a1 = w1 % 10;
		int b1 = w2 % 10;
		int c1 = w3 % 10;
		if (a1 < b1){
			if (a1 < c1){
				cout << "Odpowiedz (warunkowo) to: " << a1 << endl;
			}
			else{
				cout << "Odpowiedz (warunkowo) to: " << c1 << endl;
			}
		}
		else{
			if (b1 < c1){
				cout << "Odpowiedz (warunkowo) to: " << b1 << endl;
			}
			else {
				cout << "Odpowiedz (warunkowo) to: " << c1 << endl;
			}
		}
	}
	else {
		cout << "Jedna lub wiecej liczb nie spelnia warunkow zadania";
		system("PAUSE");
		return 0;
	}
	system("PAUSE");
	return 0;
	system("PAUSE");
}