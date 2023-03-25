#include <iostream>
using namespace std;
struct Student
{
    string name;
    float math;
    float literature;
};
Student inforStudent(Student &x)
{
    cout << "Name of Student: ";
    getline(cin,x.name);
    cout << "Math grade: ";
    cin >> x.math;
    cout << "Literature grade: ";
    cin >> x.literature;
    return x;
}
int main()
{
    Student x;
    inforStudent(x);
    float Avr = (x.math + x.literature) / 2;
    cout << "Student " << x.name << "'s avarage grade: " << Avr << endl;
    return 0;
}
