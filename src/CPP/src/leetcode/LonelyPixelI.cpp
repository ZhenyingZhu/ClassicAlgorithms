/*
 * [Source] https://leetcode.com/problems/lonely-pixel-i
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Depth-first Search
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Preprocess to count numbers.
// [Corner Case]:
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        if (picture.empty() || picture[0].empty())
            return 0;

        int h = picture.size(), w = picture[0].size();
        vector<int> blackOnRow(h, 0), blackOnCol(w, 0);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (picture[i][j] == 'B') {
                    blackOnRow[i]++;
                    blackOnCol[j]++;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (picture[i][j] == 'B' && blackOnRow[i] == 1 && blackOnCol[j] == 1)
                    res++;
            }
        }
        return res;
    }
};

// [Solution]:

int main() {
    Solution sol;

    vector<vector<char>> picture = {
        {'W', 'W', 'B'},
        {'W', 'B', 'W'},
        {'B', 'W', 'B'}
    };
    cout << sol.findLonelyPixel(picture) << endl;

    return 0;
}
