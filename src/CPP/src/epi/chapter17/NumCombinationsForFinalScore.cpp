#include "NumCombinationsForFinalScore.hpp"

#include <vector>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter17 {
    size_t NumCombinationsForFinalScore::numCombinationsForFinalScoreWrong
            (unsigned int finalScore, const vector<unsigned int> &individualPlayScores) {
        if (finalScore == 0)
            return 1;

        vector<size_t> numWaysToI = {1};
        for (unsigned int i = 1; i <= finalScore; ++i) {
            size_t numWays = 0;
            for (const unsigned int &score : individualPlayScores) {
                if (score > i)
                    continue;

                numWays += numWaysToI[i - score];
            }

            numWaysToI.push_back(numWays);
            cout << vec_to_string(numWaysToI) << endl;
        }

        return numWaysToI[finalScore];
    }

    size_t NumCombinationsForFinalScore::numCombinationsForFinalScore
            (unsigned int finalScore, const vector<unsigned int> &individualPlayScores) {
        if (finalScore == 0)
            return 1;

        vector<vector<size_t>> numWaysToI(
                individualPlayScores.size(),
                vector<size_t>(finalScore + 1, 0)
                );
        for (size_t i = 0; i != individualPlayScores.size(); ++i) {
            numWaysToI[i][0] = 1;
        }

        for (size_t scoreSize = 0; scoreSize != individualPlayScores.size(); ++scoreSize) {
            unsigned int currentScore = individualPlayScores[scoreSize]; // Add this score to totalScore or not
            for (unsigned int totalScore = 1; totalScore <= finalScore; ++totalScore) {
                size_t withoutThisScore = scoreSize == 0 ?
                        0 : numWaysToI[scoreSize - 1][totalScore];
                size_t withThisScore = currentScore > totalScore ?
                        0 : numWaysToI[scoreSize][totalScore - currentScore];

                numWaysToI[scoreSize][totalScore] = withoutThisScore + withThisScore;
            }
        }

        return numWaysToI[individualPlayScores.size() - 1][finalScore];
    }

    bool NumCombinationsForFinalScore::test() {
        vector<unsigned int> individualPlayScores = {2, 3, 7};

        size_t res = numCombinationsForFinalScore(12, individualPlayScores);

        if (res != 4) {
            cout << "Should be: 4" << endl;
            cout << "Result: " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter17
} // epi
