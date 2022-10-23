/*
 * [Source] https://leetcode.com/problems/lexicographical-numbers/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Recursive call.
// [Corner Case]:
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        res.reserve(n);

        for (int i = 1; i <= 9 && i <= n; ++i)
            helper(i, n, res);
        return res;
    }

    void helper(int pre, int n, vector<int> &res) {
        res.push_back(pre);

        if (pre > n / 10)
            return;

        pre *= 10;
        for (int i = 0; i <= 9; ++i) {
            if (pre + i > n)
                break;
            helper(pre + i, n, res);
        }
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    for (int &num : sol.lexicalOrder(13)) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
