/*
 * [Source] https://leetcode.com/problems/assign-cookies/
 * [Difficulty]: Easy
 * [Tag]: Greedy
 */

#include <iostream>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>()); // child
        sort(s.begin(), s.end(), greater<int>()); // cookie
        int cookie = 0;
        int cnt = 0;
        for (int child = 0; child < (int)g.size() && cookie < (int)s.size(); ++child) {
            if (s[cookie] >= g[child]) {
                ++cookie;
                ++cnt;
            }
        }

        return cnt;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    return 0;
}
