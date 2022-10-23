/*
 * [Source] https://leetcode.com/problems/nested-list-weight-sum/
 * [Difficulty]: Easy
 * [Tag]: Depth-first Search
 */

#include <iostream>

using namespace std;

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

// [Solution]:
// [Corner Case]:
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int sum = 0;
        for (NestedInteger &ni : nestedList) {
            if (ni.isInteger()) {
                sum += ni.getInteger();
            } else {
                sum += depthSum(ni.getList(), 2);
            }
        }
        return sum;
    }

    int depthSum(vector<NestedInteger>& nestedList, int depth) {
        int sum = 0;
        for (NestedInteger &ni : nestedList) {
            if (ni.isInteger()) {
                sum += depth * ni.getInteger();
            } else {
                sum += depthSum(ni.getList(), depth + 1);
            }
        }
        return sum;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    return 0;
}
