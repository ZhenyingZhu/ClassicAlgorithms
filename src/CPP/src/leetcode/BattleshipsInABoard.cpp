/*
 * [Source] https://leetcode.com/problems/battleships-in-a-board/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// [Solution]: If left or up cell is 'X', it means this cell is part of the previous counted ship
// [Corner Case]:
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return 0;
        int h = board.size(), w = board[0].size();

        int res = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (board[i][j] == 'X') {
                    // if this is part of the previous ship
                    if (i != 0 && board[i - 1][j] == 'X')
                        continue;
                    if (j != 0 && board[i][j - 1] == 'X')
                        continue;
                    ++res;
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

    vector<string> strs = {"X..X", "...X", "...X"};
    vector<vector<char>> board;
    for (string &s : strs) {
        board.push_back(vector<char>(s.begin(), s.end()));
    }

    cout << sol.countBattleships(board) << endl;

    return 0;
}
