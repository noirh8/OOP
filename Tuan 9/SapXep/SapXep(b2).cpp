#include <iostream>
#include <typeinfo>
using namespace std;
template <class T, int n>
class Mang
{
private:
    T arr[n];
public:
    Mang() {}
    explicit Mang(const T& v) {
        for(int i=0; i<n; i++) {
            arr[i] = v;
        }
    }
    virtual T& operator [] (int i) {
        if(i<0||i>n) {
            cout << i << " la gioi han cua mang"<< endl;
            exit(EXIT_FAILURE);
        }
        return arr[i];
    }
    virtual operator[] (int i) const {
        if(i<0||i>n) {
            cout << i << " la gioi han cua mang"<< endl;
            exit(EXIT_FAILURE);
        }
        return arr[i];
    }
    //Xep mang tang dan
    void SapXep() {
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if(arr[i]>arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    //Xep mang giam dan theo gia tri tuyet doi
    void XepGiamModule() {
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                T a = (arr[i]<0) ? -arr[i] : arr[i];
                T b = (arr[j]<0) ? -arr[j] : arr[j];
                if(a<b) {
                    T temp = a;
                    a = b; 
                    b = temp;
                }
            }
        }
    }
    // Xep mang voi so nguyen chan tang, so nguyen le giam
    void XepChanLe() {
        if(typeid(T).name() == typeid(int).name()) {
            T chan[n];
            int nChan = 0;
            T le[n];
            int nLe = 0;
            for(int i=0; i<n; i++) {
                if((int)arr[i]%2==0) {
                    chan[nChan++] = arr[i];
                }
                else {
                    le[nLe++] = arr[i];
                }
            }
            int k=0;
            for(int i=0; i<nChan-1; i++) {
                for(int j=i+1; j<nChan; j++) {
                    if(chan[i]>chan[j]) {
                        T temp = chan[i];
                        chan[i] = chan[j];
                        chan[j] = temp;
                    }
                }
                arr[k++] = chan[i];
            }
            arr[k++] = le[nLe-1];
            for(int i=0; i<nLe-1; i++) {
                for(int j=i+2; j<nLe; j++) {
                    if(le[i] < le[j]) {
                        T temp = le[i];
                        le[i] = le[j];
                        le[j] = temp;
                    }
                }
                arr[k++] = le[i];
            }
            arr[k++] = le[nLe -1];
        }
        else { 
            cout << "Mang khong co so nguyen" << endl;
        }
    }
    //Xep mang so nguyen am giam, so nguyen duong tang, am truoc duong
    void XepAmDuong() {
        T Duong[n];
        int nDuong=0;
        T Am[n];
        int nAm=0;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                Duong[nDuong++]=arr[i];
            }
            else {
                Am[nAm++]=arr[i];
            }
        }
        int k=0;
        for(int i =0;i<nDuong-1;i++){
            for(int j=i+1;j<nDuong;j++){
                if(Duong[i]>Duong[j]){
                    T temp=Duong[i];
                    Duong[i]=Duong[j];
                    Duong[j]=temp;
                }
            }
            arr[k++]=Duong[i];
        }
        arr[k++]=Duong[nDuong-1];
        for(int i =0;i<nAm-1;i++){
            for(int j=i+1;j<nAm;j++){
                if(Am[i]<Am[j]){
                    T temp=Am[i];
                    Am[i]=Am[j];
                    Am[j]=temp;
                }
            }
            arr[k++]=Am[i];
        }
        arr[k++]=Am[nAm-1];
    }
    friend ostream& operator << (ostream& os, const Mang<T,n> &arr) {
        for(int i=0; i<n; i++) {
            os << arr[i] << " ";
        }
        return os;
    }
};
int main() 
{
    cout<<"----------SO NGUYEN----------\n";
    Mang<int,5> arrINT(1);
    int arr[5]={1,8,-7,3,-4};
    for(int i=0;i<5;i++){
        arrINT[i]=arr[i];
    }
    cout << "Mang ban dau: "<< arrINT << endl;
    arrINT.SapXep();
    cout << "Mang sau khi sap xep: "<< arrINT << endl;
    arrINT.XepGiamModule();
    cout << "Mang sau khi sap xep giam dan theo tri tuyet doi: "<< arrINT << endl;
    arrINT.XepChanLe();
    cout << "Mang sau khi sap xep theo chan le: "<< arrINT << endl;
    arrINT.XepAmDuong();
    cout << "Mang sau khi sap xep theo so nguyen am va nguyen duong: " << arrINT << endl;
    cout<< endl;
    cout<<"----------SO THUC----------\n";
    Mang<double,5> arrDouble(1);

    double dou[5]={-1.9,5.3,5.1,2.3,4.2};
    for(int i=0;i<5;i++){
        arrDouble[i]=dou[i];
    }
    cout << "Mang ban dau: " << arrDouble << endl;
    arrDouble.SapXep();
    cout << "Mang sau khi sap xep: " << arrDouble << endl;
    arrDouble.XepGiamModule();
    cout << "Mang sau khi sap xep giam dan theo tri tuyet doi: " << arrDouble << endl;
    arrDouble.XepChanLe();
    cout << "Mang sau khi sap xep theo chan le: " << arrDouble << endl;
    arrDouble.XepAmDuong();
    cout << "Mang sau khi sap xep theo so nguyen am va nguyen duong: " << arrDouble << endl;
    return 0;
}
