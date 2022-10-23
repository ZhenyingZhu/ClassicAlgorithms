#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

// [Source]: EPI Chapter 20 Intro
class Semaphore {
public:
    Semaphore(int maxAvailable):
        maxAvailable_(maxAvailable),
        token_(0) { }

    void acquire() {
        unique_lock<mutex> lock(mx_);
        while (token_ == maxAvailable_) {
            cout << "Not ready" << endl;
            cond_.wait(lock);
        }
        cout << "Ready" << endl;
        ++token_;
    }

    void release() {
        unique_lock<mutex> lock(mx_);
        --token_;
        cond_.notify_all();
    }

private:
    int maxAvailable_;
    int token_;
    mutex mx_;
    condition_variable cond_;
};

void foo(int id, Semaphore &s) {
    s.acquire();
    cout << id << " get" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    s.release();
}

int main() {
    Semaphore s(2);

    thread t1(foo, 1, ref(s));
    thread t2(foo, 2, ref(s));
    thread t3(foo, 3, ref(s));
    thread t4(foo, 4, ref(s));
    thread t5(foo, 5, ref(s));
    thread t6(foo, 6, ref(s));
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    return 0;
}
