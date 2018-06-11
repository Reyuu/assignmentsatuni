#include <iostream>
#include <cstdlib>
using namespace std;

int get_length(char* word) {
	char *w = word;
	int a = 0;
	while (*w)
	{
		w++;
		a++;
	}
	return a;
}

void find_longest_common_str(int tab[][100], int word1_len, int word2_len, char word1[], char word2[], int *p, int *max) {
	for (int i = 1; i <= word1_len; i++) {
		for (int j = 1; j <= word2_len; j++) {
			if (word1[i - 1] != word2[j - 1]) tab[i][j] = 0;
			else {
				tab[i][j] = tab[i - 1][j - 1] + 1;
				if (tab[i][j] > *max) {
					*max = tab[i][j];
					*p = i;
				}
			}
		}
	}
}

int main()
{
	char word1[100];
	char word2[100];
	cout << "Podaj pierwsze slowo: " << endl;
	cin >> word1;
	cout << "Podaj drugie slowo: " << endl;
	cin >> word2;
	int word1_len = get_length(word1); //podsłowo jeden
	int word2_len = get_length(word2); //podsłowo dwa
	int max = 0;
	int p = 0;
	int tab[100][100];
	for (int h = 0; h < 100; h++) {
		tab[0][h] = tab[h][0] = 0;
	}
	find_longest_common_str(tab, word1_len, word2_len, word1, word2, &p, &max);
	if (max != 0){
		cout << "Najwiekszym wspolnym ciagiem znakow jest: ";
		for (int i = 0; i < max; i++) {
			cout << word1[p + i - max];
		}
	}
	cout << endl << "Jego dlugosc to: " << max << endl;
	system("PAUSE");
	return 0;
}