#include <iostream>
#include <ostream>
#include <algorithm>

using namespace std;

class MyClass {
public:
    MyClass(): val(0) { }
    MyClass(int v): val(v) { }
    MyClass(const MyClass &cpy) {
        this->val = cpy.val;
    }

    MyClass& operator=(const MyClass &cpy) {
        this->val = cpy.val;
        return *this;
    }

    bool operator<(const MyClass &cpy) const {
        return this->val < cpy.val;
    }

    int val;
};

ostream& operator<<(ostream &out, const MyClass &mc) {
    out << mc.val;
    return out;
}

bool smaller(const MyClass &mc1, const MyClass &mc2) {
    return mc1.val < mc2.val;
}

int main() {
    vector<MyClass> vec;
    for (int i = 0; i < 5; ++i) {
        vec.push_back(MyClass(i));
    }

    // sort can call MyClass::operator<. 
    // Notice to use in sort when a==b, this func must return false
    //sort(vec.begin(), vec.end());
    sort(vec.begin(), vec.end(), smaller);

    for (MyClass &mc : vec)
        cout << mc << " ";
    cout << endl;
}
