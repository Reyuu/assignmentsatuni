#include <iostream>
#include <random>
using namespace std;

bool generate(int *vector1, int wsp_w1, int *vector2, int wsp_w2){
	random_device rd;
	default_random_engine generator(rd());
	uniform_int_distribution<int> distribution(-100, 100);
	cout << "Wektor 1 o dlugosci " << wsp_w1 << " vector1[ ";
	for (int i = 0; i < wsp_w1; i++){
		while (true){
			int random = distribution(generator);
			if (random % 2 == 0){
				vector1[i] = random;
				cout << vector1[i];
				break;
			}
		}
		if (i != (wsp_w1 - 1)){
			cout << ", ";
		}
	}
	cout << " ]" << endl;
	cout << "Wektor 2 o dlugosci " << wsp_w2 << " vector2[ ";
	for (int i = 0; i < wsp_w2; i++){
		while (true){
			int random = distribution(generator);
			if (random % 2 != 0){
				vector2[i] = random;
				cout << vector2[i];
				break;
			}
		}
		if (i != (wsp_w2 - 1)){
			cout << ", ";
		}
	}
	cout << " ]" << endl;
	return true;
}

int multiply(int *vector1, int wsp_w1, int *vector2, int wsp_w2, bool &multiply_possible){
	if (wsp_w1 > wsp_w2){
		cout << "Mnozenie niewykonalne: Wektor 1 ma wieksza ilosc wspolrzednych: " << wsp_w1 << " < " << wsp_w2 << endl;
		multiply_possible = false;
		return 0;
	}
	else if (wsp_w2 > wsp_w1){
		cout << "Mnozenie niewykonalne: Wektor 2 ma wieksza ilosc wspolrzednych: " << wsp_w2 << " < " << wsp_w1 << endl;
		multiply_possible = false;
		return 0;
	}
	long int result = 0;
	for (int i = 0; i < wsp_w1; i++){
		result += vector1[i] * vector2[i];
	}
	return result;
}

int main()
{
	int *vector1;
	int *vector2;
	int wsp_w1 = 0;
	int wsp_w2 = 0;
	bool multiply_possible = true;
	cout << "Podaj ilosc wspolrzednych wektora 1:" << endl;
	std::cin >> wsp_w1;
	cout << "Podaj ilosc wspolrzednych wektora 2:" << endl;
	std::cin >> wsp_w2;
	if (wsp_w1 < 0 || wsp_w2 < 0){
		cout << "Wektor nie moze miec ujemnej ilosci wspolrzednych!" << endl;
		system("pause");
		return -1;
	}
	vector1 = new int[wsp_w1];
	vector2 = new int[wsp_w2];

	generate(vector1, wsp_w1, vector2, wsp_w2);

	long int wynik = multiply(vector1, wsp_w1, vector2, wsp_w2, multiply_possible);
	if (multiply_possible){
		cout << "Wynik mnozenia: " << wynik << endl;
	}
	system("pause");
	return 0;
}