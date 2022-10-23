/*
 * [Source] https://leetcode.com/problems/maximum-gap/
 * [Difficulty]: Hard
 * [Tag]: Sort
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// [Solution]: Bucket sort. Since average difference is (max-min)/(len-1), so make each bucket has this volumn (which means min and max values in a bucket is at most this difference), which needs len buckets.
// [Corner Case]: difference cannot be int since it could be 0 when len is large.
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if (len < 2)
            return 0;

        int minNum = INT_MAX, maxNum = INT_MIN;
        for (const int& num : nums) {
            minNum = min(num, minNum);
            maxNum = max(num, maxNum);
        }

        double diff = double(maxNum - minNum) / double(len - 1);
        vector<Bucket> buckets(len, Bucket());
        for (int i = 0; i < len; ++i) {
            int idx = double(nums[i] - minNum) / diff;
            buckets[idx].push(nums[i]);
        }

        int maxGap = 0;
        int prevBucket = -1;
        for (int i = 0; i < len; ++i) {
            Bucket& cur = buckets[i];
            if (cur.empty)
                continue;
            if (prevBucket != -1)
                maxGap = max(cur.min - buckets[prevBucket].max, maxGap);

            prevBucket = i;
        }

        return maxGap;
    }

private:
    struct Bucket {
        Bucket(): empty(true), min(0), max(0) {}

        void push(int val) {
            if (empty) {
                min = val;
                max = val;
                empty = false;
            } else {
                if (min > val) {
                    min = val;
                } else if (max < val) {
                    max = val;
                }
            }
        }

        bool empty;
        int min, max;
    };
};

// [Solution]: Don't understand the answer http://blog.csdn.net/u012162613/article/details/41936569 . Doesn't look right

int main() {
    Solution sol;

    //vector<int> nums = {1, 3, 6, 4, 5, 3};
    vector<int> nums = {1,1,1,1,1,5,5,5,5,5};
    cout << sol.maximumGap(nums) << endl;

    return 0;
}
