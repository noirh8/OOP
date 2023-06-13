#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <limits>
using namespace std;
class Room
{
private:
    double phiDichVu;
    string idPhong;
    int soDem;
    double DoanhThu;
public:
    Room() {
        setIDPhong("").setPhiDichVu(0).setSoDem(0);
    }
    Room(string id, double phi, int dem) {
        setIDPhong(id).setPhiDichVu(phi).setSoDem(dem);
    }
    Room(const Room& room) {
        setIDPhong(room.idPhong).setPhiDichVu(room.phiDichVu).setSoDem(room.soDem);
    }
    ~Room() {}
    Room& setIDPhong(string idPhong) {
        idPhong = idPhong;
        return *this;
    }
    Room& setPhiDichVu(double phi) {
        phiDichVu = phi;
        return *this;
    }
    Room& setSoDem(int dem) {
        soDem = dem;
        return *this;
    }
    string getIDPhong() const {return idPhong;}
    double getPhiDichVu() const {return phiDichVu;}
    int getSoDem() const {return soDem;}
    double getDoanhThu() const {return DoanhThu;}
    virtual void setDoanhThu() = 0;
    virtual void CapNhatDoanhThu(double Doanhthu) {
        DoanhThu = Doanhthu;
    }
    virtual void SetAll() = 0;
    virtual Room* CreateRoom() = 0;
    virtual string TenPhong() = 0;
    void Xuat() {
        cout << getIDPhong() << " - loai: " << TenPhong() << " - Doanh thu: " << (long long) getDoanhThu() << endl;
    }
};
class Deluxe : public Room
{
private:
    double PhiPhucVu;
public:
    Deluxe() {
        setPhiDichVu(0);
    }
    Deluxe(string id, double phi, double phiphucvu, int dem) : Room(id,phi,dem) {
        setPhiPhucVu(phiphucvu);
        setDoanhThu();
    }
    Deluxe(const Deluxe& deluxe) {
        setPhiPhucVu(deluxe.getPhiPhucVu()).setPhiDichVu(deluxe.getPhiDichVu()).setIDPhong(deluxe.getIDPhong()).setSoDem(deluxe.getSoDem());
    }
    ~Deluxe() {}
    Deluxe& setPhiPhucVu(double phiPhucVu) {
        PhiPhucVu = phiPhucVu;
    }
    double getPhiPhucVu() const {return PhiPhucVu;} 
    void setDoanhThu() {
        Room::CapNhatDoanhThu(getSoDem() * 750000 + getPhiPhucVu() + getPhiDichVu());
    }
    Room* CreateRoom() {
        Room* NewRoom = new Deluxe;
        return NewRoom;
    }
    void SetAll() {
        cout << "ID phong: "; 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string id; getline(cin,id);
        double cost;
        cout << "Phi dich vu: "; cin >> cost;
        double costServe;
        cout << "Phi phuc vu: "; cin >> costServe;
        int night;
        cout << "So dem su dung: "; cin >> night;      
        setPhiPhucVu(costServe).setPhiDichVu(cost).setIDPhong(id).setSoDem(night);
        setDoanhThu();  
    }
    string TenPhong() {return "Deluxe room";}
};
class Premium : public Room
{
public:
    Premium() {

    }
    Premium(string id, double phiphucvu, int sodem) : Room(id,phiphucvu,sodem) {

    }
    Premium(const Premium& prenium) {
        setPhiDichVu(prenium.getPhiDichVu()).setIDPhong(prenium.getIDPhong()).setSoDem(prenium.getSoDem());
    }
    ~Premium() {}
    void setDoanhThu() {
        Room::CapNhatDoanhThu((getSoDem()*500000 + getPhiDichVu()) * 1.05);
    }
    Room* CreateRoom() {
        Room* NewRoom = new Premium;
        return NewRoom;
    }
    void SetAll() {
        cout << "ID phong: "; 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string id;
        getline(cin,id);
        double cost;
        cout << "Phi dich vu: "; cin >> cost;
        double costServe;
        cout << "Phi phuc vu: "; cin >> costServe;
        int night;
        cout << "So dem su dung: "; cin >> night;      
        setPhiDichVu(cost).setIDPhong(id).setSoDem(night);
        setDoanhThu();
    }
    string TenPhong() {return "Premium room";}
}; 
class Business : public Room
{
public:
    Business() {}
    Business(const Business& business) {
        setPhiDichVu(business.getPhiDichVu()).setIDPhong(business.getIDPhong()).setSoDem(business.getSoDem());
    }
    Business(string id, double cost, int dem) : Room(id,cost,dem) {}
    ~Business() {}
    void SetAll() {
        cout << "ID phong: "; 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string id;
        getline(cin,id);
        int night;
        cout << "So dem su dung: "; cin >> night;
        setIDPhong(id).setSoDem(night);
        setDoanhThu();
    }
    void setDoanhThu() {
        Room::CapNhatDoanhThu(getSoDem() * 300000);
    }
    Room* CreateRoom() {
        Room* NewRoom = new Business;
        return NewRoom;
    }
    string TenPhong() {return "Bussiness room";}
};
