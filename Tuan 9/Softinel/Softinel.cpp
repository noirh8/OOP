#include "Room.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class Sofitel 
{
private:
    vector<Room*> arrRoom;
    int numDeluxeRoom;
    int numPremiumRoom;
    int numBusinessRoom;
    double SumDoanhThuDeluxe;
    double SumDoanhThuPremium;
    double SumDoanhThuBusiness;
public:
    Sofitel() {
        arrRoom.resize(0);
    }
    ~Sofitel() {
        for(int i=0; i<arrRoom.size(); i++) {
            delete arrRoom[i];
        }
    }

    Sofitel& setSumDoanhThuDeluxe(double deluxe) {
        SumDoanhThuDeluxe = deluxe;
    }
    Sofitel& setSumDoanhThuPremium(double premium) {
        SumDoanhThuPremium = premium;
    }
    Sofitel& setSumDoanhThuBusiness(double business) {
        SumDoanhThuBusiness = business;
    }
    Sofitel& setNumDeluxeRoom(int numdeluxe) {numDeluxeRoom = numdeluxe;}
    Sofitel& setNumPremiumRoom(int numpremium) {numPremiumRoom = numpremium;}
    Sofitel& setNumBusinessRoom(int numbusiness) {numBusinessRoom = numbusiness;}

    double getSumDoanhThuDeluxe() const {return SumDoanhThuDeluxe;}
    double getSumDoanhThuPremium() const {return SumDoanhThuPremium;}
    double getSumDoanhThuBusiness() const {return SumDoanhThuBusiness;}
    int getNumDeluxeRoom() {return numDeluxeRoom;}
    int getNumPremiumRoom() {return numPremiumRoom;}
    int getNumBusinessRoom() {return numBusinessRoom;}
    vector<Room*> GetArr() {return arrRoom;}
    
    void NhapRoomsFile() {
        arrRoom.resize(0);
        string filename;
        cout << "Enter file name: ";
        cin >> filename;
        ifstream file;
        file.open(filename);
        if (!file.is_open())
        {
            cout << "Khong the mo file\n";
            return;
        }
        int d = 0, p = 0, b = 0;
        double sumDeluxe = 0, sumPreium = 0, sumBusiness = 0;
        file >> d >> p >> b;
        setNumDeluxeRoom(d).setNumPremiumRoom(p).setNumBusinessRoom(b);
        for (int i = 0; i < d; i++)
        {
            string id;
            file.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(file, id);
            double cost;
            file >> cost;
            double costserver;
            file >> costserver;
            int night;
            file >> night;
            arrRoom.push_back(new Deluxe(id, cost, costserver, night));
            sumDeluxe += arrRoom.back()->getDoanhThu();
        }
        for (int i = 0; i < p; i++)
        {
            arrRoom.push_back(new Premium);
            string id;
            file.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(file, id);
            double cost;
            file >> cost;
            int night;
            file >> night;
            arrRoom.back()->setPhiDichVu(cost).setIDPhong(id).setSoDem(night);
            arrRoom.back()->setDoanhThu();
            sumPreium += arrRoom.back()->getDoanhThu();
        }
        for (int i = 0; i < b; i++)
        {
            arrRoom.push_back(new Business);
            string id;
            file.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(file, id);
            int night;
            file >> night;
            arrRoom.back()->setIDPhong(id).setSoDem(night);
            arrRoom.back()->setDoanhThu();
            sumBusiness += arrRoom.back()->getDoanhThu();
        }
        setSumDoanhThuDeluxe(sumDeluxe).setSumDoanhThuPremium(sumPreium).setSumDoanhThuBusiness(sumBusiness);
    }
    void Nhap() {
        double sumDeluxe = 0, sumPreium = 0, sumBusiness = 0;
        int d, p, b;
        cout << "Num of deluxe rooms: ";
        cin >> d;
        arrRoom.resize(0);
        for (int i = 0; i < d; i++)
        {
            cout << "Room " << i + 1 << " deluxe:\n";
            arrRoom.push_back(new Deluxe);
            arrRoom.back()->SetAll();
            sumDeluxe += arrRoom.back()->getDoanhThu();
        }
        cout << "Num of premium room: ";
        cin >> p;
        for (int i = 0; i < p; i++)
        {
            cout << "Room " << i + 1 << " premium:\n";
            arrRoom.push_back(new Premium);
            arrRoom.back()->SetAll();
            sumPreium += arrRoom.back()->getDoanhThu();
        }
        cout << "Num of business rooms: ";
        cin >> b;
        for (int i = 0; i < b; i++)
        {
            cout << "Room " << i + 1 << " business:\n";
            arrRoom.push_back(new Business);
            arrRoom.back()->SetAll();
            sumBusiness += arrRoom.back()->getDoanhThu();
        }
        setNumDeluxeRoom(d).setNumPremiumRoom(p).setNumBusinessRoom(b).setSumDoanhThuDeluxe(sumDeluxe).setSumDoanhThuPremium(sumPreium).setSumDoanhThuBusiness(sumBusiness);
    }
    void XuatDoanhThu()
    {
        cout << "Tong doanh thu cua deluxe room: " << (long long)getSumDoanhThuDeluxe() << endl;
        cout << "Tong doanh thu cua premium rooms: " << (long long)getSumDoanhThuPremium() << endl;
        cout << "Tong doanh thu cua business rooms: " << (long long)getSumDoanhThuBusiness() << endl;
    }
    void XuatAllRoom()
    {
        for (int i = 0; i < arrRoom.size(); i++) {
            arrRoom[i]->Xuat();
        }
    }
    void RoomVuotTroi() {
        ofstream file;
        file.open("SOFITEL.OUT.txt");
        Sofitel DoanhThuThangTruoc;
        cout << "Nhap doanh thu thang truoc: \n";
        DoanhThuThangTruoc.NhapRoomsFile();
        vector<Room *> arr = DoanhThuThangTruoc.GetArr();
        vector<Room *> arrAdvanceRoom;
        arrAdvanceRoom.resize(0);
        int n = (arr.size() <= arrRoom.size()) ? arr.size() : arrRoom.size();
        for (int i = 0; i < n; i++)
        {
            if (arrRoom[i]->getDoanhThu() >= 1.25 * arr[i]->getDoanhThu())
            {
                arrAdvanceRoom.push_back(arrRoom[i]);
            }
        }
        cout << arrAdvanceRoom.size() << " room advance revenue: \n";
        file << arrAdvanceRoom.size() << " room advance revenue: \n";
        for (int i = 0; i < arrAdvanceRoom.size(); i++)
        {
            cout << "Room: " << arrAdvanceRoom[i]->getIDPhong() << endl;
            file << "Room: " << arrAdvanceRoom[i]->getIDPhong() << endl;
        }
        file.close();
    }
};
int main() 
{
    Sofitel hotel;
    int CatchKey;
    cout << "_____ SOFITEL _____\n";
    do
    {
        cout << "__________Menu__________\n";
        cout << "1. Nhap room tu file\n";
        cout << "2. Nhap room thu cong\n";
        cout << "3. Xuat tong doanh thu cua tung loai room\n";
        cout << "4. Xuat thong tin tung room\n";
        cout << "5. Xuat thong tin phong doanh thu vuoi troi\n";
        cout << "6. Thoat\n";
        cout << "Press: ";
        while (cin >> CatchKey && CatchKey != 1 && CatchKey != 2 && CatchKey != 3 && CatchKey != 4 && CatchKey != 5 && CatchKey != 6)
        {
            cout << "Chon sai. Vui long chon lai" << endl;
        }
        switch (CatchKey)
        {
        case 1:
            hotel.NhapRoomsFile();
            break;
        case 2:
            hotel.Nhap();
            break;
        case 3:
            hotel.XuatDoanhThu();
            break;
        case 4:
            hotel.XuatAllRoom();
            break;
        case 5:
            hotel.RoomVuotTroi();
            break;
        default:
            break;
        }
    } while (CatchKey != 6);
    return 0;
}
