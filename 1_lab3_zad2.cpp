#pragma warning (disable : 4996)
#include <iostream>
#include <cmath>

int main(){
	char oper;
	short dobrze = 1;
	double arg1, arg2, wynik;
	printf("Kalkulator, napisz wyrazenie:");
	scanf("%lf%c%lf", &arg1, &oper, &arg2);
	switch(oper){
		case '+':
			printf("%lf + %lf = %lf", arg1, arg2, arg1 + arg2);
			break;
		case '-':
			printf("%lf - %lf = %lf", arg1, arg2, arg1 - arg2);
			break;
		case '*':
			printf("%lf * %lf = %lf", arg1, arg2, arg1 * arg2);
			break;
		case '/':
			printf("%lf / %lf = %lf", arg1, arg2, arg1 / arg2);
			break;
		case '^':
			printf("%lf ^ %lf = %lf", arg1, arg2, pow(arg1, arg2));
			break;
	}
	printf("\n");
	system("PAUSE");
}