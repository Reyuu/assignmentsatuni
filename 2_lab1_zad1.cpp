#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;
/*
int compute_a(int tab[], int len); //return a
int compute_b(int tab[], int len, double a); //return b
int* compute_c(int tab[], int len, double a, double b); //return pointer to arr to c
int* compute_d(int tab[], int len, double a);  //return pointer to arr d
int print_arr(int tab[], int len);
*/

template <typename T> T* create_arr(int len) {
	//usage: auto* a = create_arr<int>(5);
	T* arr;
	arr = new T[len];
	for (int i = 0; i < len; i++) {
		*(arr + i) = T(rand() % 1000);
	}
	return arr;
}

double compute_a(int *tab, int len) {
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += *(tab + i);
	}
	double pico = sum / len;
	return pico;
}

double compute_b(int *tab, int len, double a) {
	double sum = 0;
	for (int i = 0; i < len; i++) {
		sum += pow((*(tab + i) - a), 2);
	}
	return sqrt(sum / len);
}

int* compute_c(int *tab, int len, double aa, double bb) {
	double a = aa - bb;
	double b = aa + bb;
	int* tab2 = new int[len];
	for (int i = 0; i < len; i++) {
		if (*(tab + i) > a && *(tab + i) < b) {
			*(tab2 + i) = *(tab + i);
		}
		else {
			*(tab2 + i) = 0;
		}
	}
	return tab2;
}

int** compute_d(int* tab, int len, double a) {
	int **arr = new int*[len];
	for (int i = 0; i < len; i++) {
		*(arr + i) = new int[2];
	}

	for (int i = 0; i < len; i++) {
		if (*(tab + i) < a){
			*(*(arr + 1) + i) = 0;
			*(*arr + i) = *(tab + i);
		}
		else{
			*(*(arr + 1) + i) = *(tab + i);
			*(*arr + i) = 0;
		}
	}
	return arr;
}

void display(int* tab, int len) {
	cout << "{" << endl;
	for (int i = 0; i < len; i++) {
		cout << *(tab + i);
		if (!(i == len-1)) {
			cout << ", ";
		}
		if (i % 4 == 0 && !(i == 0) && !(i==len-1)) {
			cout << endl;
		}
	}
	cout << endl << "}" << endl;
}

void display(int* tab, int** arr, int len, double a) {
	cout << "{" << endl;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 2; j++) {
			cout << *(*(arr + j)+i);
			if (!(i == (len-1) && j == 1)) {
				cout << ", ";
			}
		}
		cout << endl;
	}
	cout << "}" << endl;
}

int main() {
	int len;
	double a;
	double r;
	int* tab2;
	int** tab3;
	cout << "Ilosc elementow tablicy" << endl;
	cin >> len;
	auto* tab = create_arr<int>(len);
	a = compute_a(tab, len);
	r = compute_b(tab, len, a);
	tab2 = compute_c(tab, len, a, r);
	tab3 = compute_d(tab, len, a);
	cout << "Tabela przed zmianami:" << endl;
	display(tab, len);
	cout << "Tabela z punktu c:" << endl;
	display(tab2, len);
	tab3 = compute_d(tab, len, a);
	cout << "Tabela z punktu d:" << endl;
	display(tab, tab3, len, a);
	cout << "Srednia wartosc: " << a << " Odchylenie standardowe: " << r << endl;
	delete tab;
	delete tab2;
	delete tab3;
	system("pause");
	return 1;
}