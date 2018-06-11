#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <ctime>
using namespace std;
typedef int(*functiontype)();
const int ARRAY_SIZE = 200;

int get_random_number() {
	return rand() % 100;
}

int ret_0() {
	return 0;
}

void fill_array_with(int arr[], int arr_size, functiontype func) {
	/*
	iterate over arr
	call func and asign the value to the array
	*/
	for (int i = 0; i < arr_size; i++) {
		arr[i] = (*func)();
	}
}

bool ascending(int i, int j) {
	return i < j;
}

bool descending(int i, int j) {
	return i > j;
}

void sort_me(int arr[], int arr_size, int sort_type) {
	if (sort_type == 1) {
		sort(arr, arr + arr_size, descending);
	}
	if (sort_type == 2) {
		sort(arr, arr + arr_size, ascending);
	}
}

static vector<int> check_for_num(int arr[], int arr_size, int num) {
	static vector<int> nums;
	for (int i = 0; i < arr_size; i++) {
		if (arr[i] == num) {
			nums.push_back(i);
		}
	}
	return nums;
}

int main() {
	int arr[ARRAY_SIZE];
	int sort_how = -1;
	int num = -1;
	bool running = true;
	srand(time(NULL));
	fill_array_with(arr, ARRAY_SIZE, *ret_0);
	fill_array_with(arr, ARRAY_SIZE, *get_random_number);
	cout << "Wybierz w jaki sposob posortowac tablice:" << endl;
	while (running) {
		cout << "[1]. Malejaco\n[2]. Rosnaco" << endl;
		cout << ">>>\t";
		cin >> sort_how;
		if (cin.fail())
		{
			// clear error state
			cin.clear();
			// discard 'bad' character(s)
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		switch (sort_how)
		{
		default:
			cout << "Wybierz prawidlowa funkcje programu" << endl;
			break;
		case 1:
			sort_me(arr, ARRAY_SIZE, 1);
			running = false;
			break;
		case 2:
			sort_me(arr, ARRAY_SIZE, 2);
			running = false;
			break;
		case -1:
			cout << "Wybierz prawidlowa funkcje programu" << endl;
			break;
		}
	}
	running = true;
	while (running) {
		cout << "Jakiej liczby szukac? (0, 100)" << endl;
		cout << ">>>\t";
		cin >> num;
		if (cin.fail())
		{
			// clear error state
			cin.clear();
			// discard 'bad' character(s)
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (num >= 0 && num <= 100) {
			running = false;
		}
	}

	vector<int> vect_block = check_for_num(arr, ARRAY_SIZE, num);
	for (std::vector<int>::iterator it = vect_block.begin(); it != vect_block.end(); ++it) {
		cout << *it+1 << endl;
	}
	system("PAUSE");
	return 0;
}