#include <iostream>

using namespace std;

int main(){
	const int ARRAY_SIZE = 100;
	int table [ARRAY_SIZE];
	int n;
	cout << "Podaj ilosc liczb" << endl;
	cin >> n;
	if (n < 0){
		cout << "Wprowadzono n mniejsze od 0" << endl;
		system("PAUSE");
		return -1;
	}
	cout << "Po kazdej liczbie nacisnij ENTER lub RETURN" << endl;
	for (int i = 0; i < n; i++){
		cin >> table[i];
	}
	int max_var = table[0];
	for (int j = 0; j < n; j++){
		if (max_var < table[j]){
			max_var = table[j];
			
		}
	}
	cout << max_var << endl;
	system("pause");
	return 0;
}