#include<bits/stdc++.h>
using namespace std;

class Rectangle {
private:
    double length;
    double breadth;
    string color;

public:
    Rectangle(double len = 1.0, double bread = 1.0, string col = "White");

    double getLength() const;
    double getBreadth() const;
    string getColor() const;

    void setLength(double len);
    void setBreadth(double bread);
    void setColor(string col);

    double getArea() const;
    double getPerimeter() const;
    void displayInfo() const;
};


Rectangle::Rectangle(double len, double bread, string col) : length(len), breadth(bread), color(col) {}

double Rectangle::getLength() const { return length; }
double Rectangle::getBreadth() const { return breadth; }
string Rectangle::getColor() const { return color; }

void Rectangle::setLength(double len) { length = len; }
void Rectangle::setBreadth(double bread) { breadth = bread; }
void Rectangle::setColor(string col) { color = col; }

double Rectangle::getArea() const { return length * breadth; }
double Rectangle::getPerimeter() const { return 2 * (length + breadth); }

void Rectangle::displayInfo() const {
    cout << "Rectangle: " << length << " x " << breadth
              << ", Color: " << color
              << ", Area: " << getArea()
              << ", Perimeter: " << getPerimeter()
              << endl;
}

int main() {
    Rectangle r1(5, 3, "Blue");
    r1.displayInfo();

    return 0;
}