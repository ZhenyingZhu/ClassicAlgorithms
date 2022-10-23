/*
 * [Source] https://leetcode.com/problems/optimal-account-balancing/
 * [Difficulty]: Hard
 * [Tag]: 
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

// [Solution]: It is a NP problem. Each person either owe, or lend money. Backtracking to find the min trans to make every one has 0 money.
// [Corner Case]:
class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, long> personMoneyMap;
        for (vector<int> &tran : transactions) {
            personMoneyMap[tran[0]] -= tran[2];
            personMoneyMap[tran[1]] += tran[2];
        }

        vector<long> depts;
        for (auto it = personMoneyMap.begin(); it != personMoneyMap.end(); ++it) {
            if (it->second != 0)
                depts.push_back(it->second);
        }

        int res = INT_MAX;
        helper(depts, 0, 0, res);
        return res;
    }

    void helper(vector<long> &depts, int trans, int st, int &res) {
        int size = depts.size();
        while (st < size && depts[st] == 0)
            ++st;

        if (st == size) {
            res = min(trans, res);
            return;
        }

        for (int i = st + 1; i < size; ++i) {
            if ( (depts[i] < 0 && depts[st] > 0) || (depts[i] > 0 && depts[st] < 0) ) {
                depts[i] += depts[st];
                helper(depts, trans + 1, st + 1, res);
                depts[i] -= depts[st];
            }
        }
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<vector<int>> trans = {{0,1,10}, {1,0,1}, {1,2,5}, {2,0,5}};
    cout << sol.minTransfers(trans) << endl;

    return 0;
}
