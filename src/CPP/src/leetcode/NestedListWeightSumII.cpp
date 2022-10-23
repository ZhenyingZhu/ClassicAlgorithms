/*
 * [Source] https://leetcode.com/problems/nested-list-weight-sum-ii/
 * [Difficulty]: Medium
 * [Tag]: Depth-first Search
 */

#include <iostream>

using namespace std;

class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

// [Solution]: Can use a vector to replace hash map
// [Corner Case]:
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        unordered_map<int, int> levelSumMap;
        int maxLevel = 0;
        helper(nestedList, 1, levelSumMap, maxLevel);

        int sum = 0;
        for (int i = 1; i <= maxLevel; ++i) {
            sum += (maxLevel - i + 1) * levelSumMap[i];
        }
        return sum;
    }

    void helper(vector<NestedInteger>& nestedList, int depth, unordered_map<int, int> &levelSumMap, int &maxLevel) {
        maxLevel = max(depth, maxLevel);
        for (NestedInteger &ni : nestedList) {
            if (ni.isInteger()) {
                levelSumMap[depth] += ni.getInteger();
            } else {
                helper(ni.getList(), depth + 1, levelSumMap, maxLevel);
            }
        }
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    return 0;
}
