#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct MyClass {
public:
    MyClass() {
        val = 0;
        cout << "MyClass() called " << this << endl;
    }

    MyClass(int v): val(v) {
        cout << "MyClass(int v) called with val " << v << " " << this << endl;
    }

    MyClass(const MyClass &cpy) {
        val = cpy.val;
        cout << "MyClass(const MyClass &cpy) copy " << &cpy << " to " << this << endl;
    }

    MyClass& operator=(const MyClass &cpy) {
        val = cpy.val;
        cout << "operator=(const MyClass &cpy) copy " << &cpy << " to " << this << endl;
        return *this;
    }

    ~MyClass() {
        cout << "~MyClass() called with val " << val << " " << this << endl;
    }

    int val;
};

int main() {
    // contain is on stack, but the objects in the contain is on heap
    unordered_map<int, MyClass> map;

    // Create an obj1 on heap
    MyClass a(1);
    cout << "assign is done" << endl;
    
    map[1] = a;
    // What happened
    // map[1]: MyClass() called tmp1
    // MyClass(const MyClass &cpy) copy tmp1 to tmp2
    // MyClass(const MyClass &cpy) copy tmp2 to tmp3
    // ~MyClass() called with val 0 tmp2
    // MyClass(const MyClass &cpy) copy tmp3 to target
    // ~MyClass() called with val 0 tmp3
    // ~MyClass() called with val 0 tmp1
    // = a: operator=(const MyClass &cpy) copy obj1 to target
    cout << "Ops are done" << endl;

    cout << &map[1] << endl;
    MyClass *ptr = &map[1];
    cout << ptr->val << endl;
    
    unordered_map<int, MyClass*> pointerMap;
    pointerMap[1] = new MyClass(1);
    cout << pointerMap[1]->val << endl;
    delete pointerMap[1]; // Otherwise never deleted

    return 0;
}
