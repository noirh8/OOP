#include <iostream>
using namespace std;
struct fraction
{
	int t;
	int m;
};
typedef fraction PS;
void InpFrac(PS &x)
{
	cout << "Numerator : ";
	cin >> x.t;
	do
	{
		cout << "Denominator : ";
		cin >> x.m;
		if (x.m == 0)
		{
			cout << "Invalid Denominator";
		}
	} while (x.m==0);
}
void OutFrac(PS x)
{
	if (x.t==x.m) cout << 1;
	else if (x.t==0) cout << 0;
	else cout <<  x.t << '/' << x.m << endl;
}
int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}
void Simplify(PS &x)
{
    int gc=GCD(x.t,x.m);
    x.t=x.t/gc;
    x.m=x.m/gc;
    OutFrac(x);
}
int Parity(PS x1, PS x2)
{
    if (x1.t*x2.m - x2.t*x1.m>0) return 1;
        else if (x1.t*x2.m - x2.t*x1.m<0) return -1;
        else if (x1.t*x2.m - x2.t*x1.m == 0) return 0;
}
PS AddPS(PS x1, PS x2)
{
    PS sum;
    sum.t=x1.t*x2.m+x2.t*x1.m;
    sum.m= x1.m*x2.m;
    Simplify(sum);
    OutFrac(sum);
}
PS SubPS(PS x1, PS x2)
{
    PS sub;
    sub.t=x1.t*x2.m-x2.t*x1.m;
    sub.m= x1.m*x2.m;
    Simplify(sub);
    OutFrac(sub);
}
PS MultiplePS(PS x1, PS x2)
{
    PS multi;
    if (x2.t==0) cout << "Invalid  Calculate";
    else {
        multi.t=x1.t*x2.t;
        multi.m= x1.m*x2.m;
        Simplify(multi);
        OutFrac(multi);
    }
}
PS DividePS(PS x1, PS x2)
{
    PS div;
    div.t=x1.t*x2.m;
    div.m= x1.m*x2.t;
    Simplify(div);
    OutFrac(div);
}
int main()
{
    PS x;
    InpFrac(x);
    OutFrac(x);
    Simplify(x);
}
