#include <iostream>
#include <cmath>
#include "diem.h"
using namespace std;

Coordinate::Coordinate()
{

}
Coordinate::~Coordinate()
{

}
void Coordinate::SetCoordinate(double x, double y)
{
    abscissa = x;
    ordinate = y;
}
double Coordinate::GetAbscissa()
{
    return abscissa;
}
double Coordinate::GetOrdinate()
{
    return ordinate;
}
void Coordinate::Input()
{
    cout << "Input Abscissa: "; cin >> abscissa;
    cout << "Input Ordinate: "; cin >> ordinate;
}
void Coordinate::Output()
{
    cout << "(" << abscissa << "," << ordinate << ")";
}
void Coordinate::Translations(double x, double y)
{
    Coordinate TranslationsPoint;
    TranslationsPoint.abscissa = abscissa + x;
    TranslationsPoint.ordinate = ordinate + y;
    cout << "(" << TranslationsPoint.abscissa << "," << TranslationsPoint.ordinate << ")";
}
void Coordinate::RotateP(double RotateDegree)
{
    Coordinate RotatePoint;
    double Radian = RotateDegree * M_PI / 180;
    RotatePoint.abscissa = abscissa * cos(Radian) - ordinate * sin(Radian);
    RotatePoint.ordinate = abscissa * sin(Radian) + ordinate * cos(Radian);
    cout << "(" << RotatePoint.abscissa << "," << RotatePoint.ordinate << ")";
}
