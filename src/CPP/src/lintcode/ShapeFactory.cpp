/*
 * [Source] http://www.lintcode.com/en/problem/shape-factory/
 * [Difficulty]: Easy
 * [Tag]: 
 */

#include <iostream>

using namespace std;

// [Corner Case]:
// [Solution]:
class Shape {
public:
    virtual void draw() const = 0;
};

class Rectangle: public Shape {
    void draw() const {
        cout << " ----" << endl;
        cout << "|    |" << endl;
        cout << " ----" << endl;
    }
};

class Square: public Shape {
    void draw() const {
        cout << " ----" << endl;
        for (int i = 0; i < 2; ++i)
            cout << "|    |" << endl;
        cout << " ----" << endl;
    }
};

class Triangle: public Shape {
    void draw() const {
        cout << "  /\\" << endl;
        cout << " /  \\" << endl;
        cout << "/____\\" << endl;
    }
};

class ShapeFactory {
public:
    /**
     * @param shapeType a string
     * @return Get object of type Shape
     */
    Shape* getShape(string shapeType) {
        if (shapeType == "Rectangle")
            return new Rectangle;
        else if (shapeType == "Square")
            return new Square;
        else if (shapeType == "Triangle")
            return new Triangle;
        else
            return NULL;
    }
};

// [Solution]:

int main() {
    ShapeFactory sf;
    Shape *rec = sf.getShape("Rectangle");
    rec->draw();
    Shape *squ = sf.getShape("Square");
    squ->draw();
    Shape *tri = sf.getShape("Triangle");
    tri->draw();

    return 0;
}
