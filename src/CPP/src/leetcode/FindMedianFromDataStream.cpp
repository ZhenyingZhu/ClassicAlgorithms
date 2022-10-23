/*
 * [Source] https://leetcode.com/problems/find-median-from-data-stream/
 * [Difficulty]: Hard
 * [Tag]: Heap
 * [Tag]: Design
 */

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

// [Solution]: Use two priority queues. FIrst queue keeps the largerest element at top, and the second one keep the smallest. Make sure the first one already same or 1 larger length than the second one.
// [Corner Case]:
class MedianFinder {
public:
    priority_queue<int> smallerQueue;
    priority_queue<int, vector<int>, greater<int>> largerQueue;

    // Adds a number into the data structure.
    void addNum(int num) {
        if (!largerQueue.empty() && largerQueue.top() < num) {
            largerQueue.push(num);
        } else {
            smallerQueue.push(num);
        }
cout << smallerQueue.size() << " " << largerQueue.size() << endl;
        if (largerQueue.size() > smallerQueue.size()) {
            int tmp = largerQueue.top();
            largerQueue.pop();
            smallerQueue.push(tmp);
        } else if (largerQueue.size() + 1 < smallerQueue.size()) {
            int tmp = smallerQueue.top();
            smallerQueue.pop();
            largerQueue.push(tmp);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (smallerQueue.size() > largerQueue.size())
            return (double)smallerQueue.top();
        if (!smallerQueue.empty())
            return (double)(smallerQueue.top() + largerQueue.top()) / 2;
        return 100.0;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    MedianFinder mf;
    mf.addNum(0); mf.addNum(1); mf.addNum(1);
    cout << mf.findMedian() << endl;

    return 0;
}
