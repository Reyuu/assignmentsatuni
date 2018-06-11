#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

int main() {
	vector<string> a;
	list<string> b;

	bool running = true;
	cout << "Wprowadzanie slow (wprowadz ##END## aby zakonczyc): " << endl;
	while (running) {
		string temp;
		cout << ">>>";
		cin >> temp;
		cout << endl;
		if (temp == "##END##") {
			running = false;
		}
		else {
			a.push_back(temp);
			b.push_back(temp);
		}
	}
	string szukane;
	cout << "Wprowadz slowo, ktorego szukasz: " << endl;
	cout << ">>>";
	cin >> szukane;
	cout << endl;
	int found = 0;
	cout << "Lista: " << endl;
	for (list<string>::iterator it = b.begin(); it != b.end(); it++) {
		if (*it == szukane) {
			found += 1;
			cout << distance(b.begin(), it) << ". " << *it << endl;
		}
	}
	if (found == 0) {
		cout << "Brak slowa w liscie" << endl;
	}
	found = 0;
	cout << "Wektor: " << endl;
	for (vector<string>::iterator it = a.begin(); it != a.end(); it++) {
		if (*it == szukane) {
			found += 1;
			cout << distance(a.begin(), it) << ". " << *it << endl;
		}
	}
	if (found == 0) {
		cout << "Brak slowa w wektorze" << endl;
	}
	system("PAUSE");
}