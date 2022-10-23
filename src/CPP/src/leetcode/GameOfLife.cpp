/*
 * [Source] https://leetcode.com/problems/game-of-life/
 * [Difficulty]: Medium
 * [Tag]: Array
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: First update live cells to be 10 (9 is enough but easy to compute) to distinct live and dead. Then for each live cell, increase 1 for all of its neighbors.
// [Corner Case]:
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0 || board[0].size() == 0)
            return;

        int height = board.size(), width = board[0].size();
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (board[i][j] == 1)
                    board[i][j] = 10;
            }
        }

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                updateNeighbors(i, j, board);
            }
        }

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (board[i][j] == 3 || board[i][j] == 12 || board[i][j] == 13)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }

    void updateNeighbors(int i, int j, vector<vector<int>>& board) {
        bool isLive = board[i][j] >= 10;

        for (int h = i - 1; h <= i + 1; ++h) {
            if (h < 0 || h >= (int)board.size())
                continue;

            for (int w = j - 1; w <= j + 1; ++w) {
                if (w < 0 || w >= (int)board[0].size())
                    continue;

                if (h == i && w == j)
                    continue;

                if (isLive)
                    ++board[h][w];
            }
        }
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<vector<int>> board = {
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0}
    };

    sol.gameOfLife(board);
    for (vector<int>& vec : board) {
        for (int& n : vec) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}
