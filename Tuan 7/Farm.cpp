#include <iostream>
#include<string>
#include <vector>
#include <time.h>
#include <random>
using namespace std;
class GiaSuc
{
private:
    int SinhCon;
    int LitSua;
    string Keu;
public:
    GiaSuc() {
        SetSinhCon(0);
        SetLitSua(0);
        SetKeu("");
    }
    GiaSuc(int Con, int sua, const string keu) {
        SetSinhCon(Con);
        SetLitSua(sua);
        SetKeu(keu);
    }
    virtual ~GiaSuc() { }
    
    int GetSinhCon() { return SinhCon; }
    int GetLitSua() { return LitSua; }
    string GetKeu() { return Keu; }
    
    void SetSinhCon(int num) {
        SinhCon = num;
    }
    void SetLitSua(int milk) {
        LitSua = milk;
    }
    void SetKeu(string say) {
        Keu = say;
    }
    
    virtual void  Say() = 0;
    virtual void Print() {
        cout << " co " << GetSinhCon() << "con va " << GetLitSua() << " lit sua " << endl;
        cout << "Tieng keu: " << GetKeu() << endl;
    }
};
class Bo :public GiaSuc
{
private:
    const string say = "Mooo";
public:
    Bo() {
        SetSinhCon(rand()%10);
        SetLitSua(rand()%20+1);
        SetKeu(say);
    }
    ~Bo() { }
    virtual void Say() {
        cout << say << endl;
    }
    void Print() {
        cout << "Bo";
        GiaSuc::Print();
    }
};
class Cuu : public GiaSuc
{
private:
    const string say = "Baaa";
public:
    Cuu() {
        SetSinhCon(rand() % 10);
        SetLitSua(rand() % 5 + 1);
        SetKeu(say);
    }
    ~Cuu() { }
    virtual void Say() {
        cout << say << endl;
    }
    void Print() {
        cout << "Cuu";
        GiaSuc::Print();
    }
};
class De :public GiaSuc
{
private:
    const string say = "Mehh";
public:
    De() {
        SetSinhCon(rand() % 10);
        SetLitSua(rand() % 10 + 1);
        SetKeu(say);
    }
    ~De() { }
    virtual void Say() {
        cout << say << endl;
    }
    void Print() {
        cout << "De";
        GiaSuc::Print();
    }
};
void Input(vector<vector<GiaSuc*>>& List) {
    int CatchKey;
    do {
        cout << "\tNhan 1 de chon bo\n";
        cout << "\tNhan 2 de chon cuu\n";
        cout << "\tNhan 3 de chon de\n";
        cout << "\tNhan 4 de quay lai\n";
        while (cin >> CatchKey && CatchKey != 1 && CatchKey != 2 && CatchKey != 3 && CatchKey != 4)
        {
            cout << "Chon sai. Vui long chon lai";
        }
        switch (CatchKey)
        {
        case 1:
            int n;
            cout << "Nhap so bo: ";
            cin >> n;
            List[0].resize(0);
            for (int i = 0; i < n; i++) {
                List[0].push_back(new Bo);
            }
            break;
        case 2:
            int p;
            cout << "Nhap so cuu: ";
            cin >> p;
            List[1].resize(0);
            for (int i = 0; i < p; i++) {
                List[1].push_back(new Cuu);
            }
            break;
        case 3:
            int m;
            cout << "Nhap so de: ";
            cin >> m;
            List[2].resize(0);
            for (int i = 0; i < m; i++) {
                List[2].push_back(new De);
            }
            break;
        default:
            break;
        }
    } while (CatchKey != 4);
}

void Print(vector<vector<GiaSuc*>>& List) {
    cout << "-----Print List Cattle----\n";
    for (int i = 0; i < List.size(); i++) {
        for (int j = 0; j < List[i].size(); j++) {
            List[i][j]->Print();
            cout << endl;
        }
    }
}
void Say(vector<vector<GiaSuc*>>& List) {
    cout << "-----Say to feed----\n";
    for (int i = 0; i < List.size(); i++) {
        for (int j = 0; j < List[i].size(); j++) {
            List[i][j]->Say();
            cout << endl;
        }
    }
    cout << "--------------------------\n";
}
int main() {
    srand(time(NULL));
    vector<vector<GiaSuc*>> ListCattle;
    ListCattle.resize(3);
    int CatchKey;
    do {
        cout << "Quan li: \n";
        cout << "\tNhan 1 de nhap cac loai gia suc\n";
        cout << "\tNhan 2 de hien thi cac loai gia suc\n";
        cout << "\tNhan 3 de hien tieng keu\n";
        cout << "\tNhan 4 de thoat\n";
        while (cin >> CatchKey && CatchKey != 1 && CatchKey != 2 && CatchKey != 3 && CatchKey != 4)
        {
            cout << "Chon sai. Vui long chon lai";
        }
        switch (CatchKey)
        {
        case 1:
            Input(ListCattle);
            break;
        case 2:
            Print(ListCattle);
            break;
        case 3:
            Say(ListCattle);
            break;
        default:
            break;
        }
    } while (CatchKey != 4);
    for (int i = 0; i < ListCattle.size(); i++) {
        for (int j = 0; j < ListCattle[i].size(); j++) {
            delete ListCattle[i][j];
        }
    }
    return 0;
}
