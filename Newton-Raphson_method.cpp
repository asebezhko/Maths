//Algorithm produces approximations to the roots (or zeroes) of a real-valued function
#include <iostream>
#include <math.h>
#include <stdio.h>
#include "windows.h"

using namespace std;

double f(double x) {	 //исходная формула в твоём варианте
	double f;
	f = pow(x, 3.0) + pow(x, 2.0) - 3.0;
	return f;
}

double f1(double x) {	 //первая производная от функции в твоём варианте
	double f1;
	f1 = 3.0 * pow(x, 2.0) + 2.0 * x;
	return f1;
}

double f2(double x) {	 //вторая производная от функции в твоём варианте
	double f2;
	f2 = 6.0 * x + 2.0;
	return f2;
}

void main() {
	double a, b, e, x;
	int k;	 //количество итераций
	setlocale(LC_ALL, "Rus");
	a = 1.0; b = 1.4; e = 0.001;	 //тут мы задаём границы отрезка и точность
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "e=" << e << endl;

	if (f(a) * f2(a) > 0) { //проверяем условие сходимости
		cout << "Условие на сходимость выполнено для x = a = "
			<< a << endl;
		x = a;
	}

	else {
		if (f(b) * f2(b) > 0) {
			cout << "Условие на сходимость выполнено для x = b = "
				<< b << endl;
			x = b;
		}
		else {
			cout << "Условие сходимости не выполнено" << endl;
			x = -10E10;
		}
	}

	if (x > -10E10) {
		k = 0;
		while (1) {	 //открываем бесконечный цикл (проверяем условие на точность)
			x = x - f(x) / f1(x);
			k = k + 1;
			if (fabs(f(x)) < e)break; //цикл закрывается, когда условие на точность достигается
		}
		cout << "Корень x = " << x << endl;
		cout << "Количество итераций k = " << k << endl;
	}
}
