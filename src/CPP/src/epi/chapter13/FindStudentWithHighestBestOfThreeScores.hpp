#ifndef SRC_EPI_CHAPTER13_FINDSTUDENTWITHHIGHESTBESTOFTHREESCORES_HPP_
#define SRC_EPI_CHAPTER13_FINDSTUDENTWITHHIGHESTBESTOFTHREESCORES_HPP_

#include "../../Solution.h"

#include <string>
#include <fstream>

namespace epi {
  namespace chapter13 {
    class FindStudentWithHighestBestOfThreeScores : myutils::Solution {
    public:
        FindStudentWithHighestBestOfThreeScores():
            Solution("EPI Chapter 13.11",
                     "Compute the average of the top three scores",
                     "Store scores in a min heap for each student.") { }

        ~FindStudentWithHighestBestOfThreeScores() { }

        std::string findStudentWithHighestBestOfThreeScores(std::ifstream *ifs);

        bool test();

    };

  } // chapter13
} // epi

#endif /* SRC_EPI_CHAPTER13_FINDSTUDENTWITHHIGHESTBESTOFTHREESCORES_HPP_ */
