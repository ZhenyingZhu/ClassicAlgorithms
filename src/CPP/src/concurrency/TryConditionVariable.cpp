#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <condition_variable>
#include <vector>

using namespace std;

condition_variable cond;
mutex mtx;
bool ready = false;

void job(int id) {
    unique_lock<mutex> lck(mtx);
    cout << "job " << id << " pending" << endl;
    do {
        cout << "wait_for " << id << endl;
        cond.wait_until(lck, chrono::seconds(10));
    } while (!ready);
    cout << "job " << id << " started" << endl;
}

void go() {
    ready = true;
    cond.notify_one();
}

int main() {
    vector<thread> threadPool;
    for (int i = 0; i < 4; i++)
        threadPool.push_back(thread(job, i));

    this_thread::sleep_for(chrono::seconds(1));
    {
        lock_guard<mutex> guard(mtx);
        cout << "4 jobs are blocked" << endl;
    }
    this_thread::sleep_for(chrono::seconds(1));
    go();

    for (thread &t : threadPool)
        t.join();

    return 0;
}
