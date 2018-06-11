#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  /* time */
using namespace std;
const int zbior_liczb = 101;
const int ilosc_losowanych = 1000000;
int random_my_number_dawg();

int random_my_number_dawg(){
	//random the number
	return (rand() % zbior_liczb);
}

int main(){
	int powtarzane_liczby[zbior_liczb];
	//define all to 0
	for (int i = 0; i < zbior_liczb; i++){
		powtarzane_liczby[i] = 0;
	}
	//seed random with NULL value
	srand(time(NULL));
	//random the numbers and increment the value of occurences
	for (int i = 0; i < ilosc_losowanych; i++){
		int losnieta = random_my_number_dawg();
		powtarzane_liczby[losnieta] += 1;
	}
	//sort the values and save max value and index of the value
	int max = 0;
	int index = 0;
	for (int i = 0; i < zbior_liczb; i++){
		if (powtarzane_liczby[i] > max){
			max = powtarzane_liczby[i];
			index = i;
		}
	}
	//print the values
	cout << "Wartosc: " << index << "\nIlosc powtorzen:" << max << endl;
	system("pause");
	return 1;
}