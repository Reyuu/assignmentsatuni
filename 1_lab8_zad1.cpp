#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  /* time */
using namespace std;
const int zbior_liczb = 99;

const int ilosc_losowanych = 100;
int random_my_number_dawg();

int random_my_number_dawg(){
	bool satisfied = false;
	while (satisfied == false){
		int randomised = rand() % zbior_liczb;
		//liczba niepatrzysta
		if (randomised % 2 == 1){
			satisfied = true;
			return randomised;
		}
	}
}

void to_zero(int tab[]){
	for (int i = 1; i < zbior_liczb; i++){
		tab[i] = 0;
	}
}

void random_all_the_nums(int tab[]){
	for (int i = 0; i < ilosc_losowanych; i++){
		int losnieta = random_my_number_dawg();
		tab[losnieta] += 1;
	}
}

void print_all_the_nums(int tab[]){
	for (int i = 1; i < zbior_liczb; i = i + 2){
		if (tab[i] == 1){
			cout << i << endl;
		}
	}
}
int main(){
	int powtarzane_liczby[zbior_liczb];
	//define all to 0
	to_zero(powtarzane_liczby);
	//seed random with NULL value
	srand(time(NULL));
	//random the numbers and increment the value of occurences
	random_all_the_nums(powtarzane_liczby);
	//sort the values and save max value and index of the value
	print_all_the_nums(powtarzane_liczby);
	system("pause");
	return 1;
}