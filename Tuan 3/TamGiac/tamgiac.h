#pragma once
#include"Diem.h"
#include <iostream>
#include <cmath>
using namespace std;
class Triangle
{
private:
    Coordinate A, B, C;
    bool isValid() {
        double AB = sqrt(pow(B.GetAbscissa() - A.GetAbscissa(), 2) + pow(B.GetOrdinate() - A.GetOrdinate(), 2));
        double AC = sqrt(pow(C.GetAbscissa() - A.GetAbscissa(), 2) + pow(C.GetOrdinate() - A.GetOrdinate(), 2));
        double BC = sqrt(pow(C.GetAbscissa() - B.GetAbscissa(), 2) + pow(C.GetOrdinate() - B.GetOrdinate(), 2));
        return (AB + AC > BC && AB + BC > AC && AC + BC > AB);
    }
public:
    Triangle();
    Triangle(const Triangle& other);
    ~Triangle();
    void InputTrian();
    void OutputTrian();
    void SetTrian(Coordinate, Coordinate, Coordinate);
    void TranslationTrian();
    void RotateTrian();
    void ZoomInOut();
};
