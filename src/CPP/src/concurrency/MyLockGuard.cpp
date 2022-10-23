#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

class LockGuard {
public:
    LockGuard(mutex &m): mx(m) {
        for (int i = 0; i < 10; i++) {
            if (!mx.try_lock()) {
                cout << "failed to get lock" << endl;
                this_thread::sleep_for(chrono::seconds(1));
            } else {
                break;
            }
        }
    }

    ~LockGuard() {
        mx.unlock();
    }

private:
    mutex &mx;
};

class LockGuardUseUniqueLock {
public:
    LockGuardUseUniqueLock(mutex &mx): lck(mx, defer_lock) {
        lck.lock(); // this is busy wait lock
    }

    ~LockGuardUseUniqueLock() {
        lck.unlock();
    }

private:
    unique_lock<mutex> lck;
};

class MyClass {
public:
    MyClass() {
    }

    void foo() {
        LockGuard guard1(mx1);
        this_thread::sleep_for(chrono::seconds(1));
        LockGuard guard2(mx2);
        cout << "MyClass foo" << endl;
    }

    void bar_deadlock() {
        LockGuard guard1(mx2); //this create a deadlock
        this_thread::sleep_for(chrono::seconds(1));
        LockGuard guard2(mx1);
        cout << "MyClass bar" << endl;
    }

    void bar() {
        LockGuard guard1(mx1);
        this_thread::sleep_for(chrono::seconds(1));
        LockGuard guard2(mx2);
        cout << "MyClass bar" << endl;
    }

private:
    mutex mx1;
    mutex mx2;
};

int main() {
    MyClass mc;

    thread t1(&MyClass::foo, &mc);
    //thread t2(&MyClass::bar, &mc);
    thread t2(&MyClass::bar_deadlock, &mc);
    t1.join();
    t2.join();

    return 0;
}
