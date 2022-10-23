#ifndef SRC_EPI_CHAPTER17_NUMCOMBINATIONSFORFINALSCORE_HPP_
#define SRC_EPI_CHAPTER17_NUMCOMBINATIONSFORFINALSCORE_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter17 {
    class NumCombinationsForFinalScore : public myutils::Solution {
    public:
        NumCombinationsForFinalScore():
            Solution("EPI Chapter 17.1",
                     "Count the number of score combinations",
                     "From 0, 1, ..., x, to record how many ways to reach x, "
                     "then N(x) = N(x1) + N(x2) + N(x3) + ...,"
                     " where xi means xi + certain score = x.") { }

        ~NumCombinationsForFinalScore() { }

        size_t numCombinationsForFinalScoreWrong(unsigned int finalScore, const std::vector<unsigned int> &individualPlayScores);

        size_t numCombinationsForFinalScore(unsigned int finalScore, const std::vector<unsigned int> &individualPlayScores);

        bool test();

    };

  } // chapter17
} // epi

#endif /* SRC_EPI_CHAPTER17_NUMCOMBINATIONSFORFINALSCORE_HPP_ */
