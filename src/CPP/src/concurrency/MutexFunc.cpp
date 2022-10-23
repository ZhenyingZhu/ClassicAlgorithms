#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

mutex m;
vector<int> vec = {0};

void insert(int num) {
    lock_guard<mutex> guard(m);
    vec.push_back(num);
    this_thread::sleep_for(chrono::seconds(1));
}

void readBack() {
    cout << "back " << vec.back() << endl;
}

void readBackWithLock() {
    lock_guard<mutex> guard(m);
    cout << "back with lock " << vec.back() << endl;
}

int main() {
    thread t(insert, 1);
    t.detach();

    /* without lock, first print 0, then 1
    readBack();
    t.join();
    readBack();
    */

    // if not put in a thread, print 0 at once
    //readBackWithLock();

    // only print 1
    //thread r(readBackWithLock);
    //r.join();

    return 0;
}
