#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void foo() {
    for (int i = 0; i < 3; ++i) {
        cout << "foo " << i << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void f(int times, string word) {
    for (int i = 0; i < times; ++i) {
        cout << word << " " << i << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

class Task {
public:
    void operator()() {
        for (int i = 0; i < 3; ++i) {
            cout << "task " << i << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
};

int main() {
    // func with args
    //thread t(foo);

    // a callable class
    //Task task;
    //thread t(task);

    // func with args
    thread t(f, 3, "foo");

    cout << "main thread" << endl;
    t.join();

    cout << "main finish" << endl;
    return 0;
}
