#include <iostream>
#include "diem.h"
#include "dagiac.h"
Polygon::Polygon() {

}
Polygon::~Polygon() {

}
void Polygon::Input()
{
    int check;
    do {
        check = 0;
        cout << "Nums of Polygon apicies: ";
        cin >> NumApices;
        if(NumApices<3) {
            check = 1;
            cout << "Invalid polygon";
        }
    } while(check);
    for(int i=0; i<NumApices; i++) {
        cout << "Coordinate of " << i+1 << " apex: " << endl;
        ApexList[i].Input();
        cout << endl;
    }
}
void Polygon::Output()
{
    for(int i=0; i<NumApices; i++) {
        cout << "Cordinate of " << i+1 << " apex: ";
        ApexList[i].Output();
        cout << endl;
    }
}
void Polygon::TranslatePolygon()
{
    double x,y;
    cout << "Input Vecto V: " << endl;
    cout << "Abscissa: "; cin >> x;
    cout << "Ordinate: "; cin >> y;
    for(int i=0; i<NumApices;i++){
        cout << "Coordinate of " << i+1 << " apex after translation follow (" << x << "," << y << "): ";
        ApexList[i].Translations(x,y);
        cout << endl;
    }
}
void Polygon::RotatePolygon()
{
    double RotateDegree;
    cout << "Degree want to rotate: "; cin >> RotateDegree;
    for(int i=0; i<NumApices; i++) {
        cout << "Coordinate of " << i+1 << " apex after rotation an angle of " << RotateDegree << ": ";
        ApexList[i].RotateP(RotateDegree);
        cout << endl;
    }
}
void Polygon::ZoomInOut()
{
    double ZoominRatio;
    cout << "Input Zoom in Ratio: "; cin >> ZoominRatio;
    for(int i=0; i<NumApices; i++) {
        cout << "Coordinate of " << i+1 << " apex after Zoom In " << ZoominRatio << "x : ";
        ApexList[i].SetCoordinate(ApexList[i].GetAbscissa() * ZoominRatio, ApexList[i].GetOrdinate() * ZoominRatio);
        ApexList[i].Output();
        cout << endl;
        }
    double ZoomoutRatio;
    cout << endl;
    cout << "Input Zoom out Ratio: "; cin >> ZoomoutRatio;
    for(int i=0; i<NumApices; i++) {
        cout << "Coordinate of " << i+1 << " apex after Zoom Out " << ZoomoutRatio << "x : ";
        ApexList[i].SetCoordinate(ApexList[i].GetAbscissa() * (1.0/(ZoomoutRatio*ZoominRatio)), ApexList[i].GetOrdinate() * (1.0/(ZoomoutRatio*ZoominRatio)));
        ApexList[i].Output();
        cout << endl;
        }
}

