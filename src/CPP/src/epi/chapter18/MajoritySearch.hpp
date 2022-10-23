#ifndef SRC_EPI_CHAPTER18_MAJORITYSEARCH_HPP_
#define SRC_EPI_CHAPTER18_MAJORITYSEARCH_HPP_

#include "../../Solution.h"

#include <string>
#include <sstream>

namespace epi {
  namespace chapter18 {
    class MajoritySearch : public myutils::Solution {
    public:
        MajoritySearch():
            Solution("EPI Chapter 18.5",
                     "Find the majority element",
                     "Majority element must occurs more than n / 2 times in a n-size array. "
                     "So use a counter on current element. If next element is the same one, "
                     "increase the count; otherwise decrease the count. If the count back to 0, "
                     "it means the element cannot be the majority, and the last one differ from "
                     "it cannot be the majority as well. So pick the next one as candidate. The "
                     "algorithm return a nonsense result when there are at lest two majority numbers.") { }

        ~MajoritySearch() { }

        std::string majoritySearch(std::istringstream *inputStream);

        bool test();

    };

  } // chapter18
} // epi

#endif /* SRC_EPI_CHAPTER18_MAJORITYSEARCH_HPP_ */
