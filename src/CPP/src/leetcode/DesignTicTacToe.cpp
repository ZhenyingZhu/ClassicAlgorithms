/*
 * [Source] https://leetcode.com/problems/design-tic-tac-toe/
 * [Difficulty]: Medium
 * [Tag]: Design
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]:
// [Corner Case]:
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->n = n;
        ver.resize(2, vector<int>(n, 0));
        hor.resize(2, vector<int>(n, 0));
        dia.resize(2, vector<int>(2, 0));
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int p = player - 1;
        ++ver[p][row];
        if (ver[p][row] == n)
            return player;
        ++hor[p][col];
        if (hor[p][col] == n)
            return player;

        if (row == col) {
            ++dia[p][0];
            if (dia[p][0] == n)
                return player;
        }
        if (row + col == n - 1) {
            ++dia[p][1];
            if (dia[p][1] == n)
                return player;
        }

        return 0;
    }

    int n;
    vector<vector<int>> ver;
    vector<vector<int>> hor;
    vector<vector<int>> dia;
};

class Solution {
public:
    void test() {
        TicTacToe t(3);
        cout << t.move(0,0,1) << endl;
        cout << t.move(0,2,2) << endl;
        cout << t.move(2,2,1) << endl;
        cout << t.move(1,1,2) << endl;
        cout << t.move(2,0,1) << endl;
        cout << t.move(1,0,2) << endl;
        cout << t.move(2,1,1) << endl;
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
