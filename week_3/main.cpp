#include <vector>
#include "Shape.h"
#include <SFML/Graphics.hpp>
using namespace std;


class Canvas {
    vector<Shape*> shapes;
public:
    void addShape(Shape* s);
    void displayCanvas();
};

void Canvas::addShape(Shape* s) {
    shapes.push_back(s);
}
void Canvas::displayCanvas() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Canvas");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                     window.close();
        }
        window.clear(sf::Color::White);

        for (Shape* shape : shapes) {
            shape->draw(window);
        }

        window.display();
    }
}


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

    Canvas c;
    c.addShape(new Rectangle(4, 5, "Blue"));
    c.addShape(new Circle(10));
    c.addShape(new Square(6, "Red"));
    r1.move(100, 100);
    c1.move(50,50);
    c.addShape(&r1);
    c.addShape(new Ellipse(4, 2));  
    c.displayCanvas();

    return 0;
}