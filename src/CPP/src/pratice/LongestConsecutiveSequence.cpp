#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/longest-consecutive-sequence/?tab=Description
// http://www.1point3acres.com/bbs/thread-225639-1-1.html

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        int maxLen = 0;
        while (!set.empty()) {
            int num = *set.begin();
            set.erase(num);
            int cnt = 1;

            int next = num + 1;
            while (set.count(next)) {
                set.erase(next);
                ++cnt;
                ++next;
            }

            int prev = num - 1;
            while (set.count(prev)) {
                set.erase(prev);
                ++cnt;
                --prev;
            }

            maxLen = max(maxLen, cnt);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    vector<int> vec = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutive(vec) << endl;

    return 0;
}
