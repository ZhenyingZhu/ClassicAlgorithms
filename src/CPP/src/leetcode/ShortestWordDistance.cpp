/*
 * [Source] https://leetcode.com/problems/shortest-word-distance/
 * [Difficulty]: Easy
 * [Tag]: Array
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Compare between indexes. No need to do it in O(n^2). Always move the smaller index ahead.
// [Corner Case]:
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> word1Idx, word2Idx;
        for (int i = 0; i < (int)words.size(); ++i) {
            if (words[i] == word1)
                word1Idx.push_back(i);
            else if (words[i] == word2)
                word2Idx.push_back(i);
        }

        int pt1 = 0, pt2 = 0;
        int minDist = words.size();
        while (pt1 < (int)word1Idx.size() && pt2 < (int)word2Idx.size()) {
            int idx1 = word1Idx[pt1], idx2 = word2Idx[pt2];
            if (idx1 < idx2) {
                minDist = min(idx2 - idx1, minDist);
                ++pt1;
            } else {
                minDist = min(idx1 - idx2, minDist);
                ++pt2;
            }
        }
        return minDist;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
    cout << sol.shortestDistance(words, "coding", "practice") << endl;
    cout << sol.shortestDistance(words, "makes", "coding") << endl;

    return 0;
}
