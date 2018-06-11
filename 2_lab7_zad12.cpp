#include <iostream>
#include <math.h>
const double PI = 3.14;
using namespace std;

class Bryla {
public:
	virtual double objetosc() {
		cout << "invalid objetosc()" << endl;
		return 0.0;
	};
	virtual double pole_powierzchni_calkowitej() = 0;
	virtual void pobierz_dane() = 0;
	virtual ~Bryla() {
		cout << "destruktor Bryla" << endl;
	};
};

class Stozek : public Bryla {
private:
	double r;
	double h;
	double l;
public:
	double tworzaca() {
		l = sqrt(pow(h, 2) + pow(r, 2));
		return l;
	};
	double objetosc() {
		return (PI*pow(r, 2)*h) / 3;
	};
	void pobierz_dane() {
		cout << "Wprowadz r: " << endl;
		cin >> r;
		cout << "Wprowadz h: " << endl;
		cin >> h;
		tworzaca();
	};
	double pole_powierzchni_calkowitej() {
		return (PI*pow(r, 2) + (PI*r*l));
	};
	~Stozek() {
		cout << "destruktor Stozek" << endl;
	}
};

class Walec : public Bryla {
private:
	double r;
	double h;
public:
	void pobierz_dane() {
		cout << "Wprowadz r: " << endl;
		cin >> r;
		cout << "Wprowadz h: " << endl;
		cin >> h;
	};
	double objetosc() {
		return PI * pow(r, 2)*h;
	};
	double pole_powierzchni_calkowitej() {
		return (2 * PI*r + 2 * PI*pow(r, 2));
	};
	~Walec() {
		cout << "destruktor Walec" << endl;
	}
};

class Kula : public Bryla {
private:
	double r;
public:
	void pobierz_dane() {
		cout << "Wprowadz r: " << endl;
		cin >> r;
	};
	double objetosc() {
		return (4 / 3)*PI*pow(r, 3);
	};
	double pole_powierzchni_calkowitej() {
		return 4 * PI*pow(r, 2);
	};
	~Kula() {
		cout << "destruktor Kula" << endl;
	}
};

class Czworoscian_Foremny : public Bryla {
private:
	double a;
	double H;
	double h;
public:
	void pobierz_dane() {
		cout << "Wprowadz a: " << endl;
		cin >> a;
		h = wysokosc_trojkata();
		H = wysokosc_czworoscianu();
	};
	double wysokosc_trojkata() {
		return (a*sqrt(3)) / 2;
	}
	double wysokosc_czworoscianu() {
		return (a*sqrt(6)) / 3;
	}
	double objetosc() {
		return (pow(a, 3)*sqrt(2))/12;
	};
	double pole_powierzchni_calkowitej() {
		return pow(a, 2)*sqrt(3);
	};
	~Czworoscian_Foremny() {
		cout << "destruktor Czworoscian_Foremny" << endl;
	};
};

class Prostopadloscian : public Bryla {
private:
	double a;
	double b;
	double H;
public:
	void pobierz_dane() {
		cout << "Wprowadz a: " << endl;
		cin >> a;
		cout << "Wprowadz b: " << endl;
		cin >> b;
		cout << "Wprowadz H: " << endl;
		cin >> H;
	};
	double objetosc() {
		return a*b*H;
	};
	double pole_powierzchni_calkowitej() {
		return (2*a*b)+(2*b*H)+(2*a*H);
	};
	~Prostopadloscian() {
		cout << "destruktor Prostopadloscian" << endl;
	};
};

void obsluga_bryly(Bryla &b) {
	b.pobierz_dane();
	cout << "Pole powierzchni calkowitej: " << b.pole_powierzchni_calkowitej() << endl;
	cout << "Objetosc: " << b.objetosc() << endl;
}

template <typename T> void wywolania(T a) {
	Bryla *wsk = new T;
	wsk->pobierz_dane();
	cout << "Pole powierzchni calkowitej: " << wsk->pole_powierzchni_calkowitej() << endl;
	cout << "Objetosc: " << wsk->objetosc() << endl;
	delete wsk;
	obsluga_bryly(a);
	cout << "----------------------" << endl;
}

int main() {
	wywolania<Stozek>(Stozek());
	wywolania<Walec>(Walec());
	wywolania<Kula>(Kula());
	wywolania<Czworoscian_Foremny>(Czworoscian_Foremny());
	wywolania<Prostopadloscian>(Prostopadloscian());
	system("pause");
	return 1;
	/*
	zzzzzz, na pewno nie
	Bryla *wsk = new Stozek;
	wsk->pobierz_dane();
	cout << "Pole powierzchni calkowitej: " << wsk->pole_powierzchni_calkowitej() << endl;
	cout << "Objetosc: " << wsk->objetosc() << endl;
	delete wsk;
	Stozek a;
	obsluga_bryly(a);
	*/
}