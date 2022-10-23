/*
 * [Source] https://leetcode.com/problems/excel-sheet-column-title/
 * [Difficulty]: Easy
 * [Tag]: Math
 */

#include <iostream>
#include <algorithm>

using namespace std;

// [Solution]: mode 26, then add a correspond letter until 0.
// [Corner Case]: should treat A as 1 since otherwise AA become 0.
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        string candidates = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
        while (n != 0) {
            res.push_back(candidates[n % 26]);
            n =  (n - 1) / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// [Solution]:
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/ExcelSheetColumnTitle.java
 */

int main() {
    Solution sol;

    for (int i = 1; i <= 26*26; ++i)
        cout << sol.convertToTitle(i) << endl;

    return 0;
}
