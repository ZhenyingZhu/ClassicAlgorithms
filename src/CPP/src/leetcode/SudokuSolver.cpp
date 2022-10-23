/*
 * [Source] https://leetcode.com/problems/sudoku-solver/
 * [Difficulty]: Hard
 * [Tag]: Backtrcking
 * [Tag]: Hash Table
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>

using namespace std;

// [Solution]: Use coordinate as key, and a boolen vector as value, indicate which value is already used. Need reverse after update
// [Corner Case]: So many corner cases, don't use hash table
class Solution {
private:
    struct Coordinate {
        bool operator==(const Coordinate& other) const {
            return x == other.x && y == other.y;
        }

        int x, y;
    };

    struct CoordinateHash {
        size_t operator()(const Coordinate& c) const {
            return hash<int>()(9 * c.x + c.y);
        }
    };

    vector<Coordinate> markUsage(const Coordinate& c, int val, unordered_map<Coordinate, vector<bool>, CoordinateHash>& map) {
        vector<Coordinate> changed;
        
        if (!map[c][val - 1]) {
            map[c][val - 1] = true;
            changed.push_back(c);
        }
        for (int row = 0; row < 9; ++row) {
            Coordinate r{row, c.y};
            if (!map[r][val - 1]) {
                map[r][val - 1] = true;
                changed.push_back(r);
            }
        }
        for (int col = 0; col < 9; ++col) {
            Coordinate l{c.x, col};
            if (!map[l][val - 1]) {
                map[l][val - 1] = true;
                changed.push_back(l);
            }
        }
        int offsetX = c.x / 3 * 3, offsetY = c.y / 3 * 3;
        for (int i = offsetX; i < offsetX + 3; ++i) {
            for (int j = offsetY; j < offsetY + 3; ++j) {
                Coordinate t{i, j};
                if (!map[t][val - 1]) {
                    map[t][val - 1] = true;
                    changed.push_back(t);
                }
            }
        }

        return changed;
    }

    void reverseChange(const vector<Coordinate>& changed, int val, unordered_map<Coordinate, vector<bool>, CoordinateHash>& map) {
        for (const Coordinate& c : changed)
            map[c][val - 1] = false;
    }

    unordered_map<Coordinate, vector<bool>, CoordinateHash> initMap(const vector<vector<char>>& board) {
        unordered_map<Coordinate, vector<bool>, CoordinateHash> usedNumMap;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                Coordinate c{i, j};
                usedNumMap[c] = vector<bool>(9, false);
            }
        }
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                Coordinate c{i, j};
                markUsage(c, (int)(board[i][j] - '0'), usedNumMap);
            }
        }
        return usedNumMap;
    }

    bool sudokuHelper(const Coordinate& cur, vector<vector<char>>& board, unordered_map<Coordinate, vector<bool>, CoordinateHash>& usedNumMap) {
        if (cur.x == 9)
            return true;

        int nextY = cur.y + 1, nextX = cur.x;
        if (nextY == 9) {
            nextY = 0;
            ++nextX;
        }
        Coordinate next{nextX, nextY};

        if (board[cur.x][cur.y] != '.')
            return sudokuHelper(next, board, usedNumMap);

        for (int val = 1; val <= 9; ++val) {
            if (usedNumMap[cur][val - 1])
                continue;
            vector<Coordinate> changed = markUsage(cur, val, usedNumMap);
            board[cur.x][cur.y] = '0' + val;
            if (sudokuHelper(next, board, usedNumMap))
                return true;
            reverseChange(changed, val, usedNumMap);
        }

        board[cur.x][cur.y] = '.';
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        unordered_map<Coordinate, vector<bool>, CoordinateHash> usedNumMap = initMap(board);
        sudokuHelper({0, 0}, board, usedNumMap);
    }

private: // helper
    void dumpMap(const unordered_map<Coordinate, vector<bool>, CoordinateHash>& map) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                Coordinate cur{i,j};
                cout << "(" << i << "," << j << "):";
                const vector<bool>& v = map.find(cur)->second;
                for (const bool& b : v) {
                    if (b)
                        cout << "T";
                    else
                        cout << "F";
                }
                cout << endl;
            }
        }
    }


};

// [Solution]: Don't use stupid hash table, just check valid every time when try a value
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/SudokuSolver.java
 */

/* Java solution
public class Solution {
    public void solveSudoku(char[][] board) {
        solveSudokuHelper(board); 
    }
    
    private boolean solveSudokuHelper(char[][] board) {
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (board[i][j] == '.') {
                    for (int k = 0; k < 9; ++k) {
                        board[i][j] = (char)('1' + k); // Need used for next cell. 
                        if (isValid(board, i, j) && solveSudokuHelper(board)) {
                            return true;
                        } else {
                            board[i][j] = '.'; // Might already be set for next cell. 
                        }
                    }
                    return false; // There is still empty cell. 
                }
            }
        }
        return true; // No empty cell. 
    }
    
    private boolean isValid(char[][] board, int x, int y) {
        int i, j; 
        for (i = 0; i < 9; ++i) { // The col. 
            if (i != x && board[i][y] == board[x][y]) {
                return false;
            }
        }
        for (j = 0; j < 9; ++j) { // The row.
            if (j != y && board[x][j] == board[x][y]) {
                return false;
            }
        }
        int xAxis = 3 * (x / 3); 
        int yAxis = 3 * (y / 3);
        for (i = xAxis; i < xAxis + 3; ++i) {
            for (j = yAxis; j < yAxis + 3; ++j) {
                if (i != x && j != y && board[i][j] == board[x][y]) {
                    return false; 
                }
            }
        }
        return true;
    }
}
 */

int main() {
    Solution sol;

    /*
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    */
    vector<vector<char>> board = {
        {'.','.','9','7','4','8','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'.','2','.','1','.','9','.','.','.'},
        {'.','.','7','.','.','.','2','4','.'},
        {'.','6','4','.','1','.','5','9','.'},
        {'.','9','8','.','.','.','3','.','.'},
        {'.','.','.','8','.','3','.','2','.'},
        {'.','.','.','.','.','.','.','.','6'},
        {'.','.','.','2','7','5','9','.','.'}
    };

    sol.solveSudoku(board);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j];
        }
        cout << endl;
    }

    return 0;
}
