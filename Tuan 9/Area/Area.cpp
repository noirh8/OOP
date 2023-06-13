#pragma once
#include <iostream>
#include"Rectangle.cpp"
#include"Triangle.cpp"
#include"Circle.cpp"
#include<vector>
using namespace std;

class Area
{
private:
    vector<Shape *> arrShape;
    vector<Shape *> TemplateShape;
public:

    Area() {
        arrShape.resize(0);
        TemplateShape.resize(0);
        TemplateShape.push_back(new Rectangle);
        TemplateShape.push_back(new Triangle);
        TemplateShape.push_back(new Circle);
    }
    ~Area() {
        for (int i = 0; i < arrShape.size(); i++) {
            delete arrShape[i];
        }
    }
    void InputShapes() {
        do {
            int id;
            for (int i = 0; i < TemplateShape.size(); i++) {
                cout << "   " << i + 1 << ". Enter " << TemplateShape[i]->NameShape() << endl;
            }
            cout << "Press: ";
            cin >> id;
            arrShape.push_back(TemplateShape[id - 1]->CreateObject());
            arrShape.back()->Set();

            cout << "Press enter to continue enter other, other press to exit: ";
            fflush(stdin);
        } while (getchar() == '\n');
    }
    void PrintAllShape() {
        for (int i = 0; i < arrShape.size(); i++) {
            arrShape[i]->Print();
            cout << endl;
        }
    }
};
