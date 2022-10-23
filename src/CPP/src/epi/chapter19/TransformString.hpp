#ifndef SRC_EPI_CHAPTER19_TRANSFORMSTRING_HPP_
#define SRC_EPI_CHAPTER19_TRANSFORMSTRING_HPP_

#include "../../Solution.h"

#include <vector>
#include <unordered_set>
#include <string>

namespace epi {
  namespace chapter19 {
    class TransformString : public myutils::Solution {
    public:
        TransformString():
            Solution("EPI Chapter 19.7",
                     "Transform one string to another",
                     "From a dictionary, find strings that have only one char differ "
                     "between each other, to convert one string to another. Use each "
                     "string as a vertex, and use BFS to find the shortest path.") { }

        ~TransformString() { }

        int transformString(std::unordered_set<std::string> dict, const std::string &s, const std::string &t);

        bool test();

    };

  } // chapter19
} // epi

#endif /* SRC_EPI_CHAPTER19_TRANSFORMSTRING_HPP_ */
