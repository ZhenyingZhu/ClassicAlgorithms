/*
 * [Source] https://leetcode.com/problems/shuffle-an-array/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Create random index
// [Corner Case]:
class SolutionRandomIdx {
public:
    vector<int> origVec;

    SolutionRandomIdx(vector<int> nums):
        origVec(nums.begin(), nums.end())
    {
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origVec;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res;

        int len = origVec.size();
        vector<bool> used(len, false);
        for (; len > 0; --len) {
            int idx = rand() % len;
cout << idx << "+";
            res.push_back(getNotUsed(idx, used));
        }
cout << endl;

        return res;
    }

    int getNotUsed(int idx, vector<bool> &used) {
        int i = 0;
        for (; i < (int)used.size(); ++i) {
            if (!used[i]) {
                if (idx == 0)
                    break;
                --idx;
            }
        }

        used[i] = true;
        return origVec[i];
    }
};

// [Solution]: random pick a number from (i, n). Prove: for first element 1, it has 1/n change to stay on the first cell. For second element 2, it has 1/n change to be swapped with 1 already, so it has (n-1)/n change to stay on the second cell, then it has 1/(n-1) change to stay after pick a random number and it is still not changed. So it has 1/n chance to stay on second cell.
class Solution {
public:
    Solution(vector<int> nums):
        origin_(nums.begin(), nums.end()),
        shuffled_(nums.begin(), nums.end())
    { }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        if (origin_.empty())
            return {};

        for (size_t i = 0; i < origin_.size(); ++i)
            shuffled_[i] = origin_[i];
        return shuffled_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int len = shuffled_.size();
        for (int i = 0; i < len; ++i) { // no need to swap the last element
            int idx = rand() % (len - i) + i;
            if (i != idx)
                swap(shuffled_[i], shuffled_[idx]);
        }
        return shuffled_;
    }

private:
    vector<int> origin_;
    vector<int> shuffled_;
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution sol(nums);

    for (int i = 0; i < 12; ++i) {
        for (int &num : sol.shuffle())
            cout << num << " ";
        cout << endl;
    }

    return 0;
}
