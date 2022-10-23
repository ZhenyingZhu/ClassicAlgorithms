#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/design-tic-tac-toe/
// http://www.1point3acres.com/bbs/thread-224495-1-1.html

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        size = n;
        rows.resize(2, vector<int>(n, 0));
        cols.resize(2, vector<int>(n, 0));
        diags.resize(2, vector<int>(2, 0));
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
        int idx = player - 1;
        rows[idx][row]++;
        if (rows[idx][row] == size)
            return player;

        cols[idx][col]++;
        if (cols[idx][col] == size)
            return player;

        if (row == col) {
            diags[idx][0]++;
            if (diags[idx][0] == size)
                return player;
        }
        if (row + col == size - 1) {
            diags[idx][1]++;
            if (diags[idx][1] == size)
                return player;
        }

        return 0;
    }

private:
    int size;
    vector<vector<int>> rows;
    vector<vector<int>> cols;
    vector<vector<int>> diags;
};

int main() {
    TicTacToe t(3);

    t.move(0, 0, 1);

    return 0;
}
