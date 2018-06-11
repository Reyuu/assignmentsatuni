#include <iostream>
#include <random>
#include <ctime>
using namespace std;
typedef int(*functiontype)();
const int ARRAY_SIZE = 200;

int get_random_number() {
	return rand() % 100000;
}

void fill_array_with(int arr[], functiontype func) {
	/*
	iterate over arr
	call func and asign the value to the array
	*/
	for (int i = 0; i < ARRAY_SIZE; i++) {
		arr[i] = (*func)();
	}
}

int count_digits(int x) {
	int length = 1;
	while (x /= 10)
		length++;
	return length;
}

int compare_arrays(int arr1[], int arr2[], int n, int result_arr[]) {
	int arr_1_count = 0;
	int arr_2_count = 0;
	int result_array[2];
	for (int i = 0; i < ARRAY_SIZE; i++) {
		int temp1 = count_digits(arr1[i]);
		int temp2 = count_digits(arr2[i]);
		if (temp1 == n)
			arr_1_count++;
		if (temp2 == n)
			arr_2_count++;
	}
	if (arr_1_count > arr_2_count) {
		result_arr[0] = 1;
		result_arr[1] = arr_1_count;
	}
	if (arr_2_count > arr_1_count) {
		result_arr[0] = 2;
		result_arr[1] = arr_2_count;
	}
	if (arr_1_count == arr_2_count) {
		result_arr[0] = 0;
		result_arr[1] = arr_1_count;
	}
	return 2;
}

int ret_0(){
	return 0;
}

int main()
{
	bool num_correct = false;
	int num = 0;
	int arr_one[ARRAY_SIZE];
	int arr_two[ARRAY_SIZE];
	int result_array[2];
	fill_array_with(arr_one, *ret_0);
	fill_array_with(arr_two, *ret_0);
	srand(time(NULL));
	fill_array_with(arr_one, *get_random_number);
	fill_array_with(arr_two, *get_random_number);
	cout << "Wprowadz liczbe (od 1 do 6):" << endl;
	cout << ">>>\t";
	while (num_correct == false) {
		cin >> num;
		if (cin.fail())
		{
			// clear error state
			cin.clear();
			// discard 'bad' character(s)
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (num >= 1 && num <= 6)
			num_correct = true;
		else {
			num = 0;
			cout << "\nWprowadzno zbyt duza lub niska liczbe(od 1 do 6):" << endl;
			cout << ">>>\t";
		}
	}
	compare_arrays(arr_one, arr_two, num, result_array);
	switch (result_array[0])
	{
	default:
		cout << "Nieznany blad" << endl;
		break;
	case 0:
		cout << "Obie tablice zawieraly tyle samo elementow z liczba cyfr " << num << " i bylo ich " << result_array[1] << endl;
		break;
	case 1:
	case 2:
		cout << "Tablica z numerem " << result_array[0] << " miala wiecej elementow z liczba cyfr " << num << " i bylo ich " << result_array[1] << endl;
		break;
	}
	system("pause");
}
