#include <iostream>
#include<vector>
#include <math.h>
using namespace std;
struct Diem
{
    double x;
    double y;
};
class DaGiac
{
private:
    int soDinh;
    vector<Diem> diem;
public:
    DaGiac() {
        SetSoDinh(0);
        vector<Diem> diem;
        diem.resize(0);
        SetDiem(diem);
    }
    DaGiac(int num) {   
        SetSoDinh(num);
        vector<Diem> diem;
        diem.resize(0);
        for(int i =0;i<num;i++){
            diem[i]={0,0};
        }
        SetDiem(diem);
    }
    virtual ~DaGiac() {}
    void SetSoDinh(int num) {
        soDinh = num;
    }
    void SetDiem(vector<Diem> diem) {
        this->diem = diem;
    }
    virtual void Set() {
        vector<Diem> diem;
        diem.resize(GetSoDinh());
        do{
        for(int i=0;i<GetSoDinh();i++){
            cout<<"Diem "<<i+1<<"(x,y): ";
            cin>>diem[i].x;
            cin>>diem[i].y;
    }
        SetDiem(diem);
        } while(Check()==0);
    }
    int GetSoDinh(){return soDinh;}
    vector<Diem> GetDiem(){return diem;}
    virtual void Xuat() {
        vector<Diem> diem;
        diem=GetDiem();
        for(int i=0;i<GetSoDinh();i++){
            cout<<"( "<<diem[i].x<<" , "<<diem[i].y<<" )";
            if(i!=GetSoDinh()-1){
                cout<<"--";
            }
        }
    }
    virtual bool Check() {
        vector<Diem> diem;
        diem=GetDiem();
        for(int i =0;i<GetSoDinh()-1;i++){
            for(int j=i+1;j<GetSoDinh();j++){
                if(diem[i].x==diem[j].x&&diem[i].y==diem[j].y){
                    cout<<"Nhap sai. Vui long nhap lai\n";
                return false;
                }
            }
        }
        return true;
    }
    void TinhTien(int x,int y) {
        vector<Diem> diem;
        diem=GetDiem();
        for(int i=0;i<GetSoDinh();i++){
            diem[i].x+=x;
            diem[i].y+=y;
        }
        SetDiem(diem);
    }
};
class TuGiac : public DaGiac
{
private:
    const int dinh=4;

public:
    TuGiac() {
        SetSoDinh(dinh);
    }
    virtual ~TuGiac() {}
    void Set() {
        DaGiac::Set();
    }
    void Xuat() {
        cout << "Tu giac: ";
        DaGiac::Xuat();
    }
};
class TamGiac final : public DaGiac
{
private:
    const int dinh=3;

public:
    TamGiac() {
        SetSoDinh(dinh);
    }
    ~TamGiac() {}
    void Set() {
        DaGiac::Set();
    }
    void Xuat() {
        cout << "Tam giac: "; 
        DaGiac::Xuat();
    }
};
double DaDiem(Diem c1,Diem c2){
    return c1.x*c2.x+c1.y*c2.y;
}
double Module(Diem c1,Diem c2){
    return sqrt(pow(c1.x-c2.x,2)+pow(c1.y-c2.y,2));
}
Diem VectorDiem(Diem c1,Diem c2){
    Diem c;
    c.x=c1.x-c2.x;
    c.y=c1.y-c2.y;
    return c;
}
class HBH final :public TuGiac
{
public:
    HBH() {}
    ~HBH() {}
    void Set() {
        TuGiac::Set();
    }
    bool Check() {
        Diem TrucY={0,1};
        vector<Diem> c=GetDiem();
        vector<double> value;
        value.resize(0);
        for(int i=0;i<3;i++){
            for(int j=i+1 ;j<4;j++){
                if(DaDiem(VectorDiem(c[i],c[j]),TrucY)==0){
                    value.push_back(Module(c[i],c[j]));
                }
            }
        }
        if(value.size()==2&&value[0]==value[1]){
            return true;
        }
        else{
            cout<<"Nhap sai. Vui long nhap lai" << endl;
            return false;
        }
    }
    void Xuat() {
        cout << "HBH: ";
        TuGiac::Xuat();
    }
};
class HCN : public TuGiac
{
public:
    HCN() {}
    virtual ~HCN() {}
    void Set() {
        TuGiac::Set();
    }
    bool Check() {
        Diem TrucY={0,1};
        Diem TrucX={1,0};
        vector<Diem> c=GetDiem();
        vector<double> Xvalue;
        vector<double> Yvalue;
        Xvalue.resize(0);
        Yvalue.resize(0);
        for(int i=0;i<3;i++){
            for(int j=i+1 ;j<4;j++){
                if(DaDiem(VectorDiem(c[i],c[j]),TrucY)==0){
                    Xvalue.push_back(Module(c[i],c[j]));
                }
                else if(DaDiem(VectorDiem(c[i],c[j]),TrucX)==0){
                    Yvalue.push_back(Module(c[i],c[j]));
                }
                else{
                }
            }
        }
        if(Xvalue.size()==Yvalue.size()){
            return true;
        }
        else{
            cout<<"Nhap sai. Vui long nhap lai\n";
            return false;
        }
    }
    virtual void Xuat() {
        cout << "HCN: ";
        DaGiac::Xuat();
    }
};
class HV final : public HCN
{
public:
    HV() {}
    ~HV() {}
    void Set() {
        TuGiac::Set();
    }
    bool Check() {
        Diem TrucY={0,1};
        Diem TrucX={1,0};
        vector<Diem> c=GetDiem();
        vector<double> Xvalue;
        vector<double> Yvalue;
        Xvalue.resize(0);
        Yvalue.resize(0);
        for(int i=0;i<3;i++){
            for(int j=i+1 ;j<4;j++){
                if(DaDiem(VectorDiem(c[i],c[j]),TrucY)==0){
                    Xvalue.push_back(Module(c[i],c[j]));
                }
                else if(DaDiem(VectorDiem(c[i],c[j]),TrucX)==0){
                    Yvalue.push_back(Module(c[i],c[j]));
                }
                else{
                }
            }
        }
        if(Xvalue.size()==Yvalue.size()&&Xvalue[0]==Yvalue[0]){
            return true;
        }
        else{
            cout<<"Wrong input!Again.\n";
            return false;
        }
    }
    void Xuat() {
        cout << "Hinh vuong: ";
        DaGiac::Xuat();
    }
};
void Input(vector<DaGiac*> &List){
    int chon;
    do{
        cout<<"\t1. Nhap Tu giac\n";
        cout<<"\t2. Nhap Tam Giac\n";
        cout<<"\t3. Nhap HBH\n";
        cout<<"\t4. Nhap HCN\n";
        cout<<"\t5. Nhap HV\n";
        cout<<"\t6. Quay lai menu\n";
        while (cin>>chon&&chon!=1&&chon!=2&&chon!=3&&chon!=4&&chon!=5&&chon!=6)
        {
            cout<<"Nhap sai. Vui long nhap lai ";
        }
        switch (chon)
        {
        case 1:
            List.push_back(new TuGiac);
            List[List.size()-1]->Set();
            break;
        case 2:
            List.push_back(new TamGiac);
            List.back()->Set();
            break;
        case 3:
            List.push_back(new HBH);
            List.back()->Set();
            break;
        case 4:
            List.push_back(new HCN);
            List.back()->Set();
            break;
        case 5:
            List.push_back(new HV);
            List.back()->Set();
            break;
        default:
            break;
        }
    }while(chon!=6);
}
void Xuat(vector<DaGiac*> &List){
    cout<<"-----Xuat danh sach da giac----\n";
    for(int i=0;i<List.size();i++){
        List[i]->Xuat();
        cout<<endl;
    }
    cout<<"--------------------------\n";
}
void TinhTien(vector<DaGiac*>&List){
    cout<<"Input vector(x,y) to move: ";
    int x,y;
    cin>>x>>y;
    for(int i=0;i<List.size();i++){
        List[i]->TinhTien(x,y);
    }
    Xuat(List);
}
int main(){
    vector<DaGiac*> ListPolygons;
    ListPolygons.resize(0);
    int chon;
    do{
        cout<<"Quan li da giac: \n";
        cout<<"\t1. Nhap da giac\n";
        cout<<"\t2. Xuat va tinh tien da giac\n";
        cout<<"\t3. Thoat\n";
        while (cin>>chon&&chon!=1&&chon!=2&&chon!=3)
        {
            cout<<"Nhap sai. Vui long nhap lai";
        }
        switch (chon)
        {
        case 1:
            Input(ListPolygons);
            break;
        case 2:
            Xuat(ListPolygons);
            char x;
            cout<<"Move? (y,n): ";
            while(cin>>x&&x!='n'&&x!='y'){
                cout<<"Nhap sai. Vui long nhap lai\n";
            }
            if(x=='y'){
                TinhTien(ListPolygons);
            }
            break;
        default:
            break;
        }
    }while(chon!=3);
    for(int i=0;i<ListPolygons.size();i++){
        delete ListPolygons[i];
    }
    return 0;
}
