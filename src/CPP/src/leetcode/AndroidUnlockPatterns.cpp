/*
 * [Source] https://leetcode.com/problems/android-unlock-patterns/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 * [Tag]: Backtracking
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Backtracking. Checking if it is able to go from a st to an ed. Since there is only 9 cells, it can pass the OJ.
// [Corner Case]:
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<int> path;
        vector<bool> used(9, false);
        return helper(path, used, m, n);
    }

    int helper(vector<int> &path, vector<bool> &used, int m, int n) {
        int size = path.size();
        if (size > n)
            return 0;
        int patterns = 0;
        if (size >= m) {
for (int &i : path) cout << i << "->"; cout << endl;
            ++patterns;
        }

        for (int i = 1; i <= 9; ++i) {
            if (used[i - 1])
                continue;

            if (path.empty() || accessiable(path.back(), i, used)) {
                path.push_back(i);
                used[i - 1] = true;
                patterns += helper(path, used, m, n);

                path.pop_back();
                used[i - 1] = false;
            }
        }
        return patterns;
    }

    bool accessiable(int st, int ed, vector<bool> &used) {
        if (st > ed) // no need to compare twice
            swap(st, ed);

        if (ed - st == 2) {
            if (st % 3 == 1) // 1-3
                return used[st]; // so 2 should be used
            return true; // 2-4
        }

        if (ed - st == 6) // 1-7
            return used[st + 2];

        if ( (st == 1 && ed == 9) || (st == 3 && ed == 7) )
            return used[4];

        return true;
    }
};

int main() {
    Solution sol;

    cout << sol.numberOfPatterns(1, 9) << endl;

    return 0;
}
