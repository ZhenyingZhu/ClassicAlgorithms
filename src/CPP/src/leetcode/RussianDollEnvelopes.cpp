/*
 * [Source] https://leetcode.com/problems/russian-doll-envelopes/
 * [Difficulty]: Hard
 * [Tag]: Binary Search
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

// [Solution]: Sort the array by first, then use 2D DP.
// [Corner Case]:
class Solution2D {
public:
    static bool smaller(const pair<int, int> &p1, const pair<int, int> &p2) {
        if (p1.first < p2.first) {
            return true;
        } else if (p1.first > p2.first) {
            return false;
        } else if (p1.second < p2.second) {
            return true;
        }
        // same emvelope return false
        return false;
    }

    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty())
            return 0;

        sort(envelopes.begin(), envelopes.end(), smaller);

        vector<int> nums(envelopes.size(), 1);
        int res = 1;
        for (int cur = 1; cur < (int)envelopes.size(); ++cur) {
            pair<int, int> &curEnv = envelopes[cur];
            int maxNum = 1;
            for (int pre = cur - 1; pre >= 0; --pre) {
                pair<int, int> &preEnv = envelopes[pre];
                if (curEnv.first > preEnv.first && curEnv.second > preEnv.second)
                    maxNum = max(nums[pre] + 1, maxNum);
            }
            nums[cur] = maxNum;
            res = max(maxNum, res);
        }

        return res;
    }
};

// [Solution]: LIS
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), smaller);
        
        vector<int> heightLIS;
        for (pair<int, int> &envelope : envelopes) {
            int lastSmaller = binarySearch(heightLIS, envelope.second);

            if (lastSmaller + 1 == (int)heightLIS.size()) {
                heightLIS.push_back(envelope.second);
            } else {
                heightLIS[lastSmaller + 1] = envelope.second;
            }
        }

        return heightLIS.size();
    }

private:
    static bool smaller(const pair<int, int> &p1, const pair<int, int> &p2) {
        if (p1.first < p2.first)
            return true;
        if (p1.first == p2.first && p1.second > p2.second)
            return true;
        return false;
    }

    int binarySearch(vector<int> &nums, int target) {
        if (nums.empty())
            return -1;

        int left = 0, right = nums.size() - 1;
        // the last smaller than target
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
                right = mid;
            else
                left = mid;
        }
        if (nums[right] < target)
            return right;
        if (nums[left] < target)
            return left;
        return -1;
    }
};

int main() {
    Solution sol;

    vector<pair<int, int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};

    cout << sol.maxEnvelopes(envelopes) << endl;

    return 0;
}
