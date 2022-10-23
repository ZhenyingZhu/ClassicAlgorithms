/*
 * [Source] https://leetcode.com/problems/insert-delete-getrandom-o1/
 * [Difficulty]: Hard
 * [Tag]: Array
 * [Tag]: Hash Table
 * [Tag]: Design
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

// [Solution]: It is hard? Really?
// [Corner Case]:
class RandomizedSet {
public:
    unordered_map<int, int> numIdxMap;
    vector<int> nums;

    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (numIdxMap.find(val) != numIdxMap.end())
            return false;

        nums.push_back(val);
        numIdxMap[val] = nums.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (numIdxMap.find(val) == numIdxMap.end())
            return false;

        int idx = numIdxMap[val];
        if (idx != (int)nums.size() - 1) {
            int back = nums.back();
            nums[idx] = back;
            numIdxMap[back] = idx;
        }

        nums.pop_back();
        numIdxMap.erase(val);

        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        if (nums.empty())
            return INT_MAX;

        int idx = rand() % nums.size();
        return nums[idx];
    }
};

class Solution {
public:
    void test() {
        RandomizedSet randomSet;
        cout << randomSet.insert(1) << endl;
        cout << randomSet.remove(2) << endl;
        cout << randomSet.insert(2) << endl;
        cout << randomSet.getRandom() << endl;
        cout << randomSet.getRandom() << endl;
        cout << randomSet.getRandom() << endl;
        cout << randomSet.remove(1) << endl;
        cout << randomSet.insert(2) << endl;
        cout << randomSet.getRandom() << endl;
        cout << randomSet.getRandom() << endl;
        cout << randomSet.getRandom() << endl;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    sol.test();

    return 0;
}
