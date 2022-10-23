/*
 * [Source] https://leetcode.com/problems/magical-string/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Brute force
// [Corner Case]:
class Solution {
public:
    int magicalString(int n) {
        if (n <= 0)
            return 0;
        if (n <= 3)
            return 1;

        vector<int> vec = {1, 2, 2};
        vec.reserve(n);

        int idx = 2;
        while ( (int)vec.size() < n ) {
            int cnt = vec[idx++];
            int num = vec.back() + 1;
            if (num == 3)
                num = 1;
            for (int i = 0; i < cnt; ++i)
                vec.push_back(num);
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (vec[i] == 1)
                ++res;
        }
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;
    cout << sol.magicalString(6) << endl;

    return 0;
}
