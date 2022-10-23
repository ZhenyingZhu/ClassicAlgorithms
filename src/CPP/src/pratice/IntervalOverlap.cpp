#include <iostream>

using namespace std;

struct Interval {
    int start, end;
    Interval(int s, int e): start(s), end(e) { }
};

// [Source]: http://www.1point3acres.com/bbs/thread-225639-1-1.html

class Solution {
public:
    bool isOverlap(Interval inter1, Interval inter2) {
        if (inter1.start > inter2.start) {
            swap(inter1, inter2);
        }

        return inter2.start <= inter1.end;
    }
};

int main() {
    Solution sol;

    cout << sol.isOverlap(Interval(0, 1), Interval(2, 3)) << endl;
    cout << sol.isOverlap(Interval(0, 2), Interval(2, 3)) << endl;
    cout << sol.isOverlap(Interval(0, 2), Interval(1, 3)) << endl;

    return 0;
};
