#include <iostream>

using namespace std;

class SuperClass {
public:
    virtual void print() {
        cout << "Super" << endl;
    }
};

class ChildClass: public SuperClass {
public:
    void print() {
        cout << "Child" << endl;
    }
};

int main() {
    SuperClass *s = new ChildClass;
    // 1. without define SuperClass::print() as virtual, it is static binded, which resolved at compile time. s->print() return Super
    // 2. with virtual function, a virtual table is defined, which is used for dynamic binding. vtable stores pointers to the most derived function.
    s->print();

    return 0;
}
