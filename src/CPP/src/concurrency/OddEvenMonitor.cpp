#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

// [Source]: EPI Chapter 20.3
class OddEvenMonitor {
public:
    static const bool ODD_TURN = true;
    static const bool EVEN_TURN = false;

    OddEvenMonitor():
        turn_(ODD_TURN) { }

    void waitTurn(bool curTurn) {
        unique_lock<mutex> lock(mx_);
        while (turn_ != curTurn) {
            cond_.wait(lock);
        }
    }

    void toggleTurn() {
        unique_lock<mutex> lock(mx_);
        turn_ = !turn_;
        cond_.notify_one();
    }

private:
    bool turn_;
    mutex mx_;
    condition_variable cond_;
};

void printNum(bool odd, OddEvenMonitor &monitor) {
    int num = odd ? 1 : 2;
    for (; num <= 10; num += 2) {
        monitor.waitTurn(odd);
        cout << num << endl;
        monitor.toggleTurn();
    }
}

int main() {
    OddEvenMonitor monitor;
    thread t1(printNum, true, ref(monitor));
    thread t2(printNum, false, ref(monitor));
    t1.join();
    t2.join();

    return 0;
}
