

#include <iostream>
#include "hyperbole.h"
#include "elips.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "ukr");
    Ellipse e;
    e.WedElips();
    e.PrintElips();
    cout<< " Площа еліпса - "<<e.Square();
    e.TopPointElips();
    e.PointElips(0,0);
    e.PointLine(3,6);


    
    Parabola p1(1,2,3);
    Parabola p2;
    p1.WidParab();
    p2.WidParab();
    p1.PrintParab();
    p1.PrintTopParab();
    p1.IsPointIn(4, 6);
    p1.PrintPointLine(-3, 8);
    p1.PrintPointParabola(&p2);
    float r = p1.SquareParabola(&p2);
    cout << "Square : " << r << endl;

    Hiperbola h;
    Hiperbola h1;
    h1.WedHiperola();
    h.WedHiperola();
    h.Print();
    h.PrintCentr();
    h.PoindHiperbola(9, 8);
    h. PrintPeretHiperbola(h1);


    system("pause");
    return 0;
}
