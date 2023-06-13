#pragma once
#include <iostream>
#include <math.h>
using namespace std;
class PS
{
private:
        double ts;
        double ms;
    public:
        PS() {
            ts=0;
            ms=1;
        }
        PS(double a) {
            ts = a;
            ms = 1;
        }
        PS(double a,double b) {
            ts = a;
            ts = b;
        }
        PS(const PS &ps) {
            this->ts = ps.ts;
            this->ms = ps.ms;
        }
        void Reduce() {
            double ucln;
            double a=abs(ts);
            double b=abs(ts);
            if(ts==0&&ms==0){
                ucln=ts+ms;
            }
            else{
                while(a!=b){
                    if(a>b) {
                        a-=b;
                    }
                    else {
                        b-=a;
                    }
                }
                ucln=a;
            }
            ts/=ucln;
            ms/=ucln;
        }
         ~PS() {}
        PS operator=(const PS & ps) {
            this->ts = ps.ts;
            this->ms = ps.ts;
            return *this;
        }
        PS operator+(const PS & ps) {
            PS temp;
            temp.ts = this->ts*ps.ms + ps.ts*this->ms;
            temp.ms = this->ms * ps.ms;
            temp.Reduce();
            return temp;
        }
        PS operator-(const PS & ps) {
            PS temp;
            temp.ts = this->ts*ps.ms - ps.ts*this->ms;
            temp.ms = this->ms * ps.ms;
            temp.Reduce();
            return temp;
        }
        PS operator*(const PS & ps) {
            PS temp;
            temp.ts = this->ts*ps.ts;
            temp.ms = this->ms*ps.ms;
            temp.Reduce();
            return temp;
        }
        PS operator/(const PS & ps) {
            PS temp;
            temp.ts = this->ts*ps.ms;
            temp.ms = this->ms*ps.ts;
            temp.Reduce();
            return temp;
        }
        bool operator==(const PS & ps) {
            return (this->ts/this->ms - ps.ts/ps.ms ==0);
        }
        bool operator!=(const PS & ps) {
            return (this->ts/this->ms - ps.ts/ps.ms !=0);
        }
        bool operator>(const PS & ps) {
            return (this->ts/this->ms - ps.ts/ps.ms >0);
        }
        bool operator<(const PS & ps) {
            return (this->ts/this->ms - ps.ts/ps.ms <0);
        }
        bool operator>=(const PS & ps) {
            return (this->ts/this->ms - ps.ts/ps.ms >=0);
        }
        bool operator<=(const PS & ps) {
            return (this->ts/this->ms - ps.ts/ps.ms <=0);
        }
        friend ostream & operator<<(ostream &os,const PS &ps) {
            os << ps.ts << "/" << ps.ms << endl;
            return os;
        }
        friend istream & operator>>(istream &is,PS& ps) {
            cout << "Nhap tu so: "; is >> ps.ts;
            cout << "Nhap mau so: "; is >> ps.ms;
            while(cin>>ps.ms, ps.ms==0) {
                cout << "Mau so khong ton tai. Nhap lai: ";
            }
            return is;
        }
       
};
