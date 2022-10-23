/*
 * [Source] https://leetcode.com/problems/h-index-ii/
 * [Difficulty]: Medium
 * [Tag]: Binary Search
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: max of the min(idx, val). So can use binary search. If the middle idx is smaller, but the middle - 1 idx is larger, than we get the answer
// [Corner Case]:
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        if (size == 0)
            return 0;

        int st = 0, ed = size - 1;
        while (st + 1 < ed) {
            int md = st + (ed - st) / 2;
            if (citations[md] == getIndex(md, size))
                return citations[md];

            if (citations[md] > getIndex(md, size)) {
                ed = md;
            } else {
                st = md;
            }
        }

        int first = min(citations[st], getIndex(st, size));
        int second = min(citations[ed], getIndex(ed, size));
        return max(first, second);
    }

    int getIndex(int idx, int size) {
        return size - idx;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<vector<int>> testcases = {
        {0},
        {2},
        {0, 1, 3, 5, 6},
        {6, 6, 6},
        {0, 0, 4, 4}
    };

    for (vector<int>& vec : testcases) {
        cout << sol.hIndex(vec) << endl;
    }

    return 0;
}
