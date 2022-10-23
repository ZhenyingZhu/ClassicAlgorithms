#include <iostream>

using namespace std;

struct MyClass {
    // default membership value is only support in C++11
    int val = 0;
};

int main() {
    MyClass mc;
    cout << mc.val << endl;

    return 0;
}
