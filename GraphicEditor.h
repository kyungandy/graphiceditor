#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H

#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual ~Shape() {}
    virtual void draw() const = 0;
};

class Line : public Shape {
public:
    void draw() const override {
        cout << "Line" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        cout << "Rectangle" << endl;
    }
};

class GraphicEditor {
private:
    vector<Shape*> shapes;

public:
    ~GraphicEditor(); 
    void insertShape();
    void deleteShape();
    void showShapes() const;
    void run();
};

#endif 