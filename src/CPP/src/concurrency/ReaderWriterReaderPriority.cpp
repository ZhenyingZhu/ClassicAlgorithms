#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

// [Source]: EPI Chapter 20.6
class Cache {
public:
    Cache() {
        num = 0;
        readCnt = 0;
    }

    int num;
    int readCnt;
    mutex readMutex;
    mutex writeMutex;
    condition_variable cond;
};

// Reader perferance higher than writer
void reader(Cache &c) {
    {
        lock_guard<mutex> lock(c.readMutex);
        ++c.readCnt;
    }
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Read " << c.num << endl;
    {
        lock_guard<mutex> lock(c.readMutex);
        --c.readCnt;
        c.cond.notify_one();
    }
}

void writer(Cache &c, int num) {
    {
        lock_guard<mutex> lockWrite(c.writeMutex);
        {
            unique_lock<mutex> lock(c.readMutex);
            while (c.readCnt > 0)
                c.cond.wait(lock);
            this_thread::sleep_for(chrono::seconds(2));
            c.num = num;
            cout << "Write " << c.num << endl;
        }
    }
}

int main() {
    Cache c;
    thread r1(reader, ref(c));
    thread r2(reader, ref(c));
    thread r3(reader, ref(c));
    thread w1(writer, ref(c), 3);
    thread w2(writer, ref(c), 4);
    this_thread::sleep_for(chrono::seconds(5));
    thread r4(reader, ref(c));

    r1.join(); r2.join(); r3.join(); w1.join(); w2.join(); r4.join();

    return 0;
}
