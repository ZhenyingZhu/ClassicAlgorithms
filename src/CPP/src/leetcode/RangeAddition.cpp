/*
 * [Source] https://leetcode.com/problems/range-addition/
 * [Difficulty]: Medium
 * [Tag]: Array
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Update only the begining to inc, and the next of ending to dec
// [Corner Case]:
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        if (length == 0)
            return {};

        vector<int> diff(length, 0);
        for (vector<int> &update : updates) {
            int st = update[0], ed = update[1] + 1;
            int inc = update[2];
            
            diff[st] += inc;
            if (ed < length)
                diff[ed] -= inc;
        }

        vector<int> res;
        int sum = 0;
        for (int &d : diff) {
            sum += d;
            res.push_back(sum);
        }

        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<vector<int>> updates = {{1,3,2}, {2,4,3}, {0,2,-2}};
    for (int &n : sol.getModifiedArray(5, updates))
        cout << n << " ";
    cout << endl;

    return 0;
}
