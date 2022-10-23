/*
 * [Source] https://leetcode.com/problems/create-maximum-number/
 * [Difficulty]: Hard
 * [Tag]: Dynamic Programming
 * [Tag]: Greedy
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size(), len2 = nums2.size();

        vector<int> res;
        // if len2 is smaller than k, need at least pick k-len2 numbers from nums1
        // if len1 is smaller than k, can at most pick len1 numbers
        for (int numFrom1 = max(0, k - len2); numFrom1 <= min(k, len1); ++numFrom1) {
            vector<int> maxSubarray1 = maxInorderNumFromArray(nums1, numFrom1);
            vector<int> maxSubarray2 = maxInorderNumFromArray(nums2, k - numFrom1);
            vector<int> tmp = merge(maxSubarray1, maxSubarray2);
            res = max(res, tmp);
        }
        return res;
    }

    vector<int> maxInorderNumFromArray(vector<int>& nums, int n) {
        int canDrop = (int)nums.size() - n;
        vector<int> res;

        int drop = 0;
        for (int& num : nums) {
            // since need to keep inorder, previous smaller number can greedily drop. Then the result keeps in desendent order.
            while (drop < canDrop && !res.empty() && res.back() < num) {
                res.pop_back();
                ++drop;
            }
            res.push_back(num);
        }

        res.resize(n); // there could be more than n nums
        return res;
    }

    // cannot use the algorithm that merge sorted lists. Since they are not sorted, use vector operator< to find the larger one to add to result
    vector<int> merge(vector<int>& array1, vector<int>& array2) {
for (int& num : array1)
    cout << num << " ";
cout << endl;
for (int& num : array2)
    cout << num << " ";
cout << endl;
        vector<int> res;
        while (array1.size() + array2.size() > 0) {
            if (array1 > array2) {
                res.push_back(array1[0]);
                array1.erase(array1.begin());
            } else {
                res.push_back(array2[0]);
                array2.erase(array2.begin());
            }
        }

        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<int> nums1 = {3, 4, 6, 5};
    //vector<int> nums2 = {9, 1, 2, 5, 8, 3};
    //vector<int> nums1 = {6, 7};
    //vector<int> nums2 = {6, 0, 4};
    //for (int& num : sol.maxNumber(nums1, nums2, 5))
    vector<int> nums1 = {1,6,5,4,7,3,9,5,3,7,8,4,1,1,4};
    vector<int> nums2 = {4,3,1,3,5,9};
    for (int& num : sol.maxNumber(nums1, nums2, 21))
        cout << num << " ";
    cout << endl;

    return 0;
}
