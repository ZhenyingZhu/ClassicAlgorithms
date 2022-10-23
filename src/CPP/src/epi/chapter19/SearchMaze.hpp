#ifndef SRC_EPI_CHAPTER19_SEARCHMAZE_HPP_
#define SRC_EPI_CHAPTER19_SEARCHMAZE_HPP_

#include "../../Solution.h"

#include <vector>
#include <unordered_set>

namespace epi {
  namespace chapter19 {
    class SearchMaze : public myutils::Solution {
    public:
        struct Coordinate;

        struct CoordinateHash;

        SearchMaze():
            Solution("EPI Chapter 19.1",
                     "Search a maze",
                     "Model the maze as a indirected graph. Use DFS to find the path.") { }

        ~SearchMaze() { }

        std::vector<Coordinate> searchMaze(const std::vector<std::vector<bool>> &maze, const Coordinate &start, const Coordinate &exit);

        bool test();

    private:
        bool searchMazeHelper(const std::vector<std::vector<bool>> &maze, const Coordinate &curr, const Coordinate &exit,
                std::unordered_set<Coordinate, CoordinateHash> &visited, std::vector<Coordinate> &path);

    };

  } // chapter19
} // epi

#endif /* SRC_EPI_CHAPTER19_SEARCHMAZE_HPP_ */
