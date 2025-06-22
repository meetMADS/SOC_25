
    Shape* A;
    A = new Square(2, "Green");
    
    A->getArea();
    cout << "shape_id = " << A->getShape() << endl;
    cout << "Shape position: (" << A->getX() << "," << A->getY() << ")" << endl;

    delete A;
    return 0;
}
