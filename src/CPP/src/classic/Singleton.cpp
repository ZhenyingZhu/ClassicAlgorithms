#include <iostream>

using namespace std;

// [Solution]: Meyers implementation. In c++11 it is threadsafe
class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    Singleton(const Singleton &) = delete;

    void operator=(const Singleton &) = delete;

private:
    Singleton() { }
};

int main() {
    Singleton &s1 = Singleton::getInstance();
    Singleton &s2 = Singleton::getInstance();
    cout << &s1 << " " << &s2 << endl;

    return 0;
}
