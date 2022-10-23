/*
 * [Source] https://leetcode.com/problems/lonely-pixel-ii
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Depth-first Search
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// [Solution]: Use a hashmap to see if all rows follow rule2 are same
// [Corner Case]:
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if (picture.empty() || picture[0].empty())
            return 0;
        int h = picture.size(), w = picture[0].size();

        // preprocess
        vector<int> blackOnRow(h, 0), blackOnCol(w, 0);
        // the different rows that have a black pixel at column C
        unordered_map<int, unordered_set<string>> blackOnColString;

        for (int i = 0; i < h; i++) {
            string cur = string(picture[i].begin(), picture[i].end());
            for (int j = 0; j < w; j++) {
                if (picture[i][j] == 'B') {
                    blackOnRow[i]++;
                    blackOnCol[j]++;
                    blackOnColString[j].insert(cur);
                }
            }
        }

        // checking
        int res = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (picture[i][j] == 'B') {
                    // Rule1
                    if (blackOnRow[i] != N || blackOnCol[j] != N)
                        continue;
                    // Rule2
                    if (blackOnColString[j].size() > 1)
                        continue;

                    res++;
                }
            }
        }
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<vector<char>> picture = {
        {'W', 'B', 'W', 'B', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'B', 'W'},
        {'W', 'W', 'B', 'W', 'B', 'W'}
    };
    int N = 3;

    cout << sol.findBlackPixel(picture, N) << endl;

    return 0;
}
