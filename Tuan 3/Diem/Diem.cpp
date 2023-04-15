#include <iostream>
using namespace std;
class  Coordinate
{
private:
    double abscissa,ordinate;
public:
    Coordinate() {};
    Coordinate(double h, double t)
    {
        abscissa=h;
        ordinate=t;
    }
    Coordinate(const Coordinate& other) {
        this->abscissa = other.abscissa;
        this->ordinate = other.ordinate;
    }
    void InputCoor();
    void OutputCoor();
    double GetAbscissa();
    double GetOrdinate();
    void Translations();
};
void Coordinate::InputCoor()
{
    cout << "Input Abscissa: ";
    cin >> abscissa;
    cout << "Input Ordinate: ";
    cin >> ordinate;
}
void Coordinate::OutputCoor()
{
    cout << "Coordinate: (" << abscissa << "," << ordinate << ")" << endl;
}
double Coordinate::GetAbscissa()
{
    return abscissa;
}
double Coordinate::GetOrdinate()
{
    return ordinate;
}
void Coordinate::Translations()
{
    Coordinate vectorV;
    Coordinate TranslatedP;
    cout << "Input the Abscissa of Vector V: "; cin >> vectorV.abscissa;
    cout << "Input the Ordinate of Vector V: "; cin >> vectorV.ordinate;
    TranslatedP.abscissa = abscissa + vectorV.abscissa;
    TranslatedP.ordinate = ordinate + vectorV.ordinate;
    cout << "Coordinate after Translation: (" << TranslatedP.abscissa << "," << TranslatedP.ordinate << ")";
}
int main()
{
    Coordinate A;
    A.InputCoor();
    A.OutputCoor();
    A.Translations();
    return 0;
}
