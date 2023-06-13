#include <iostream>
using namespace std;

class PS
{
private:
    int ts;
    int ms;
    int gcd(int a, int b)
    {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    void RutGon()
    {
        int m = gcd(ts, ms);
        ts /= m;
        ms /= m;
    }
public:
    PS(int ts = 0, int ms = 1)
    {
        this->ts = ts;
        this->ms = ms;
        RutGon();
    }
    PS(int a) {
        this->ts = a;
        this->ms = 1;
        RutGon();
    }
    friend istream& operator >> (istream& is, PS& p)
    {
        cout << "Nhap tu so: "; is >> p.ts;
        cout << "Nhap mau so: "; is >> p.ms;
        return is;
    }
    friend ostream& operator << (ostream& os, PS p)
    {
        if (p.ts == 0) os << 0;
        else if (p.ts == p.ms) os << 1;
        else if (p.ts < 0 || p.ms < 0) cout << "-" << p.ts << "/" << abs(p.ms);
        else os << p.ts << "/" << p.ms;
        return os;
    }
    PS operator+ (PS& p)
    {
        PS temp;
        temp.ts = (this->ts * p.ms) + (this->ms * p.ts);
        temp.ms = this->ms * p.ms;
        temp.RutGon();
        return temp;
    }
    PS operator- (PS& p)
    {
        PS temp;
        temp.ts = (this->ts * p.ms) - (this->ms * p.ts);
        temp.ms = this->ms * p.ms;
        temp.RutGon();
        return temp;
    }
    PS operator* (PS& p)
    {
        PS temp;
        temp.ts = this->ts * p.ts;
        temp.ms = this->ms * p.ms;
        temp.RutGon();
        return temp;
    }
    PS operator/ (PS& p)
    {
        if (ts == 0) cout << "Invalid calculate" << endl;
        else {
            PS temp; 
            temp.ts = this->ts * p.ms;
            temp.ms = this->ms * p.ts;
            temp.RutGon();
            return temp;
        }
    }
    PS& operator ++ ()  {
        ts += ms;
        return *this;
    }
    PS& operator ++ (int) {
        PS ret = *this;
        ts += ms;
        return ret;
    }
    bool operator == (PS& p) {
        if (this->ts == p.ts && this->ms == p.ms)
            return true;
        return false;
    }
    bool operator != (PS& p) {
        if (this->ts != p.ts && this->ms != p.ms)
            return true;
        return false;
    }
    bool operator > (PS& p) {
        if ((this->ts * p.ms - p.ts * this->ms)>0)
            return true;
        return false;
    }
    bool operator >= (PS& p) {
        if ((this->ts * p.ms - p.ts * this->ms) >= 0)
            return true;
        return false;
    }
    bool operator < (PS& p) {
        if ((this->ts * p.ms - p.ts * this->ms) < 0)
            return true;
        return false;
    }
    bool operator <= (PS& p) {
        if ((this->ts * p.ms - p.ts * this->ms) <= 0)
            return true;
        return false;
    }
};
int main()
{
    PS p1, p2;
    cin >> p1 >> p2;
    cout << endl;
    cout << p1 << " + " << p2 << " = " << p1 + p2 << endl;
    cout << p1 << " - " << p2 << " = " << p1 - p2 << endl;
    cout << p1 << " * " << p2 << " = " << p1 * p2 << endl;
    cout << p1 << " / " << p2 << " = " << p1 / p2 << endl;
    cout << "_____________________________________________" << endl;
    cout << "So sanh 2 phan so" << endl;
    cout << "p1 == p2 : "; (p1 == p2) ? (cout << "TRUE" << endl) : (cout << "FALSE" << endl);
    cout << "p1 != p2 : "; (p1 != p2) ? (cout << "TRUE" << endl) : (cout << "FALSE" << endl);
    cout << "p1 > p2 : "; (p1 > p2) ? (cout << "TRUE" << endl) : (cout << "FALSE" << endl);
    cout << "p1 >= p2 : "; (p1 >= p2) ? (cout << "TRUE" << endl) : (cout << "FALSE" << endl);
    cout << "p1 < p2 : "; (p1 < p2) ? (cout << "TRUE" << endl) : (cout << "FALSE" << endl);
    cout << "p1 <= p2 : "; (p1 <= p2) ? (cout << "TRUE" << endl) : (cout << "FALSE" << endl);
    p1++; ++p2;
    cout << p1 << "  " << p2;
    return 0;
}

