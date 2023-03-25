#include <iostream>
using namespace std;
class PS
{
private:

public:
    int ts;
    int ms;
    PS() {};
    ~PS() {};
    int gcd(int a, int b)
    {
        if (b==0) return a;
        return gcd(b,a%b);
    }
    PS operator+(PS const &s1)
    {
        PS temp;
        temp.ts = ts*s1.ms + s1.ts*ms;
        temp.ms = ms*s1.ms;
        return temp;
    }
    PS operator-(PS const &s1)
    {
        PS temp;
        temp.ts = ts*s1.ms - s1.ts*ms;
        temp.ms = ms*s1.ms;
        return temp;
    }
    void RutGon()
    {
        int m = gcd(ts,ms);
        ts /= m;
        ms /= m;
    }
};
istream &operator >> (istream &is, PS &p)
    {
        cout << "Nhap tu so: "; is >> p.ts;
        cout << "Nhap mau so: "; is >> p.ms;
        return is;
    }
    ostream &operator << (ostream &os, PS &p)
    {
        os << p.ts << "/" << p.ms << endl;
        return os;
    }
int main()
{
    PS p1,p2, p3;
    cout << "Nhap phan so thu nhat: " << endl;
    cin >> p1;
    p1.RutGon();
    cout << p1;
    cout << "Nhap phan so thu hai: " << endl;
    cin >> p2;
    cout << p2;
    p3=p1+p2;
    p3.RutGon();
    cout << p3; 
}
