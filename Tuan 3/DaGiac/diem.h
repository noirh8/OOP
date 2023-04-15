#pragma once
class Coordinate
{
private:
    double abscissa, ordinate;
public:
    Coordinate();
    ~Coordinate();
    void Input();
    void Output();
    void SetCoordinate(double=0, double=0);
    double GetAbscissa();
    double GetOrdinate();
    void Translations(double, double);
    void RotateP(double);
};
