/*
 * [Source] https://leetcode.com/problems/wiggle-sort-ii/
 * [Difficulty]: Medium
 * [Tag]: Srot
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// [Solution]: First sort the array. Then cut array in the middle. To ensure the order, the last element of first half must smaller than last element of the second half
// [Corner Case]: [4 5 5 6]
class SolutionSortExtraSpace {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp(nums.begin(), nums.end());
        sort(tmp.begin(), tmp.end());
        
        int firstEd = ((int)nums.size() - 1) / 2, secondEd = (int)nums.size() - 1;
        bool first= true;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (first) {
                nums[i] = tmp[firstEd--];
                first = false;
            } else {
                nums[i] = tmp[secondEd--];
                first = true;
            }
        }
    }
};

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto midIt = nums.begin() + n / 2;
        nth_element(nums.begin(), midIt, nums.end());
        int mid = *midIt;

        // Template for three way partition
        int smaller = 0, larger = n - 1;
        int runner = 0;
        while (runner <= larger) {
cout << getIdx(runner, n) << ": " << nums[getIdx(runner, n)] << endl;
            if (nums[getIdx(runner, n)] < mid) {
cout << getIdx(runner, n) << " " << getIdx(smaller, n) << endl;
                swap( nums[getIdx(runner, n)], nums[getIdx(smaller, n)] );
                runner++;
                smaller++;
            } else if (nums[getIdx(runner, n)] > mid) {
cout << getIdx(runner, n) << " " << getIdx(larger, n) << endl;
                swap( nums[getIdx(runner, n)], nums[getIdx(larger, n)] );
                larger--;
            } else {
                runner++;
            }
        }
    }

    // reverse index
    // partition arr idx  0 1 2 3 4 5 6
    // needs to place to  3 6 2 5 1 4 0
    // so the order idx   6 4 2 0 5 3 1
    // think like this: when first access index 0, it is the real number at idx 6; index 1 is at 4.
    int getIdx(int idx, int n) {
        if (idx <= (n - 1) / 2) {
            return ((n - 1) / 2 - idx) * 2;
        } else {
            return (n - idx - 1) * 2 + 1;
        }
    }
};

int main() {
    Solution sol;

    for (int i = 0; i < 6; ++i)
        cout << sol.getIdx(i, 6) << " ";
    cout << endl;

    vector<int> nums = {1, 5, 1, 1, 6, 4};
    //vector<int> nums = {1, 3, 2, 2, 3, 1, 1};
    //vector<int> nums = {5, 5, 4, 6};
    sol.wiggleSort(nums);
    for (int& num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}
