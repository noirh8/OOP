#include<iostream>
#include"Diem.h"
#include"TamGiac.h"
#include<cmath>

using namespace std;

Triangle::Triangle()
{

}
Triangle::Triangle(const Triangle& other) {
    this->A = other.A;
    this->B = other.B;
    this->C = other.C;
}
Triangle::~Triangle()
{

}

void Triangle::InputTrian()
{
    int checked;
    do
    {
        checked = 0;
        cout << "A: ";
        A.InputCoor();

        cout << "B: " << endl;
        B.InputCoor();

        cout << "C: " << endl;
        C.InputCoor();
    } while (!isValid());
}

void Triangle::OutputTrian()
{
    cout << "A: "; A.OutputCoor(); cout << endl;
    cout << "B: "; B.OutputCoor(); cout << endl;
    cout << "C: "; C.OutputCoor(); cout << endl;
}

void Triangle::SetTrian(Coordinate X, Coordinate Y, Coordinate Z)
{
    A = X;
    B = Y;
    C = Z;
}

void Triangle::TranslationTrian()
{
    double X,Y;
    cout << "Input translated vecto: " << endl;
    cout << "Vecto Abscissa: ";
    cin >> X;
    cout << "Vecto Ordinate: ";
    cin >> Y;
    cout << "A after translated follow vector (" << X << ";" << Y << ") is: ";
    A.Translations(X, Y);
    cout << "B after translated follow vector (" << X << ";" << Y << ") is: ";
    B.Translations(X, Y);
    cout << "C after translated follow vector (" << X << ";" << Y << ") is: ";
    C.Translations(X, Y);
}

void Triangle::RotateTrian()
{
    double RotateDeg;
    cout << "Degree want to rotate: ";
    cin >> RotateDeg;
    cout << "A after rotated a " << RotateDeg << " degree is: ";
    A.RotateP(RotateDeg);
    cout << endl;
    cout << "B after rotated a " << RotateDeg << " degree is: ";
    B.RotateP(RotateDeg);
    cout << endl;
    cout << "C after rotated a " << RotateDeg << " degree is: ";
    C.RotateP(RotateDeg);
    cout << endl;
}

void Triangle::ZoomInOut()
{
    double zoominratio, zoomoutratio;
    cout << "Zoom in ratio: ";
    cin >> zoominratio;
    A.SetCoordinate(A.GetAbscissa() * zoominratio, A.GetOrdinate() * zoominratio);
    B.SetCoordinate(B.GetAbscissa() * zoominratio, B.GetOrdinate() * zoominratio);
    C.SetCoordinate(C.GetAbscissa() * zoominratio, C.GetOrdinate() * zoominratio);
    cout << "A after zoom in: "; A.OutputCoor(); cout << endl;
    cout << "B after zoom in: "; B.OutputCoor(); cout << endl;
    cout << "C after zoom in: "; C.OutputCoor(); cout << endl;
    cout << endl;
    cout << "Zoom out ratio: ";
    cin >> zoomoutratio;
    A.SetCoordinate(A.GetAbscissa() / (zoominratio * zoomoutratio), A.GetOrdinate() / (zoominratio * zoomoutratio));
    B.SetCoordinate(B.GetAbscissa() / (zoominratio * zoomoutratio), B.GetOrdinate() / (zoominratio * zoomoutratio));
    C.SetCoordinate(C.GetAbscissa() / (zoominratio * zoomoutratio), C.GetOrdinate() / (zoominratio * zoomoutratio));
}
