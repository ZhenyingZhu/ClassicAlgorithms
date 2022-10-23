/*
 * [Source] https://leetcode.com/problems/two-sum-iii-data-structure-design/
 * [Difficulty]: Easy
 * [Tag]: Hash Table
 * [Tag]: Design
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// [Solution]: Use vector and sort. O(nlogn) time. Timeout on OJ.
// [Corner Case]:
class TwoSumTimeout {
public:
    // Add the number to an internal data structure.
    void add(int number) {
        nums.push_back(number);
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        sort(nums.begin(), nums.end());

        int st = 0, ed = nums.size() - 1;
        while (st < ed) {
            int sum = nums[st] + nums[ed];
            if (sum == value)
                return true;
            if (sum < value) {
                ++st;
            } else {
                --ed;
            }
        }
        return false;
    }

private:
    vector<int> nums;
};

// [Solution]: Use hash table. O(n) time.
// [Corner Case]:
class TwoSum {
public:
    // Add the number to an internal data structure.
    void add(int number) {
        ++numCnt[number];
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        for (auto it = numCnt.begin(); it != numCnt.end(); ++it) {
            int num = it->first;
            if (value - num == num) {
                if (numCnt[num] > 1)
                    return true;
            } else {
                if (numCnt.count(value - num))
                    return true;
            }
        }
        return false;
    }

private:
    unordered_map<int, int> numCnt;
};

class Solution {
public:
    void test() {
        TwoSum ts;
        ts.add(1); ts.add(3); ts.add(3); ts.add(5);
        cout << ts.find(4) << endl;
        cout << ts.find(7) << endl;
        cout << ts.find(6) << endl;
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
