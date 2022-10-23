#include <iostream>

using namespace std;

class Base {
protected:
    // private func cannot be called by child class
    void foo() {
        cout << "Base foo" << endl;
    }
};

class Inherit: public Base {
public:
    void foo() {
        cout << "Inhert foo" << endl;
        Base::foo();
    }
};

int main() {
    Inherit i;
    i.foo();

    return 0;
}
