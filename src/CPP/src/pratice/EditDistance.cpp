#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/edit-distance/
// http://www.1point3acres.com/bbs/thread-225081-1-1.html

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty())
            return word2.length();
        if (word2.empty())
            return word1.length();

        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> minSteps(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; ++i)
            minSteps[i][0] = i;
        for (int j = 1; j <= len2; ++j)
            minSteps[0][j] = j;

        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                if (word1[i] == word2[j]) {
                    minSteps[i + 1][j + 1] = minSteps[i][j];
                } else {
                    minSteps[i + 1][j + 1] = 1 + min(minSteps[i][j], min(minSteps[i][j + 1], minSteps[i + 1][j]));
                }
            }
        }

        return minSteps[len1][len2];
    }
};

int main() {
    Solution sol;

    cout << sol.minDistance("abc", "accd") << endl;

    return 0;
}
