#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace std;

class Shape {
public:
    int x = 0, y = 0;
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual int getShape() const = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

    void move(int x2, int y2) {
        x = x2;
        y = y2;
    }
    void printCoordinate() const{
        cout<<x<<','<<y<<endl;
    }
    int getX() const { return x; }
    int getY() const { return y; }

    virtual ~Shape() = default;
};
class Rectangle: public Shape {
    int len;
    int bread;
    string col;
public:
    Rectangle(int l, int b, string color) : len(l), bread(b), col(color) {}

    int getLength() const { return len; }
    int getBreadth() const { return bread; }

    void setLength(int length){ len = length; }
    void setBreadth(int breadth){ bread = breadth; };
    void setColor(string color){ col = color; };

    void draw(sf::RenderWindow& window){
        sf::RectangleShape rect(sf::Vector2f(len * 10, bread * 10));
        rect.setPosition(x, y);
        rect.setFillColor(sf::Color::Blue);
        window.draw(rect);
    }
    double getArea() const{ 
        cout<< len * bread<<endl;
        return len*bread;
     };
    double getPerimeter() const{ 
        cout<<2 * (len + bread)<<endl;
        return 2 * (len + bread);
     };
    void isSquare() const { 
        if( len == bread) cout<< "true"<<endl;
        else  cout<<"false"<<endl;    
    }
    int getShape() const{return 0; }
};
class  Square: public Rectangle{
public:
    Square(int length, string col) : Rectangle(length, length, col) {}
    int getShape() const{return 1; }
    void draw(sf::RenderWindow& window){
        sf::RectangleShape sq(sf::Vector2f(getLength() * 10, getLength() * 10));
        sq.setPosition(x, y);
        sq.setFillColor(sf::Color::Red);
        window.draw(sq);
    }
};
class Ellipse:public Shape{
    int a, b;  

public:
    Ellipse(int x_axis, int y_axis) : a(x_axis), b(y_axis) {}
    double getArea() const{
        double area = 3.14 *a*b;
        cout <<area <<endl;
        return area;
    }
    double getPerimeter() const{
        double perimeter = 2 * 3.14 * sqrt(((a*a) + (b*b))/2);
        cout << perimeter << endl;
        return perimeter;
    }
    int getShape() const{return 3; }
    int getXLength() const { return a; }
    int getYLength() const { return b; }
    void draw(sf::RenderWindow& window)  {
        sf::CircleShape ell(10);
        ell.setScale(getXLength(), getYLength());
        ell.setPosition(x, y);
        ell.setFillColor(sf::Color::Yellow);
        window.draw(ell);
    }
};
class Circle:public Ellipse{
public:
    Circle(int rad) : Ellipse(rad, rad) {}
    int getShape() const{return 2; }
    int getRadii() const { return getXLength(); }
    void draw(sf::RenderWindow& window){
        sf::CircleShape circ(getRadii() * 10);
        circ.setPosition(x, y);
        circ.setFillColor(sf::Color::Black);
        window.draw(circ);
    } 
};