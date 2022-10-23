#ifndef SRC_EPI_CHAPTER17_MINIMUMMESSINESS_HPP_
#define SRC_EPI_CHAPTER17_MINIMUMMESSINESS_HPP_

#include "../../Solution.h"

#include <vector>
#include <string>

namespace epi {
  namespace chapter17 {
    class MinimumMessiness : public myutils::Solution {
    public:
        MinimumMessiness():
            Solution("EPI Chapter 17.11",
                     "The pretty printing problem",
                     "Use the sum square of the blanks at the end of each line as messiness, "
                     "find the min messiness of ways to distribute words in fixed-size lines. "
                     "Consider the last line, there could be one to all words in it. The messiness "
                     "is messiness of previous lines + messiness of the last line.") { }

        ~MinimumMessiness() { }

        int minimumMessiness(const std::vector<std::string> &words, int lineLength);

        bool test();

    };

  } // chapter17
} // epi

#endif /* SRC_EPI_CHAPTER17_MINIMUMMESSINESS_HPP_ */
