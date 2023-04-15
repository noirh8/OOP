#pragma once

class Polygon
{
private:
    int NumApices;
    Coordinate *ApexList = new Coordinate[NumApices];
public:
    Polygon();
    ~Polygon();
    void Input();
    void Output();
    void TranslatePolygon();
    void RotatePolygon();
    void ZoomInOut();
};
