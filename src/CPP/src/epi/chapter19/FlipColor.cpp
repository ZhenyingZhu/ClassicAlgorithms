#include "FlipColor.hpp"

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
    struct FlipColor::Coordinate {
        bool operator==(const Coordinate &other) const {
            return (other.x == x && other.y == y);
        }

        std::vector<Coordinate> getNeighbors(const vector<deque<bool>> &matrix) {
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

    ostream& operator<<(ostream &stream, FlipColor::Coordinate &coordinate) {
        stream << "(" << coordinate.x << "," << coordinate.y << ")";
        return stream;
    }

    void FlipColor::flipColor(int x, int y, vector<deque<bool>> &matrix) {
        assert(!matrix.empty() && !matrix[0].empty());

        bool value = matrix[x][y];

        queue<Coordinate> visiting;

        Coordinate start{x, y};
        visiting.push(start);

        while (!visiting.empty()) {
            Coordinate cur = visiting.front();
            visiting.pop();

            matrix[cur.x][cur.y] = !value;

            for (const Coordinate &neighbor : cur.getNeighbors(matrix)) {
                if (matrix[neighbor.x][neighbor.y] == value) {
                    visiting.push(neighbor);
                }
            }
        }
    }

    bool FlipColor::test() {
        vector<deque<bool>> matrix = {
                {0, 1, 0, 1, 1, 1, 0, 0, 0, 0},
                {1, 1, 0, 1, 1, 0, 1, 1, 0, 0},
                {0, 0, 0, 1, 1, 0, 0, 1, 0, 0},
                {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
                {0, 1, 0, 1, 1, 1, 1, 0, 1, 1},
                {0, 1, 0, 1, 1, 0, 1, 0, 0, 0},
                {1, 1, 1, 1, 0, 1, 0, 1, 1, 0},
                {0, 1, 0, 1, 0, 1, 0, 1, 1, 1},
                {0, 1, 0, 0, 1, 1, 1, 0, 0, 0},
                {1, 1, 1, 1, 1, 1, 1, 0, 0, 1}
        };

        vector<deque<bool>> ans = {
                {0, 1, 0, 1, 1, 1, 0, 0, 0, 0},
                {1, 1, 0, 1, 1, 0, 1, 1, 0, 0},
                {0, 0, 0, 1, 1, 0, 0, 1, 0, 0},
                {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
                {0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
        };


        flipColor(5, 4, matrix);

        if (matrix != ans) {
            for (const deque<bool> &row : matrix) {
                for (const bool &value : row) {
                    cout << (value ? 1 : 0) << " ";
                }
                cout << endl;
            }

            return false;
        }

        return true;
    }

  } // chapter19
} // epi
