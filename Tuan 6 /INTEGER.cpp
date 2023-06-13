#include <iostream>
using namespace std;
class INTEGER
{
private:
    int x;
public:
    INTEGER() {
        x = 0;
    }
    INTEGER(int value) {
        x = value;
    }
    ~INTEGER() { }
    friend istream& operator >> (istream& is, INTEGER& a) {
        is >> a.x;
        return is;
    }
    friend ostream& operator << (ostream& os, INTEGER& a) {
        os << a.x;
        return os;
    }
    INTEGER operator + (const INTEGER& a) {
        INTEGER b;
        b.x = this->x + a.x;
        return b;
    }
    INTEGER operator - (const INTEGER& a) {
        INTEGER b;
        b.x = this->x - a.x;
        return b;
    }
    INTEGER operator * (const INTEGER& a) {
        INTEGER b;
        b.x = this->x * a.x;
        return b;
    }
    INTEGER operator / (const INTEGER& a) {
        INTEGER b;
        b.x = this->x / a.x;
        return b;
    }
    INTEGER operator ++ () {
        ++x;
        return *this;
    }
    INTEGER operator -- () {
        --x;
        return *this;
    }
};
int main() 
{
    INTEGER a,b;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    INTEGER cong, tru, nhan, chia;
    cong = a + b;
    tru = a - b;
    nhan = a * b;
    chia = a / b;
    cout << "a + b = " << cong << endl;
    cout << "a - b = " << tru << endl;
    cout << "a * b = " << nhan << endl;
    cout << "a / b = " << chia << endl;
    INTEGER tang, giam;
    tang = ++a;
    giam = --b;
    cout << "a sau khi tang: " << a << endl;
    cout << "b sau khi giam: " << b << endl;
    return 0;
}
