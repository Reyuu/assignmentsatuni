#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include <regex>

using namespace std;

static int count_s = 0;
static int count_o = 0;

const int MAX_ARR_SIZE = 200;

void tokenize(std::string str, std::vector<string> &token_v) {
	size_t start = str.find_first_not_of(","), end = start;

	while (start != std::string::npos) {
		// Find next occurence of delimiter
		end = str.find(",", start);
		// Push back the token found into vector
		token_v.push_back(str.substr(start, end - start));
		// Skip all occurences of the delimiter to find new start
		start = str.find_first_not_of(",", end);
	}
}

class Sprzet {
private:
	int id;
	string type;
public:
	Sprzet() {
		set_id(count_s);
		set_type("none");
		count_s += 1;
	};
	Sprzet(const char* a) {
		set_id(count_s);
		set_type(a);
		count_s += 1;
	};
	Sprzet(int i, const char* a) {
		set_id(i);
		set_type(a);
	};
	void set_id(int i) {
		id = i;
	};
	void set_type(const char* a) {
		if (a == "rower" || a == "hulajnoga" || a == "rolki" || a == "none") {
			type = string(a);
		}
	};
	int get_id() { return id; };
	string get_type() { return type; };
};

class Osoba {
private:
	int id;
	string nazwisko;
	int wiek;
public:
	Osoba() {
		set_id(count_o);
		set_nazwisko("Smith");
		set_wiek(16 + rand() % 50);
		count_o += 1;
	};
	Osoba(const char* a) {
		set_id(count_o);
		set_nazwisko(a);
		set_wiek(18 + rand() % 50);
		count_o += 1;
	};
	Osoba(const char* a, int w) {
		set_id(count_o);
		set_nazwisko(a);
		set_wiek(w);
		count_o += 1;
	};
	Osoba(int i, const char* a, int w) {
		set_id(i);
		set_nazwisko(a);
		set_wiek(w);
	};
	void set_id(int i) {
		id = i;
	};
	void set_nazwisko(const char* a) {
		nazwisko = string(a);
	};
	void set_wiek(int i) { wiek = i; };
	int get_id() { return id; };
	string get_nazwisko() { return nazwisko; };
	int get_wiek() { return wiek; };
};

class Wypozyczenie {
private:
	int id_sprzet;
	int id_osoba;
public:
	Wypozyczenie() {
		id_sprzet = -1;
		id_osoba = -1;
	};
	Wypozyczenie(int i_os, int i_s) {
		id_osoba = i_os;
		id_sprzet = i_s;
	}
	void set_id_osoba(int i) { id_osoba = i; };
	void set_id_sprzet(int i) { id_sprzet = i; };
	int get_id_osoba() { return id_osoba; };
	int get_id_sprzet() { return id_sprzet; };
};

void save_data(Osoba* os, Sprzet* sp, Wypozyczenie* wy) {

	ofstream f;
	f.open("osoby.txt");
	for (int i = 0; i < MAX_ARR_SIZE; i++) {
			f << (os+i)->get_id() << "," << (os + i)->get_nazwisko() << "," << (os + i)->get_wiek() << endl;
		}
		f.close();
	f.open("sprzet.txt");
		for (int i = 0; i < MAX_ARR_SIZE; i++) {
			f << (sp+i)->get_id() << "," << (sp + i)->get_type() << endl;
		}
		f.close();
		f.open("wypozyczenia.txt");
		for (int i = 0; i < MAX_ARR_SIZE; i++) {
			f << (wy+i)->get_id_osoba() << "," << (wy + i)->get_id_sprzet() << endl;
		}
		f.close();
}

void load_data(Osoba* os, Sprzet* sp, Wypozyczenie* wy) {
	ifstream f;
	ifstream f2;
	ifstream f3;
	f.open("osoby.txt");
	int count = 0;
	string x;
	vector<string> after_commas;
	vector<string> after_commas2;
	vector<string> after_commas3;
	while (getline(f, x)) {
		after_commas.clear();
		tokenize(x, after_commas);
		cout << after_commas[0] << after_commas[1] << after_commas[2] <<endl;
		(os + count)->set_id(stoi(after_commas[0]));
		(os + count)->set_nazwisko((char*)after_commas[1].c_str());
		(os + count)->set_wiek(stoi(after_commas[2]));
		count++;
	}
	f.close();
	count = 0;
	x = "";
	f2.open("sprzet.txt");
	while (getline(f2, x)) {
		after_commas2.clear();
		tokenize(x, after_commas2);
		cout << after_commas2[0] << after_commas2[1] << endl;
		(sp + count)->set_id(stoi(after_commas2[0]));
		(sp + count)->set_type((char*)after_commas2[1].c_str());
		count++;
	}
	f2.close();
	count = 0;
	x = "";
	f3.open("wypozyczenie.txt");
	while (getline(f3, x)) {
		after_commas3.clear();
		tokenize(x, after_commas3);
		cout << after_commas3[0] << after_commas3[1] << endl;
		(wy + count)->set_id_osoba(stoi(after_commas3[0]));
		(wy + count)->set_id_sprzet(stoi(after_commas3[0]));
		count++;
	}
	f3.close();
	cout << endl;
	system("pause");
}

