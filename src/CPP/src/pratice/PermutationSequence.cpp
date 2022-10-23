#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Source]: https://leetcode.com/problems/permutation-sequence/
// www.1point3acres.com/bbs/thread-224947-1-1.html

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> idxes = computeIdx(n, k);

        vector<bool> used(n, false);
        vector<char> res;
        for (int &idx : idxes) {
            int cur = 0;
            for (int i = 0; i < n; ++i) {
                if (used[i])
                    continue;
                if (cur == idx) {
                    used[i] = true;
                    res.push_back('1' + i);
                    break;
                }
                ++cur;
            }
        }

        return string(res.begin(), res.end());
    }

    vector<int> computeIdx(int n, int k) {
        --k;
        if (k < 0)
            return {};

        vector<int> powers = {1};
        for (int i = 1; i < n; ++i) {
            powers.push_back(powers.back() * i);
        }
        reverse(powers.begin(), powers.end());

        vector<int> idxes(n);
        for (int i = 0; i < n; ++i) {
            idxes[i] = k / powers[i];
            // k too large
            if (idxes[i] >= n)
                return {};
            k %= powers[i];
        }
        return idxes;
    }
};

int main() {
    Solution sol;
    for (int i = 1; i <= 7; ++i)
        cout << sol.getPermutation(9, i) << endl;
}
