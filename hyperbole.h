#include "parabola.h"

class Hiperbola {
private:
	float a, b, c, r1, r2;
public:
	Hiperbola();
	Hiperbola(float a, float b, float c, float r1, float r2);
	void WedHiperola();
	void Print();
	void PrintCentr();
	bool PoindHiperbola(float x, float y);
	void PrintPeretHiperbola(Hiperbola h);
	
};