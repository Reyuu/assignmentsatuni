#include <iostream>
using namespace std;

class Wektor {
public:
	double x, y, z;
	Wektor(double x_, double y_, double z_) {
		x = x_;
		y = y_;
		z = z_;
	};
	Wektor operator+(const Wektor& w) {
		Wektor a(0,0,0);
		a.x = x + w.x;
		a.y = y + w.y;
		a.z = z + w.z;
		return a;
	};
	Wektor operator-(const Wektor& w) {
		Wektor a(0, 0, 0);
		a.x = x - w.x;
		a.y = y - w.y;
		a.z = z - w.z;
		return a;
	};
	Wektor operator/(int b) {
		Wektor a(0, 0, 0);
		a.x = x/b;
		a.y = y/b;
		a.z = z/b;
		return a;
	};
	Wektor operator/(double b) {
		Wektor a(0, 0, 0);
		a.x = x / b;
		a.y = y / b;
		a.z = z / b;
		return a;
	};
	Wektor operator/(float b) {
		Wektor a(0, 0, 0);
		a.x = x / b;
		a.y = y / b;
		a.z = z / b;
		return a;
	};
	Wektor operator*(const Wektor &w) {
		Wektor a(0, 0, 0);
		a.x = (y*w.z) - (w.y*z);
		a.y = (x*w.z) - (w.x*z);
		a.z = (x*w.y) - (w.x*y);
		return a;
	};
	Wektor operator*(int b) {
		Wektor a(0, 0, 0);
		a.x = x*b;
		a.y = y*b;
		a.z = z*b;
		return a;
	};
	Wektor operator*(double b) {
		Wektor a(0, 0, 0);
		a.x = x*b;
		a.y = y*b;
		a.z = z*b;
		return a;
	};
	Wektor operator*(float b) {
		Wektor a(0, 0, 0);
		a.x = x*b;
		a.y = y*b;
		a.z = z*b;
		return a;
	};
	void print() {
		cout << "Wektor x: " << x << " y: " << y << " z: " << z << endl;
	};
};
int main() {
	Wektor a(5.2, 6.7, 9.1);
	Wektor b(2.7, 3.2, 1);
	cout << "a:\t";
	a.print();
	cout << "b:\t";
	b.print();
	cout << "------------" << endl;
	cout << "\ta - b" << endl;
	(a - b).print();
	cout << "\ta + b" << endl;
	(a + b).print();
	cout << "\ta * b" << endl;
	(a * b).print();
	cout << "\ta * int" << endl;
	(a * 2).print();
	cout << "\ta * double" << endl;
	(b * 4.2).print();
	cout << "\ta * float" << endl;
	(a * float(1.2)).print();
	cout << "\ta / int" << endl;
	(a / 2).print();
	cout << "\ta / double" << endl;
	(b / 4.2).print();
	cout << "\ta / float" << endl;
	(a / float(1.2)).print();
	system("pause");
	return 0;
}