#include <iostream>
#include <typeinfo>
using namespace std;

void give_me_iteration(int a, int b){
	/*
	2 3 - a < b
	3 2 - a > b
	*/
	if (a < b){
		for (int i = a; i <= b; i = i + 1){
			cout << i << " ";
		}
	}
	if (a > b){
		for (int i = b; i <= a; i = i + 1){
			cout << i << " ";
		}
	}
	if (a == b){
		cout << a << " ";
	}
	cout << endl;
}

int main(){
	int limit = 0;
	int counter = 0;
	int a, b;
	string buffer = "";
	cout << "Podaj libcze zestawow:" << endl;
	cin >> limit;
	while (limit > counter){
		counter += 1;
		cout << "Podaj zestaw (po kazdej liczbie (calkowitej!) wcisnij ENTER):" << endl;
		cin >> a;
		cin >> b;
		give_me_iteration(a, b);
		a = 0;
		b = 0;
	}
	system("pause");
	return 0;
}