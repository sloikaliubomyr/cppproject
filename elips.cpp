#include "elips.h"
#include <iostream>
#include <cmath>
#include "math.h"

using namespace std;

void Ellipse::WedElips() {
	cout << endl << "Введіть координати I фокуса F_1(x0,y0) - ";
	cin >> Fx1 >> Fy1;
	cout << endl << "Введіть координати II фокуса F_2(x0,y0) - ";
	cin >> Fx2 >> Fy2;
	cout << endl << "Введіть обидва радіуси R_1 R_2 - ";
	cin >> a >> b;
}

void Ellipse::PrintElips()
{
	cout << "x^2/(" << a * a << ")+y^2/(" << b * b << ")=1" << endl;
}

float Ellipse::Square()
{
	float pi = 3.14159265358979323846;
	float S = pi * a * b;
	return S;
}

void Ellipse::TopPointElips()
{
	float x = (Fx1 + Fx2) / 2;
	float y = (Fy1 + Fy2) / 2;
	cout << endl << "Центер еліпса знаходиться в точці (" << x << "," << y << ")" << endl;
}

bool Ellipse::PointElips(float x, float y)
{
	float z = a * sqrt(1 - (y * y) / (b * b));
	if (x <= z && x >= z) {
		return true;
	}
	else {
		return false;
	}
}

void Ellipse::PointLine(float a1, float b1)
{
	float a_l = (b * b + a * a * a1);
	float b_l = 2 * a1 * a * a * b1;
	float c_l = a * a * (b1 * b1 - b * b);
	float des = b_l * b_l - 4 * a_l * c_l;
	if (des >= 0) {
		cout << "Існує перетин ЕЛІПСА " << endl;

		float x = -b_l - sqrt(des) / (2 * a1);
		float y = a_l * x * x + b_l * x + c_l;

		cout << "Точка перетину (" << x << "," << y << ")" << endl;
		if (des > 0) {
			x = -b_l + sqrt(des) / (2 * a1);
			y = a_l * x * x + b_l * x + c_l;
			cout << "Точка перетину (" << x << "," << y << ")" << endl;
		}
	}
	else {
		cout << "Пряма не перетинає елвпс :(" << endl;
	}
}
