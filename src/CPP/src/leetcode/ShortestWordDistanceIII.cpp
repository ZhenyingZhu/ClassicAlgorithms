/*
 * [Source] https://leetcode.com/problems/shortest-word-distance-iii/
 * [Difficulty]: Medium
 * [Tag]: Array
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// [Solution]: One pass
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int pt1 = -1, pt2 = -1;

        int minDis = INT_MAX;
        for (int i = 0; i < (int)words.size(); ++i) {
            if (words[i] == word1) {
                if (pt2 != -1)
                    minDis = min(minDis, i - pt2);
                pt1 = i;
            }
            
            if (words[i] == word2) {
                if (pt1 != -1 && pt1 != i)
                    minDis = min(minDis, i - pt1);
                pt2 = i;
            }
        }
        return minDis;
    }
};

// [Solution]: Compare between indexes. No need to do it in O(n^2). Always move the smaller index ahead. When two words are same, they have same indexes. Use move one to the next
// [Corner Case]:
class SolutionStoreFirst {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> word1Idx, word2Idx;
        for (int i = 0; i < (int)words.size(); ++i) {
            if (words[i] == word1)
                word1Idx.push_back(i);
            if (words[i] == word2)
                word2Idx.push_back(i);
        }

        int pt1 = 0, pt2 = 0;
        int minDist = words.size();
        while (pt1 < (int)word1Idx.size() && pt2 < (int)word2Idx.size()) {
            int idx1 = word1Idx[pt1], idx2 = word2Idx[pt2];
            if (idx1 < idx2) {
                minDist = min(idx2 - idx1, minDist);
                ++pt1;
            } else if (idx1 > idx2) {
                minDist = min(idx1 - idx2, minDist);
                ++pt2;
            } else {
                ++pt1;
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
    cout << sol.shortestDistance(words, "makes", "makes") << endl;

    return 0;
}
