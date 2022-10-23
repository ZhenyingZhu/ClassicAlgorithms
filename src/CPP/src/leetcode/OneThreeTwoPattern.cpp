/*
 * [Source] https://leetcode.com/problems/132-pattern/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>

using namespace std;

// [Solution]: Do it in reverse order. Use a stack. The idea is that we need find a2>a3>a1, so each time when check a1, we need make sure there is already a pair of a2>a3. Since a3 should after a2, so do it in reverse order. Each number as a1 first compare to a3, if it is not larger than a3, it cannot use as a1, so compare it to a2. If it is smaller than current a2, it can be a2, and in the future can be a3. If the number is larger than current a2, then current a2 can be a3, and this number replace a2. Notice we want a largest a3, so use a stack to store a2(a3 candidate)
// [Corner Case]:
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2)
            return false;

        // s2 > s3 > s1
        stack<int> a2; // s3 candidates come from here
        int a3 = INT_MIN;
        for (int i = len - 1; i >= 0; --i) {
            int &num = nums[i];
            if (num < a3)
                return true;

            while (!a2.empty() && a2.top() < num) {
                a3 = a2.top();
                a2.pop();
            }
            a2.push(num);
        }
        return false;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    return 0;
}
