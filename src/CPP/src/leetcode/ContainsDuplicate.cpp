/*
 * [Source] https://leetcode.com/problems/contains-duplicate/
 * [Difficulty]: Easy
 * [Tag]: Array
 * [Tag]: Hash Table
 */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (int& num : nums) {
            if (set.find(num) != set.end())
                return true;
            set.insert(num);
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
