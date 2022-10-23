#include <iostream>
#include <deque>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/sliding-window-maximum/#/description
// http://www.1point3acres.com/bbs/thread-206603-1-1.html

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty())
            return {};
        int size = nums.size();

        deque<int> decIndexes;
        for (int i = 0; i < size && i < k; i++) {
            while (!decIndexes.empty() && nums[i] > nums[decIndexes.back()])
                decIndexes.pop_back();
            decIndexes.push_back(i);
        }

        vector<int> res = {nums[decIndexes.front()]};
        for (int i = 0; i < size - k; i++) {
            if (decIndexes.front() == i)
                decIndexes.pop_front();
            while (!decIndexes.empty() && nums[i + k] > nums[decIndexes.back()])
                decIndexes.pop_back();
            decIndexes.push_back(i + k);

            res.push_back(nums[decIndexes.front()]);
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1,3,-1,-3,5,3,6,7}; int k = 3;
    for (int &num : sol.maxSlidingWindow(nums, k))
        cout << num << ", ";
    cout << endl;

    return 0;
}
