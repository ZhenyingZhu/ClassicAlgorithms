/*
 * [Source] https://leetcode.com/problems/flatten-2d-vector/
 * [Difficulty]: Medium
 * [Tag]: Design
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// [Solution]: Use two iterators to point to original vector positions. TODO use the end iterator as the end indicator
// [Corner Case]:
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d):
        oriVec(vec2d) {
        vecIt = oriVec.begin();
        if (vecIt != oriVec.end()) {
            numIt = vecIt->begin();
        } else {
            numIt = dummy.end();
        }

        getRightIt();
    }

    int next() {
        if (!hasNext())
            return INT_MAX;

        int next = *numIt;
        ++numIt;
        getRightIt();

        return next;
    }

    bool hasNext() {
        return numIt != dummy.end();
    }

private:
    void getRightIt() {
        while (numIt != dummy.end() && numIt == vecIt->end()) {
            ++vecIt;
            if (vecIt == oriVec.end()) {
                numIt = dummy.end();
            } else {
                numIt = vecIt->begin();
            }
        }
    }

    vector<vector<int>> &oriVec;
    vector<vector<int>>::iterator vecIt;
    vector<int>::iterator numIt;
    vector<int> dummy = {0}; // if set it to empty, it points to all empty vec
};

class Solution {
public:
    void test() {
        vector<vector<int>> vec2d = {
            {},
            {1, 2},
            {3},
            {},
            {4, 5, 6},
            {}
        };

        Vector2D vit(vec2d);
        while (vit.hasNext()) {
            cout << vit.next() << " ";
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
