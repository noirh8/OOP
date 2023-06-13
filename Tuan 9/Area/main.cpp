#include<iostream>
#include"Area.cpp"
using namespace std;
int main(){
    Area Shapes;
    int key;
    cout << "Program: \n";
    do{
        cout << "1. Input all shapes.\n";
        cout << "2. Show all area and circuit value of all shapes inputted.\n";
        cout << "3. exit.Press: ";
        while (cin >> key && key != 1 && key != 2 && key != 3)
        {
            cout << "Just input 1,2 or 3. Again: ";
        }
        switch (key)
        {
        case 1:
            Shapes.InputShapes();
            break;
        case 2:
            Shapes.PrintAllShape();
            break;
        default:
            break;
        }
    } while (key != 3);
    cout << "Thanks!\n";
}
