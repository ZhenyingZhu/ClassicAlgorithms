/*
 * [Source] https://leetcode.com/problems/zigzag-iterator/
 * [Difficulty]: Medium
 * [Tag]: Design
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// [Solution]: A list of iterators and a list of ends
// [Corner Case]:
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        iters.push_back(v1.begin());
        iters.push_back(v2.begin());
        ends.push_back(v1.end());
        ends.push_back(v2.end());
        vecIdx = 0;
        findNextIdx();
    }

    int next() {
        if (!hasNext())
            return INT_MAX;

        int num = *(iters[vecIdx]);
        ++iters[vecIdx];
        vecIdx = (vecIdx + 1) % (int)ends.size();
        findNextIdx();
        return num;
    }

    bool hasNext() {
        return vecIdx != (int)ends.size();
    }

private:
    void findNextIdx () {
        int oriIdx = vecIdx;
        while (iters[vecIdx] == ends[vecIdx]) {
            vecIdx = (vecIdx + 1) % (int)ends.size();

            // all vecs are ended
            if (vecIdx == oriIdx) {
                vecIdx = ends.size();
                break;
            }
        }
    }

    vector<vector<int>::iterator> iters;
    vector<vector<int>::iterator> ends;
    int vecIdx;
};

class Solution {
public:
    void test() {
        vector<int> v1 = {1, 2}, v2 = {3, 4, 5, 6};
        ZigzagIterator zi(v1, v2);
        while (zi.hasNext()) {
            cout << zi.next() << " ";
        }
        cout << endl;
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
