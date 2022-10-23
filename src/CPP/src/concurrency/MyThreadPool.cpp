#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <queue>

using namespace std;

// [Source]: EPI 20.4

mutex mtx;
condition_variable cond;

void threadFunc(int id, queue<int> &q) {
    for (int i = 0; i < 10; i++) {
        // set job to be default value
        int num = -1;
        {
            unique_lock<mutex> lck(mtx);

            if (q.empty()) {
                // unlock and wait for the queue to be not empty
                cout << "thread " << id << " idle" << endl;
                cond.wait_for(lck, chrono::seconds(3));
            } else {
                // pull the job from the queue
                num = q.front();
                q.pop();
            }
        }

        // work on the job. notice here should not lock the queue
        if (num != -1) {
            this_thread::sleep_for(chrono::seconds(1));
            { // this lock is just to not mess up with the output
                lock_guard<mutex> guard(mtx);
                cout << "thread " << id << " print " << num << endl;
            }
            num = -1;
        }
    }
}

int main() {
    queue<int> q;
    vector<thread> threadPool;
    for (int i = 0; i < 3; i++) {
        threadPool.push_back( thread(threadFunc, i, ref(q)) );
    }

    this_thread::sleep_for(chrono::seconds(1));
    size_t queueSize = 5;
    int num = 100;
    while (num <= 1000) {
        {
            lock_guard<mutex> guard(mtx);
            if (q.size() >= queueSize)
                continue;

            cout << "push " << num << endl;
            q.push(num);
            num += 100;
            cond.notify_all();
        }
    }

    for (thread &t : threadPool)
        t.join();

    return 0;
}
