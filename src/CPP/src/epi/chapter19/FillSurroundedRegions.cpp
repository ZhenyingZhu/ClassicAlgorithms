#include "FillSurroundedRegions.hpp"

#include <vector>
#include <deque>
#include <queue>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::queue;
using std::deque;
using std::ostream;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter19 {
    struct FillSurroundedRegions::Coordinate {
        bool operator==(const Coordinate &other) const {
            return (other.x == x && other.y == y);
        }

        std::vector<Coordinate> getNeighbors(const vector<vector<char>> &matrix) {
            assert(!matrix.empty() && !matrix[0].empty());

            int height = matrix.size(), width = matrix[0].size();

            vector<Coordinate> edges;

            if (x - 1 >= 0 && matrix[x - 1][y]) {
                edges.push_back({x - 1, y});
            }

            if (x + 1 < height && matrix[x + 1][y]) {
                edges.push_back({x + 1, y});
            }

            if (y - 1 >= 0 && matrix[x][y - 1]) {
                edges.push_back({x, y - 1});
            }

            if (y + 1 < width && matrix[x][y + 1]) {
                edges.push_back({x, y + 1});
            }

            return edges;
        }

        int x, y;
    };

    void FillSurroundedRegions::flipColor(const Coordinate &start, vector<vector<char>> &board) {
        assert(!board.empty() && !board[0].empty());

        queue<Coordinate> visiting;
        visiting.push(start);

        while (!visiting.empty()) {
            Coordinate cur = visiting.front();
            visiting.pop();

            board[cur.x][cur.y] = 'G'; // mark as green

            for (const Coordinate &neighbor : cur.getNeighbors(board)) {
                if (board[neighbor.x][neighbor.y] == 'W') {
                    visiting.push(neighbor);
                }
            }
        }
    }

    void FillSurroundedRegions::fillSurroundedRegions(vector<vector<char>> &board) {
        assert(!board.empty() && !board[0].empty());

        int height = board.size(), width = board[0].size();

        for (int i = 0; i != height; ++i) {
            if (board[i][0] == 'W') {
                Coordinate c{i, 0};
                flipColor(c, board);
            }

            if (board[i][board[0].size() - 1] == 'W') {
                Coordinate c{i, width - 1};
                flipColor(c, board);
            }
        }

        for (int j = 0; j != width; ++j) {
            if (board[0][j] == 'W') {
                Coordinate c{0, j};
                flipColor(c, board);
            }

            if (board[board.size() - 1][j] == 'W') {
                Coordinate c{height - 1, j};
                flipColor(c, board);
            }
        }

        for (size_t i = 0; i != board.size(); ++i) {
            for (size_t j = 0; j != board.size(); ++j) {
                if (board[i][j] == 'G')
                    board[i][j] = 'W';
                else
                    board[i][j] = 'B';
            }
        }
    }

    bool FillSurroundedRegions::test() {
        vector<vector<char>> board = {
                {'B', 'B', 'B', 'B'},
                {'W', 'B', 'W', 'B'},
                {'B', 'W', 'W', 'B'},
                {'B', 'B', 'B', 'B'},
        };

        vector<vector<char>> ans = {
                {'B', 'B', 'B', 'B'},
                {'W', 'B', 'B', 'B'},
                {'B', 'B', 'B', 'B'},
                {'B', 'B', 'B', 'B'},
        };


        fillSurroundedRegions(board);

        if (board != ans) {
            for (const vector<char> &row : board) {
                for (const char &value : row) {
                    cout << value << " ";
                }
                cout << endl;
            }

            return false;
        }

        return true;
    }

  } // chapter19
} // epi
