#include <iostream>
using namespace std;
class ComplexNum
{
private:
    double real;
    double imagine;
public:
    ComplexNum() {}
    ComplexNum(double t, double a)
    {
        real=t;
        imagine=a;
    }
    void inputNum();
    void outputNum();
    void Add(ComplexNum a);
    void Sub(ComplexNum a);
    void Multiply(ComplexNum a);
    void Divide(ComplexNum a);
};

void ComplexNum::inputNum()
{
    cout << "Real unit: ";
    cin >> real;
    cout << "Imaginary unit: ";
    cin >> imagine;
}
void ComplexNum::outputNum()
{
    if (imagine==0) cout << real;
    else if (imagine<0) cout << real << imagine << "i";
    else cout << real << "+" << imagine << "i";
}
void ComplexNum::Add(ComplexNum a)
{
    real = real + a.real;
    imagine = imagine + a.imagine;
}
void ComplexNum::Sub(ComplexNum a)
{
    real = real - a.real;
    imagine = imagine - a.imagine;
}
void ComplexNum::Multiply(ComplexNum a)
{
    ComplexNum z;
    z.real = real*a.real - imagine*a.imagine;
    z.imagine = real*a.imagine + imagine*a.real;
    *this = z;
}
void ComplexNum::Divide(ComplexNum a)
{
    ComplexNum z;
    z.real = (real*a.real + imagine*a.imagine) / (a.real*a.real + a.imagine*a.imagine);
    z.imagine = (imagine*a.real - real*a.imagine) / (a.real*a.real + a.imagine*a.imagine);
    *this = z;
}
int main ()
{
    ComplexNum x1,x2,x;
    x1.inputNum();
    x2.inputNum();
//cộng
    x=x1;
    x.Add(x2);
    x1.outputNum(); cout << " + "; x2.outputNum(); cout << " = "; x.outputNum(); cout << endl;
//trừ
    x=x1;
    x.Sub(x2);
    x1.outputNum(); cout << " - "; x2.outputNum(); cout << " = "; x.outputNum(); cout << endl;
//nhân
    x=x1;
    x.Multiply(x2);
    x1.outputNum(); cout << " * "; x2.outputNum(); cout << " = "; x.outputNum(); cout << endl;
//chia
    x=x1;
    x.Divide(x2);
    x1.outputNum(); cout << " / "; x2.outputNum(); cout << " = "; x.outputNum(); cout << endl;
    system("pause");

    return 0;
}