bool check_if_id_is_type(int id, const char* type, Sprzet* sp) {
	for (int i = 0; i < MAX_ARR_SIZE; i++) {
		if ((sp + i)->get_id() == id && (sp + i)->get_type() == type)
			return true;
	}
	return false;
}

bool check_if_id_is_age_higher_than(int id, int age, Osoba* os) {
	for (int i = 0; i < MAX_ARR_SIZE; i++) {
		if ((os + i)->get_id() == id && (os + i)->get_wiek() > age)
			return true;
	}
	return false;
}

void show_data(const char* a, Osoba* os, Sprzet* sp, Wypozyczenie* wy) {
	int count = 0;
	for (int i = 0; i < MAX_ARR_SIZE; i++) {
		if (check_if_id_is_type((wy + i)->get_id_sprzet(), a, sp))
			count++;
	}
	cout << "Wypozyczono " << count << endl;
	system("pause");
}

void show_data_a(int w, const char* a, Osoba* os, Sprzet* sp, Wypozyczenie* wy) {
	//osoby powyzej 25, wypozyczenie hulajnogi
	vector<int> potencjalni;
	for (int i = 0; i < MAX_ARR_SIZE; i++) {
		if (check_if_id_is_age_higher_than((wy + i)->get_id_osoba(), w, os) && check_if_id_is_type((wy + i)->get_id_sprzet(), a, sp)) {
			potencjalni.push_back(i);
		}
	}
	cout << "Lista osob, pow. 25 lat z wypozyczona hulajnoga:" << endl;
	for (int i = 0; i < potencjalni.size(); i++) {
		cout << "\t" << (os + potencjalni[i])->get_id() << ". " << (os + potencjalni[i])->get_nazwisko() << endl;
	}
}

int main() {
	Sprzet sprzeciory[MAX_ARR_SIZE];
	Osoba osobory[MAX_ARR_SIZE];
	Wypozyczenie wypozyczeniory[MAX_ARR_SIZE];
	sprzeciory[0] = Sprzet("hulajnoga");
	sprzeciory[1] = Sprzet("rower");
	sprzeciory[2] = Sprzet("hulajnoga");
	osobory[0] = Osoba("Janowicz", 27);
	osobory[1] = Osoba("Kregielski", 45);
	wypozyczeniory[0] = Wypozyczenie(osobory[0].get_id(), sprzeciory[0].get_id());
	wypozyczeniory[1] = Wypozyczenie(osobory[1].get_id(), sprzeciory[2].get_id());
	wypozyczeniory[2] = Wypozyczenie(osobory[1].get_id(), sprzeciory[1].get_id());
	bool menu = true;
	int option = -1;
	while (menu) {
		system("cls");
		cout << "1. Zapis danych" << endl;
		cout << "2. Odczyt danych" << endl;
		cout << "3. Osoby w wieku > 25 i wypozyczyly hulajnoge" << endl;
		cout << "4. Liczba wypozyczonych rowerow" << endl;
		cout << "5. Wyjscie" << endl;
		cin >> option;
		switch (option)
		{
		default:
			cout << "Nieznana komenda" << endl;
			break;
		case 1:
			save_data(osobory, sprzeciory, wypozyczeniory);
			break;
		case 2:
			load_data(osobory, sprzeciory, wypozyczeniory);
			break;
		case 3:
			show_data("hulajnoga", osobory, sprzeciory, wypozyczeniory);
			show_data_a(25, "hulajnoga", osobory, sprzeciory, wypozyczeniory);
			system("pause");
			break;
		case 4:
			show_data("rower", osobory, sprzeciory, wypozyczeniory);
			break;
		case 5:
			menu = false;
			break;
		}
	}

	system("pause");
	return 0;
}