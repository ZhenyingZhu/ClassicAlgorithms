#ifndef SRC_EPI_CHAPTER6_ONLINERANDOMSAMPLE_HPP_
#define SRC_EPI_CHAPTER6_ONLINERANDOMSAMPLE_HPP_

#include <vector>
#include <sstream>

#include "../../Solution.h"
#include "../../SmartPtr.h"

namespace epi {
  namespace chapter6 {
    class OnlineRandomSample : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        OnlineRandomSample():
            Solution("EPI Chapter 6.12",
                     "Random pick k data from incomming n data",
                     "ramdom pick one from the n data and if it is"
                     " in the subset, replace it with the new one.") { }

        bool test();

        ~OnlineRandomSample() { }

        std::vector<int> onlineRandomSample(std::istringstream *sin, int k);
    };
  } // chapter6
} // epi



#endif /* SRC_EPI_CHAPTER6_ONLINERANDOMSAMPLE_HPP_ */
