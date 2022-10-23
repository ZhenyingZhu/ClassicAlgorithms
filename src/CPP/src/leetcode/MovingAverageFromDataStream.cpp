/*
 * [Source] https://leetcode.com/problems/moving-average-from-data-stream/
 * [Difficulty]: Easy
 * [Tag]: Design
 * [Tag]: Queue
 */

#include <iostream>
#include <queue>

using namespace std;

// [Solution]:
// [Corner Case]:
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }

    double next(int val) {
        sum += val;
        q.push(val);
        if ((int)q.size() > size) {
            sum -= q.front();
            q.pop();
        }

        return (double)sum / (double)q.size();
    }

    queue<int> q;
    int size;
    int sum;
};

class Solution {
public:
    void test() {
        MovingAverage ma(3);
        cout << ma.next(1) << endl;
        cout << ma.next(10) << endl;
        cout << ma.next(3) << endl;
        cout << ma.next(5) << endl;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    sol.test();

    return 0;
}
