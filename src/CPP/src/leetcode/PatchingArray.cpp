/*
 * [Source] https://leetcode.com/problems/patching-array/
 * [Difficulty]: Hard
 * [Tag]: Greedy
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Brute force
// [Corner Case]:
class SolutionTimeout {
public:
    int minPatches(vector<int>& nums, int n) {
        vector<bool> canSumTo((long)n + 1, false);
        updateSums(nums, 0, 0, canSumTo);
for (int i = 0; i <= n; ++i)
    if (canSumTo[i]) cout << i << " ";
cout << endl;

        vector<int> patchs;
        for (long num = 1; num <= n; ++num) {
            if (canSumTo[num]) {
                cout << num << " ";
                continue;
            }

            patchs.push_back(num);
            updateSums(num, canSumTo);
        }

cout << endl;
for (int& p : patchs)
    cout << p << " ";
cout << endl;
        return patchs.size();
    }

    void updateSums(vector<int> &nums, long idx, long pre, vector<bool> &canSumTo) {
        if (idx == (long)nums.size())
            return;

        canSumTo[pre] = true;
        updateSums(nums, idx + 1, pre, canSumTo);

        long add = pre + nums[idx];
        if (add >= (long)canSumTo.size())
            return;
        canSumTo[add] = true;
        updateSums(nums, idx + 1, add, canSumTo);
    }

    void updateSums(long patch, vector<bool> &canSumTo) {
        // need to it inreverse order, so that current result won't affect furture result
        // need include 0, so that patch itself mark as can be computed
        for (long i = (long)canSumTo.size() - patch - 1; i >= 0; --i) {
            if (canSumTo[i])
                canSumTo[i + patch] = true;
        }
    }
};

// [Solution]: Key point is that if 1 to n can be compute, add n+1 to the array, then n+2 to 2n+1 can also compute
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1; // first cannot sum to num
        vector<long> patches;

        int i = 0;
        // if 1 to miss-1 can be compute, then add nums[i], nums[i]+1 to nums[i]+miss-1 can also be computed
        while (miss <= n) {
            if (i < (int)nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                patches.push_back(miss);
                miss += miss;
            }
        }
        return patches.size();
    }
};

int main() {
    Solution sol;
    //SolutionTimeout sol;

    //vector<int> nums = {1, 3}; int n = 6;
    //vector<int> nums = {1, 5, 10}; int n = 20;
    //vector<int> nums = {1, 2, 4, 11}; int n = 30;
    //vector<int> nums = {1,2,31,33}; int n = 2147483647;
    vector<int> nums; int n = 8;
    cout << sol.minPatches(nums, n) << endl;

    return 0;
}
