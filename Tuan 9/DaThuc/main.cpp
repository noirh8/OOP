#include "Fx.cpp"
#include "Gx.cpp"
#include "Hx.cpp"
#include <fstream>
using namespace std;
int main() 
{
    vector<DaThuc*> dt;
    dt.resize(0);
    dt.push_back(new Fx);
    dt.push_back(new Gx);
    dt.push_back(new Hx);
    ifstream file;
    file.open("KHAOSAT.INP.txt");
    if (!file.is_open())
    {
        cout << "Khong the mo file\n";
        return 0;
    }
    double k1, k2, k3, start, end, step;
    file >> k1;
    file >> k2;
    file >> k3;
    file >> start;
    file >> end;
    file >> step;
    file.close();
    ofstream File;
    File.open("KHAOSAT.OUT.txt", ios::app);
    dt[0]->setK(k1);
    dt[1]->setK(k2);
    dt[2]->setK(k3);
    for (double i = start; i <= end; i += step)
    {
        File << i << " ";
    }
    File << endl;
    for (int i = 0; i < 3; i++)
    {
        dt[i]->KhaoSatDT(start, end, step);
    }
    for (int i = 0; i < 3; i++)
    {
        dt[i]->KhaoSatDaoHam(start, end, step);
    }
    File.close();
    return 0;
}
