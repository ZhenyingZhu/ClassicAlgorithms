#include <iostream>
#include <vector>

using namespace std;

// template on a function
template <typename T>
const T& Max(const T &a, const T &b) {
    return a > b ? a : b;
}

// template on members own by a class, maybe it is not a correct way
template <typename T>
class NotGeneric {
public:
    void push(const T &item) {
        vec.push_back(item);
    }

    const T& top() const {
        return vec.front();
    }

    const T& bottom() const;
private:
    vector<T> vec;
};
// when implement outside, need put T to the class
template <typename T>
const T& NotGeneric<T>::bottom() const {
    return vec.back();
};

// template on a class
template <class T>
class Generic {
public:
    void push(const T &item) {
        vec.push_back(item);
    }

    const T& top() const;

private:
    vector<T> vec;
};

// template on the class, so that when instanize, need the type
template <class T>
const T& Generic<T>::top() const {
    return vec.front();
}

int main() {
    int a = 1, b = 2;
    cout << Max(a, b) << endl;

    NotGeneric<int> ng;
    ng.push(1);
    cout << ng.top() << endl;
    cout << ng.bottom() << endl;

    Generic<int> g;
    g.push(1);
    cout << g.top() << endl;
}
