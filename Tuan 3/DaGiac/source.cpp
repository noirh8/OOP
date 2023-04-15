#include <iostream>
#include "diem.h"
#include "diem.cpp"
#include "dagiac.h"
#include "dagiac.cpp"
using namespace std;
int main()
{
    Polygon A;
    A.Input();
    A.Output();
    cout << endl;
    A.TranslatePolygon();
    cout << endl;
    A.RotatePolygon();
    cout << endl;
    A.ZoomInOut();
    return 0;
}


