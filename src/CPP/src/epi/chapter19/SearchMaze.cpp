#include "SearchMaze.hpp"

#include <vector>
#include <unordered_set>
#include <functional>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::unordered_set;
using std::hash;
using std::ostream;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter19 {
    struct SearchMaze::Coordinate {
        bool operator==(const Coordinate &other) const {
            return (other.x == x && other.y == y);
        }

        std::vector<Coordinate> getNeighbors(const std::vector<std::vector<bool>> &maze) const {
            assert(!maze.empty() && !maze[0].empty());

            int height = maze.size(), width = maze[0].size();

            vector<Coordinate> edges;

            if (x - 1 >= 0 && maze[x - 1][y]) {
                edges.push_back({x - 1, y});
            }

            if (x + 1 < height && maze[x + 1][y]) {
                edges.push_back({x + 1, y});
            }

            if (y - 1 >= 0 && maze[x][y - 1]) {
                edges.push_back({x, y - 1});
            }

            if (y + 1 < width && maze[x][y + 1]) {
                edges.push_back({x, y + 1});
            }

            return edges;
        }

        int x, y;
    };

    struct SearchMaze::CoordinateHash {
        size_t operator()(const SearchMaze::Coordinate &coordinate) const {
            return hash<int>()(coordinate.x * 1021 + coordinate.y);
        }
    };

    ostream& operator<<(ostream &stream, SearchMaze::Coordinate &coordinate) {
        stream << "(" << coordinate.x << "," << coordinate.y << ")";
        return stream;
    }

    bool SearchMaze::searchMazeHelper(const vector<vector<bool>> &maze, const Coordinate &curr, const Coordinate &exit,
                    unordered_set<Coordinate, CoordinateHash> &visited, std::vector<Coordinate> &path) {
        // DFS doesn't return the shortest path
        if (visited.find(curr) != visited.end())
            return false; // cycle detected

        path.push_back(curr);

        if (curr == exit)
            return true;

        visited.insert(curr);

        for (const Coordinate &neighbor : curr.getNeighbors(maze)) {
            if ( searchMazeHelper(maze, neighbor, exit, visited, path) )
                return true;
        }

        path.pop_back();
        return false;
    }

    vector<SearchMaze::Coordinate> SearchMaze::searchMaze(const vector<vector<bool>> &maze,
            const Coordinate &start, const Coordinate &exit) {
        vector<Coordinate> path;
        unordered_set<Coordinate, CoordinateHash> visited;

        searchMazeHelper(maze, start, exit, visited, path);
        return path;
    }

    bool SearchMaze::test() {
        vector<vector<bool>> maze = {
                {0, 1, 1, 1, 1, 1, 0, 0, 1, 1},
                {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
                {0, 1, 0, 1, 1, 0, 0, 1, 0, 0},
                {1, 1, 1, 0, 0, 0, 1, 1, 0, 1},
                {1, 0, 0, 1, 1, 1, 1, 1, 1, 1},
                {1, 0, 0, 1, 1, 0, 1, 0, 0, 1},
                {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
                {0, 1, 0, 1, 0, 1, 0, 1, 1, 1},
                {0, 1, 0, 0, 1, 1, 1, 0, 0, 0},
                {1, 1, 1, 1, 1, 1, 1, 0, 0, 1}
        };

        vector<Coordinate> res = searchMaze( maze, {9, 0}, {0, 9} );
        for (Coordinate c : res) {
            cout << c << " -> ";
        }
        cout << endl;

        if (res.size() != 27) {
            cout << "Should be: 27" << endl;
            cout << "Result: " << res.size() << endl;

            return false;
        }

        return true;
    }

  } // chapter19
} // epi
