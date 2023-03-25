#include <iostream>
#include <windows.h>
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
        int m = gcd(ts,ms);
        ts /= m;
        ms /= m;
    }
public:
    PS(int ts=0, int ms=1)
    {
        this->ts = ts;
        this->ms = ms;
        RutGon();
    }
    friend istream &operator >> (istream &is, PS &p)
    {
        cout << "Nhap tu so: "; is >> p.ts;
        cout << "Nhap mau so: "; is >> p.ms;
        return is;
    }
    friend ostream &operator << (ostream &os, PS p)
    {
        if (p.ts==0) os << 0;
        else if (p.ts==p.ms) os << 1;
        else if (p.ts < 0 || p.ms < 0) cout << "-" << p.ts << "/" << abs(p.ms);
        else os << p.ts << "/" << p.ms;
        return os;
    }
    friend PS operator+ (const PS &p1, const PS &p2)
    {
        int ts = p1.ts*p2.ms + p2.ts*p1.ms;
        int ms = p1.ms*p2.ms;
        return PS(ts,ms);
    }
    friend PS operator- (const PS &p1, const PS &p2)
    {
        int ts = p1.ts*p2.ms - p2.ts*p1.ms;
        int ms = p1.ms*p2.ms;
        return PS(ts,ms);
    }
    friend PS operator* (const PS &p1, const PS &p2)
    {
        int ts = p1.ts*p2.ts;
        int ms = p1.ms*p2.ms;
        return PS(ts,ms);
    }
    friend PS operator/ (const PS &p1, const PS &p2)
    {
        int ts = p1.ts*p2.ms;
        int ms = p1.ms*p2.ts;
        return PS(ts,ms);
    }
};
int main()
{
    PS p1, p2;
    cin >> p1 >> p2;
    cout << endl;
    cout << p1 << " + " << p2 << " = " << p1+p2 << endl;
    cout << p1 << " - " << p2 << " = " << p1-p2 << endl;
    cout << p1 << " * " << p2 << " = " << p1*p2 << endl;
    cout << p1 << " / " << p2 << " = " << p1/p2 << endl;
    system("pause");
    return 0;
}






