#include<iostream>
#include<cmath>
#include"Diem.h"
#define pi 3.14159265
using namespace std;

Coordinate::Coordinate()
{

}

Coordinate::~Coordinate()
{

}
Coordinate::Coordinate(const Coordinate& other) {
    this->abscissa = other.abscissa;
    this->ordinate = other.ordinate;
}
void Coordinate::SetCoordinate(double x, double y)
{
    abscissa = x;
    ordinate= y;
}

double Coordinate::GetAbscissa()
{
    return abscissa;
}

double Coordinate::GetOrdinate()
{
    return ordinate;
}

void Coordinate::InputCoor()
{
    cout << "Input Abscissa: ";
    cin >> abscissa;
    cout << "Input Ordinate: ";
    cin >> ordinate;
}

void Coordinate::OutputCoor()
{
    cout << "(" << abscissa << ";" << ordinate << ")";
}

void Coordinate::Translations(double X, double Y)
{
    Coordinate TranslatedPoint;
    TranslatedPoint.abscissa = abscissa + X;
    TranslatedPoint.ordinate = ordinate + Y;;
    cout << "(" << TranslatedPoint.abscissa << ";" << TranslatedPoint.ordinate << ")" << endl;
}

void Coordinate::RotateP(double RotateDegree)
{
    double radian = RotateDegree * pi / 180;
    Coordinate Rotate;
    Rotate.abscissa = abscissa * cos(radian) - ordinate * sin(radian);
    Rotate.ordinate = abscissa * sin(radian) + ordinate * cos(radian);
    Rotate.OutputCoor();
}
