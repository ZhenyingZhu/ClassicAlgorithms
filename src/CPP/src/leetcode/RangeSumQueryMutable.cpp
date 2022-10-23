/*
 * [Source] https://leetcode.com/problems/range-sum-query-mutable/
 * [Difficulty]: Medium
 * [Tag]: Segment Tree
 * [Tag]: Binary Indexed Tree
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Use Binary Indexed Tree. The last 1 bit of the index indicate how many numbers are the sum of current cell
// [Corner Case]:
class NumArray {
public:
    NumArray(vector<int> &nums) {
        binaryIndexTree.resize(nums.size() + 1);
        for (int i = 0; i < (int)nums.size(); ++i) {
            update(i, nums[i]);
        }
    }

    void update(int i, int val) {
        int originVal = sumRange(i, i);
        int diff = val - originVal;

        for (int idx = i + 1; idx < (int)binaryIndexTree.size(); idx += idx & - idx) {
            binaryIndexTree[idx] += diff;
        }
    }

    int sumRange(int i, int j) {
        int upper = getSum(j);
        int lower = getSum(i - 1);
        return upper - lower;
    }

private:
    int getSum(int pos) {
        int sum = 0;
        for (int idx = pos + 1; idx > 0; idx -= idx & -idx) {
            sum += binaryIndexTree[idx];
        }
        return sum;
    }

    vector<int> binaryIndexTree;
};

class Solution {
public:
    void test() {
        vector<int> nums = {1, 3, 5};
        NumArray numArray(nums);
        cout << numArray.sumRange(0, 2) << endl;
        numArray.update(1, 2);
        cout << numArray.sumRange(0, 2) << endl;
        cout << numArray.sumRange(1, 2) << endl;
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
