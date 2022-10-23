#include <iostream>
#include <memory>

using namespace std;

class Base {
public:
    Base(): name_("Base") { }

    ~Base() {
        cout << "Destorying Base " << name_ << endl;
    }

    virtual string getName() const {
        return name_;
    }

protected:
    string name_;
};

class ChildOne: public Base {
public:
    ChildOne() {
        name_ = "Child1";
    }

    ~ChildOne() {
        cout << "Destorying Child1 " << name_ << endl;
    }
};

class ChildTwo: public Base {
public:
    ChildTwo() {
        name_ = "Child2";
    }

    ~ChildTwo() {
        cout << "Destorying Child2 " << name_ << endl;
    }
};

void getChildOne(shared_ptr<Base> &base) {
    // static_pointer_cast cannot distinguish bwtween ChildOne and ChildTwo
    if (dynamic_pointer_cast<ChildOne>(base) != NULL)
        cout << base->getName() << endl;
    else
        cout << "base is not a Child1 class" << endl;
}

int main() {
    shared_ptr<Base> c1(new ChildOne());
    getChildOne(c1);
    shared_ptr<Base> c2(new ChildTwo());
    getChildOne(c2);

    return 0;
}
