#include "hyperbole.h"
#include <iostream>
#include <cmath>
using namespace std;

Hiperbola::Hiperbola()
{
}

Hiperbola::Hiperbola(float a, float b, float c, float r1, float r2)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->r1 = r1;
	this->r2 = r2;
}

void Hiperbola::WedHiperola()
{
	cout << endl << "Введіть елементи гіперболи \n (x^2/a^2)-(y^2/b^2)=1\n a - ";
	cin >> a;
	cout << " b - ";
	cin >> b;
	cout << " c - ";
	cin >> c;
	cout << " r1 -";
	cin >> r1;
	cout << " r2 - ";
	cin >> r2;
}

void Hiperbola::Print()
{
	cout << "x^2/(" << a * a << ")-y^2/(" << b * b<<")=1 \n Відстань до центру -" << c<<endl;
}
void  Hiperbola::PrintCentr() {
	float x = 1;
	float y = -b * sqrt(1 - (x * x) / (a * a));
	cout << "Координати центра - (" << ((x * x * x) / (a * a) * (1 + ((b * b) / (a * a)))) << "," << -((y * y * y) / (b * b) * (1 + ((a * a) / (b * b)))) << ")" << endl;
}

bool Hiperbola::PoindHiperbola(float x, float y)
{
	float z= -b * sqrt(1 - (x * x) / (a * a));
	if (y > z) {
		return true;
	}
	else {
		return false;
	}
}

void Hiperbola::PrintPeretHiperbola(Hiperbola h)
{
	float t = 2 - ((b * b) / a * a) - (h.b * h.b) / (h.a * h.a);
	if (t > 0) {

		float x1 = sqrt(t);
		float x2 = -sqrt(t);
		float y1 = (b * sqrt(-1 + (x1 * x1) / (a * a)));
		float y2 = (b * sqrt(-1 + (x2 * x2) / (a * a)));
		cout << "Існують точки перетину двох гіпербол" << endl;
		cout << "Точка перетину - ("<< x1<<"," <<y1<< ")" << endl;
		cout << "Точка перетину - (" << x1 << "," << -y1 << ")" << endl;
		cout << "Точка перетину - (" << x2 << "," << y2 << ")" << endl;
		cout << "Точка перетину - (" << x2 << "," << -y2 << ")" << endl;
	}
	else {
		cout << "Перетину не має" << endl;
	}

}


