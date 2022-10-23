/*
 * [Source] https://leetcode.com/problems/shortest-word-distance-ii/
 * [Difficulty]: Medium
 * [Tag]: Hash Table
 * [Tag]: Design
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

// [Solution]: Same algorithm. Just use hash table to reduce scanning
// [Corner Case]:
class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < (int)words.size(); ++i) {
            wordIdxesMap[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int> &word1Idx = wordIdxesMap[word1];
        vector<int> &word2Idx = wordIdxesMap[word2];

        int pt1 = 0, pt2 = 0;
        int minDist = INT_MAX;
        while (pt1 < (int)word1Idx.size() && pt2 < (int)word2Idx.size()) {
            int &idx1 = word1Idx[pt1], &idx2 = word2Idx[pt2];
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

private:
    unordered_map<string, vector<int>> wordIdxesMap;
};

class Solution {
public:
    void test() {
        vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
        WordDistance wd(words);
        cout << wd.shortest("coding", "practice") << endl;
        cout << wd.shortest("makes", "coding") << endl;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;
    sol.test();

    return 0;
}
