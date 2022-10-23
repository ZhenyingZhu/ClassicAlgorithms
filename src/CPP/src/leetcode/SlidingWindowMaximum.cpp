/*
 * [Source] https://leetcode.com/problems/sliding-window-maximum/
 * [Difficulty]: Hard
 * [Tag]: Heap
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// [Solution]: 1. start from kth element, find increasing elements backward, and push to a dequeue. Also record index. 2. If the left side of window hit the first element in the queue, dequeue. 3. When push the next element into the queue, erase all elements that are smaller than it. T(n) = O(kn).
class Solution {
public:
    struct NumIdx {
        int num;
        int idx;
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 0 || nums.size() == 0)
            return {};

        deque<NumIdx> queue;
        for (int i = k - 1; i >= 0; --i) {
            if (queue.empty() || nums[i] > queue.front().num) {
                queue.push_front({nums[i], i});
            }
        }

        vector<int> res;
        for (int st = 0; st <= (int)nums.size() - k; ++st) {
            res.push_back(queue.front().num);

            if (st == queue.front().idx)
                queue.pop_front();

            int ed = st + k;
            int num = nums[ed];
            auto it = queue.begin();
            for (; it != queue.end(); ++it) {
                if (it->num < num)
                    break;
            }
            queue.erase(it, queue.end());
            queue.push_back({num, ed});
        }

        return res;
    }
};

// [Solution]: Use priority queue. So that when the first largest element is moved out, pop it and get the second large element. T(n)=O(nlogk).

int main() {
    Solution sol;

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> res = sol.maxSlidingWindow(nums, 3);
    for (int& num : res)
        cout << num << " ";
    cout << endl;

    return 0;
}
