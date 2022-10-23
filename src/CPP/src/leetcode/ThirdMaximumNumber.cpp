/*
 * [Source] https://leetcode.com/problems/third-maximum-number/
 * [Difficulty]: Easy
 * [Tag]: Array
 */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <climits>

using namespace std;

// [Solution]: Use a list to store three max value.
// [Corner Case]: If the number already appeared, not add to the list
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.empty())
            return INT_MAX;
        list<int> threeMax;
        for (int num : nums) {
for (list<int>::iterator it = threeMax.begin(); it != threeMax.end(); ++it)
    cout << *it << " ";
cout << endl;
            bool appeared = false;
            list<int>::iterator it = threeMax.begin();
            for (; it != threeMax.end(); ++it) {
                if (*it == num) {
                    appeared = true;
                    break;
                }
                if (*it < num) {
                    threeMax.insert(it, num);
                    break;
                }
            }
            if (!appeared && threeMax.size() < 3 && it == threeMax.end())
                threeMax.push_back(num);
            else if (threeMax.size() > 3)
                threeMax.pop_back();
        }

        if (threeMax.size() == 3)
            return threeMax.back();
        return threeMax.front();
    }
};

// [Solution]: sort
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {2, 2, 3, 1};
    cout << sol.thirdMax(nums) << endl;

    return 0;
}
