#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-225075-1-1.html

class Solution {
public:
    vector<pair<int, int>> countNums(vector<int> &nums) {
        vector<pair<int, int>> res;
        int st = 0;
        while (st < (int)nums.size()) {
            int ed = findLastOf(nums, st, nums[st]);
            res.push_back( {nums[st], ed - st + 1} );
            st = ed + 1;
        }
        return res;
    }

private:
    int findLastOf(const vector<int> &nums, int st, int target) {
        int left = st;
        int diff = 1;
        while (left + diff < (int)nums.size()) {
            if (nums[left + diff] <= target) {
                left += diff;
                diff *= 2;
            } else {
                break;
            }
        }

        int right = min((int)nums.size() - 1, left + diff);
        return binarySearch(nums, left, right, target);
    }

    int binarySearch(const vector<int> &nums, int left, int right, int target) {
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (nums[right] == target)
            return right;
        return left;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3};
    for (pair<int, int> &p : sol.countNums(nums))
        cout << p.first << ":" << p.second << endl;

    return 0;
}
