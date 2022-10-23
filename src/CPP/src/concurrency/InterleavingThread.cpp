#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

using namespace std;

// [Source]: EPI 20.3

bool even = false;
mutex mtx;
condition_variable cond;

void printEven() {
    unique_lock<mutex> lck(mtx);
    for (int i = 2; i <= 10; i += 2) {
        while (!even) {
            cond.wait(lck);
        }
        cout << i << endl;
        even = false;
        cond.notify_one();
    }
}

void printOdd() {
    unique_lock<mutex> lck(mtx);
    for (int i = 1; i < 10; i += 2) {
        while (even)
            cond.wait(lck);
        cout << i << endl;
        even = true;
        cond.notify_one();
    }
}

int main() {
    thread t1(printOdd);
    thread t2(printEven);

    t1.join();
    t2.join();

    return 0;
}
