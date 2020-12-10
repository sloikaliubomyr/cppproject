#include "parabola.h"
#include <cmath>
#include <string>
#include <clocale>
#include <iostream>
using namespace std;

Parabola::Parabola()
{
}

Parabola::Parabola(float a, float b, float c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

float Parabola::getA()
{
	return a;
}

float Parabola::getB()
{
	return b;
}

float Parabola::getC()
{
	return c;
}

void Parabola::WidParab()
{
	cout << endl << "Введіть коефіцієнти парабули" << endl << "y=a*(x^2)+b*x+c" << endl << "a - ";
	cin >> a;
	cout << "b - ";
	cin >> b;
	cout << "c - ";
	cin >> c;
	
}

void Parabola::PrintParab()
{
	cout << "y=" << a << "*(x^2)+" << b << "*x+" << c << endl;
}

void Parabola::PrintTopParab()
{
		if (a != 0) {
			float x = -b / (2 * a);
			float y = a * x * x + b * x + c;
			cout << endl << "Центер параболи у т. А(" << x << "," << y << ")" << endl;
		}
		else {
			cout << endl << "Оскільки а=0 - не можливо визначити центер параболи :(" << endl;
		}
}

bool Parabola::IsPointIn(float x, float y)
{ // перевірка точки
		float z = a * x * x + b * x + c;
		if (a >= 0 && y <= z || a<=0 && y>=z) {
			return true;
		}
		return false;
}

void Parabola::PrintPointLine(float a_p, float b_p) 
{ //  перетин парямої
	float a1 = a;
	float b1 = b - a_p;
	float c1 = c - b_p;
	float des =b1 * b1 - 4 * a1 * c1;
	if (des >= 0) {
		cout << "Існує перетин прямої та параболи " << endl;

		float x = -b1 - sqrt(des) / (2 * a1);
		float y = a_p * x + b_p;

		cout << "Точка перетину (" << x << "," << y << ")" << endl;
		if (des > 0) {
			x = -b1 + sqrt(des) / (2 * a1);
			y = a_p * x + b_p;
			cout << "Точка перетину (" << x << "," << y << ")" << endl;
		}
	}
	else {
		cout << "Пряма не перетинає параболу :(" << endl;
	}		
}


void Parabola::PrintPointParabola(Parabola* parabola) 
{//перетин параболи
		float a1 = a - parabola->a;
		float b1 = b - parabola->b;
		float c1 = c - parabola->c;
		float des = b1 * b1 - 4 * a1 * c1;
		if (des >= 0) {
			cout << "Існує перетин параболи " << endl;

			float x = -b1 - sqrt(des) / (2 * a1);
			float y =a*x*x+b*x+c;

			cout << "Точка перетину (" << x << "," << y << ")" << endl;
			if (des > 0) {
				x = -b1 + sqrt(des) / (2 * a1);
				y = a * x * x + b * x + c;
				cout << "Точка перетину (" << x << "," << y << ")" << endl;
			}
		}
		else {
			cout << "Параболи не перетинаються:(" << endl;
		}
}


float Parabola::SquareParabola(Parabola* p)
{
	float S = 0;

	float a1 = a - p->a;
	float b1 = b - p->b;
	float c1 = c - p->c;
	float des = b1 * b1 - 4 * a1 * c1;
	
	if (des > 0) 
	{
		float x1 = -b1 - sqrt(des) / (2 * a1);
		float x2 = -b1 + sqrt(des) / (2 * a1);

		if (x2 < x1) {
			float t = x1;
			x1 = x2;
			x2 = t;
		}

		float k = (x2 - x1) / 1000;
		float x = x1 + k / 2;
		while (x < x2)
		{
			float y1 = a * x * x + b * x + c;
			float y2 = p->a * x * x + p->b * x + p->c;
			S += k * abs(y1 - y2);
			x += k;
		}
	}

	return S;
}

