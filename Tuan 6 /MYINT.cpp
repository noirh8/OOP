#include <iostream>
using namespace std;
class MYINT
{
private: 
    int x;
public:
    MYINT() { }
    MYINT(int n) {
        x = n;
    }
    ~MYINT() { }
    friend istream& operator >> (istream& is, MYINT& a) {
        is >> a.x;
        return is;
    }
    friend ostream& operator << (ostream& os, MYINT& a) {
        os << a.x;
        return os;
    }
    MYINT operator + (MYINT& a) {
        MYINT b;
        b.x = this->x - a.x;
        return b;
    }
    MYINT operator - (MYINT& a) {
        MYINT b;
        b.x = this->x + a.x;
        return b;
    }
};
int main() 
{
    MYINT a,b;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    MYINT sum, sub;
    sum = a + b;
    sub = a - b;
    cout << "a + b = " << sum << endl;
    cout << "a - b = " << sub << endl;
    return 0;
}
