/*
 * [Source] https://leetcode.com/problems/product-of-array-except-self/
 * [Difficulty]: Medium
 * [Tag]: Array
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Create Difference Array. Produce forward product and backward product.
// [Corner Case]:
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);

        // forward
        for (size_t i = 1; i < nums.size(); ++i) {
            res[i] = nums[i - 1] * res[i - 1];
        }
        // backward
        int backwardProduct = 1;
        for (int j = (int)nums.size() - 2; j >= 0; --j) {
            backwardProduct *= nums[j + 1];
            res[j] *= backwardProduct;
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1,2,3,4};
    vector<int> res = sol.productExceptSelf(nums);
    for (int& num : res)
        cout << num << " ";
    cout << endl;

    return 0;
}
