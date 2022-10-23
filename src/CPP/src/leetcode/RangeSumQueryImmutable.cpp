/*
 * [Source] https://leetcode.com/problems/range-sum-query-immutable/
 * [Difficulty]: Easy
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Difference between sums
// [Corner Case]:
class NumArray {
public:
    NumArray(vector<int> &nums) {
        int sum = 0;
        for (int& num : nums) {
            sum += num;
            sums_.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        if (i == 0)
            return sums_[j];
        return sums_[j] - sums_[i - 1];
    }

private:
    vector<int> sums_;
};

class Solution {
public:
    void test() {
        vector<int> nums = {1, 2, 3};
        NumArray numArray(nums);
        cout << numArray.sumRange(0, 1) << endl;
        cout << numArray.sumRange(1, 2) << endl;
    }
};

int main() {
    Solution sol;

    sol.test();

    return 0;
}
