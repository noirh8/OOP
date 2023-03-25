#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double real = 0.0, double imag = 0.0) {
        this->real = real;
        this->imag = imag;
    }
    double getReal() const { return real; }
    double getImag() const { return imag; }
};

Complex operator+(const Complex& a, const Complex& b) {
    return Complex(a.getReal() + b.getReal(), a.getImag() + b.getImag());
}

Complex operator-(const Complex& a, const Complex& b) {
    return Complex(a.getReal() - b.getReal(), a.getImag() - b.getImag());
}

Complex operator*(const Complex& a, const Complex& b) {
    return Complex(a.getReal() * b.getReal() - a.getImag() * b.getImag(),
                   a.getReal() * b.getImag() + a.getImag() * b.getReal());
}

Complex operator/(const Complex &a, const Complex &b) {
    return Complex((a.getReal()*b.getReal() + a.getImag()*b.getImag()) / (b.getReal()*b.getReal() + b.getImag()*b.getImag()),
                   (b.getReal()*a.getImag() - a.getReal()*b.getImag()) / (b.getReal()*b.getReal() + b.getImag()*b.getImag()));
}

ostream& operator<<(ostream& os, const Complex& c) {
    if (c.getImag() == 0) os << c.getReal();
    else if (c.getImag() < 0) os << c.getReal() << c.getImag() << "i";
    else os << c.getReal() << " + " << c.getImag() << "i";
    return os;
}

istream& operator>>(istream& is, Complex& c) {
    double real, imag;
    is >> real >> imag;
    c = Complex(real, imag);
    return is;
}

int main() {
    Complex a, b;
    cout << "Enter the first complex number (real imag): ";
    cin >> a;
    cout << "Enter the second complex number (real imag): ";
    cin >> b;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    return 0;
}
