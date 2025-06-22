#include<bits/stdc++.h>
using namespace std;

class Shape {
public:
    int x = 0, y = 0;
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual int getShape() const = 0;

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
};
class Circle:public Ellipse{
public:
    Circle(int rad) : Ellipse(rad, rad) {}
    int getShape() const{return 2; }
    int getRadii() const { return getXLength(); } 
};
int main() {
    Rectangle r1(5, 3, "Blue");
    r1.setBreadth(10);
    r1.setLength(16);
    double area = 0;
    area = r1.getArea();
    r1.move(2, 3);
    r1.printCoordinate();

    Square s1(5, "Red");
    area=s1.getArea();
    cout <<"square? " ;
    s1.isSquare();

    Circle c1(3);
    area = c1.getArea();

    Shape* A;
    A = new Square(2, "Green");
    A->getArea();
    A->move(1, 2);
    cout << "shape_id = "<< A->getShape() <<endl;
    cout << "position: " << A->getX() << "," << A->getY()<< endl;

    return 0;
}