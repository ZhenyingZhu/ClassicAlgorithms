#ifndef SRC_EPI_CHAPTER17_LEVENSHTEINDISTANCE_HPP_
#define SRC_EPI_CHAPTER17_LEVENSHTEINDISTANCE_HPP_

#include "../../Solution.h"

#include <string>

namespace epi {
  namespace chapter17 {
    class LevenshteinDistance : public myutils::Solution {
    public:
        LevenshteinDistance():
            Solution("EPI Chapter 17.2",
                     "Compute the Levenshtein distance",
                     "To make first i chars from s1 and first j chars from s2 to be same, "
                     "if s1(i) == s2(j), T(i,j)=min(T(i-1,j), T(i,j-1), T(i-1,j-1)), "
                     "otherwise the min + 1.") { }

        ~LevenshteinDistance() { }

        size_t levenshteinDistance(const std::string &str1, const std::string &str2);

        bool test();

    };

  } // chapter17
} // epi

#endif /* SRC_EPI_CHAPTER17_LEVENSHTEINDISTANCE_HPP_ */
