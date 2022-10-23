#include <iostream>
#include <vector>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-224113-1-1.html

class Solution {
public:
    vector<int> missing(vector<int> &nums) {
        if (nums.empty())
            return {};

        int minVal = nums[0], maxVal = nums[0];;
        for (int &num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }

        vector<bool> buckets(maxVal - minVal + 1, false);
        for (int &num : nums) {
            buckets[num - minVal] = true;
        }

        vector<int> res;
        for (int i = minVal; i <= maxVal; ++i) {
            if (!buckets[i - minVal])
                res.push_back(i);
        }
        return res;
    }
};

int main() {
    Solution sol;

    //vector<int> nums = {-1, 0, 3};
    vector<int> nums = {1, 2, 3, 7, 9, 4, 8};
    for (int &m : sol.missing(nums))
        cout << m << " ";
    cout << endl;

    return 0;
}
