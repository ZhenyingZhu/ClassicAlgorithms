/*
 * [Source] https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
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
    unordered_map<int, vector<int>> numIdxMap;
    vector<int> nums;

    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool notContains = true;
        if (numIdxMap.find(val) != numIdxMap.end())
            notContains = false;

        nums.push_back(val);
        numIdxMap[val].push_back(nums.size() - 1);
        return notContains;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (numIdxMap.find(val) == numIdxMap.end())
            return false;

        int idx = numIdxMap[val].back();
        if (idx != (int)nums.size() - 1) {
            int back = nums.back();
            nums[idx] = back;

            vector<int> &backIdxes = numIdxMap[back];
            for (int i = (int)backIdxes.size() - 1; i >= 0; --i) { // cannot use a heap here, because the insert op will be O(logn). But on average it is still O(n)
                if (backIdxes[i] == (int)nums.size() - 1) {
                    backIdxes[i] = idx;
                    break;
                }
            }
        }

        nums.pop_back();
        numIdxMap[val].pop_back();
        if (numIdxMap[val].empty())
            numIdxMap.erase(val);

        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        if (nums.empty())
            return INT_MAX;

cout << "(";
for (int &num : nums)
    cout << num << " ";
cout << ")" << endl;

        int idx = rand() % nums.size();
        return nums[idx];
    }
};

class Solution {
public:
    void test() {
        RandomizedSet randomSet;
        cout << randomSet.insert(1) << endl;
        cout << randomSet.insert(1) << endl;
        cout << randomSet.remove(2) << endl;
        cout << randomSet.insert(2) << endl;
        cout << "1 1 2" << endl;
        cout << randomSet.getRandom() << endl;
        cout << randomSet.getRandom() << endl;
        cout << randomSet.getRandom() << endl;
        cout << randomSet.getRandom() << endl;
        cout << randomSet.getRandom() << endl;
        cout << randomSet.getRandom() << endl;
        cout << "===" << endl;
        cout << randomSet.remove(1) << endl;
        cout << randomSet.insert(2) << endl;
        cout << "1 2 2" << endl;
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
