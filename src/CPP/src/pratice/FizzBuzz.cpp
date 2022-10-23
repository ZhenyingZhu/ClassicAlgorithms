#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/fizz-buzz/
// http://www.1point3acres.com/bbs/thread-226373-1-1.html

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        vector<int> nums = {3, 5};
        for (int i = 1; i <= n; ++i) {
            res.push_back(helper(nums, 2, i));
        }
        return res;
    }

    string helper(vector<int> &nums, int top, int target) {
        if (top <= 0)
            return "";

        // TODO: this logic is too tricky. Use a vector to store modable numbers

        // nums is in inc order
        bool all = true;
        int largestIdx = -1;
        for (int i = 0; i < top; ++i) {
            if (target % nums[i] > 0)
                all = false;
            else
                largestIdx = i;
        }
        if (all && largestIdx == (int)nums.size() - 1) {
            return getAll();
        } else if (largestIdx == -1) {
            if (top == (int)nums.size())
                return get(target);
            else
                return "";
        } else {
            return get(nums[largestIdx]) + helper(nums, largestIdx, target);
        }
    }

    string getAll() {
        return "FizzBuzz";
    }

    string get(int num) {
        if (num == 5)
            return "Buzz";
        else if (num == 3)
            return "Fizz";
        //else if (num == 2)
        //    return "Axzz";
        return to_string(num);
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3,5};
    for (int i = 1; i <= 30; ++i)
        cout << sol.helper(nums, 2, i) << endl;

    return 0;
}
