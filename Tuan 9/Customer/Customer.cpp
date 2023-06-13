#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <vector>
using namespace std;
class Customer 
{
private:
    string name;
    double TienTra;
    int luongHang;
    double donGia;
public:
    Customer() {}
    ~Customer() {}
    void setName(string name) {
        this->name = name;
    }
    void setTienTra(double TienTra) {
        this->TienTra = TienTra;
    }   
    void setLuongHang(int luongHang) {
        this->luongHang = luongHang;
    }
    void setDonGia(double donGia) {
        this->donGia = donGia;
    }
    string getName() {return name;}
    double getTientra() {return TienTra;}
    int getLuongHang() {return luongHang;}
    double getDonGia() {return donGia;}
    virtual istream &operator>>(istream &is)
    {
        string name;
        is.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(is, name);
        setName(name);
        int num;
        is >> num;
        setLuongHang(num);
        double price;
        is >> price;
        setDonGia(price);
        this->TinhTienTra();
        return is;
    }
    ostream &operator<<(ostream &os)
    {
        os << "Ten: " << getName() << endl;
        os << "So tien phai tra: " << getTientra() << endl;
        return os;
    }
    virtual void TinhTienTra() = 0;
};

class CustomerA : public Customer
{
public:
    CustomerA() {}
    ~CustomerA() {}
    void TinhTienTra() {
        double money;
        money = getLuongHang() * getDonGia() * 1.1;
        setTienTra(money);
    }
};
class CustomerB : public Customer
{
private: 
    int soNam;
    double discount;
public:
    CustomerB() {}
    ~CustomerB() {}
    void setSoNam(int soNam) {
        this->soNam = soNam;
    }
    void setDiscount() {
        discount = getSoNam() * 5 /100;
        if(discount>0.5) discount = 0.5;
    }
    int getSoNam() {return soNam;}
    double getDiscount() {return discount;}
    istream &operator>>(std::istream &is)
    {
        Customer::operator>>(is);
        int year;
        is >> year;
        setSoNam(year);
        TinhTienTra();
        return is;
    }
    void TinhTienTra() {
        setDiscount();
        double tien;
        tien = getLuongHang() * getDonGia() * (1- getDiscount()) * 1.1;
        setTienTra(tien);
    }
};
class CustomerC : public Customer
{
public:
    CustomerC() {}
    ~CustomerC() {}
    void TinhTienTra() {
        double tien;
        tien = getLuongHang() * getDonGia() * 0.5 * 1.1;
        setTienTra(tien);
    }
};
int main() 
{
    ifstream file;
    file.open("XYZ.INP.txt");
    if (!file.is_open())
    {
        cout << "Can't open file\n";
    }
    else
    {
        int x, y, z;
        file >> x;
        file >> y;
        file >> z;
        vector<Customer *> Vcustomer;
        Vcustomer.resize(0);
        double Sum = 0;
        for (int i = 0; i < x; i++)
        {
            Vcustomer.push_back(new CustomerA);
            Vcustomer.back()->operator>>(file);
            Sum += Vcustomer.back()->getTientra();
        }
        for (int i = 0; i < y; i++)
        {
            Vcustomer.push_back(new CustomerB);
            Vcustomer.back()->operator>>(file);
            Sum += Vcustomer.back()->getTientra();
        }
        for (int i = 0; i < z; i++)
        {
            Vcustomer.push_back(new CustomerC);
            Vcustomer.back()->operator>>(file);
            Sum += Vcustomer.back()->getTientra();
       }
       file.close();
        ofstream File("XYZ.OUT.txt");
        File << x << " " << y << " " << z << endl;
        for (int i = 0; i < Vcustomer.size(); i++)
        {
            (*Vcustomer[i]).operator<<(File);
        }
        File << "Tong so tien ma cong ty nhan duoc: " << Sum << endl;
        File.close();
    }
    return 0;

}
