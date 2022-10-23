#ifndef SRC_EPI_CHAPTER18_FINDAMPLECITY_HPP_
#define SRC_EPI_CHAPTER18_FINDAMPLECITY_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter18 {
    class FindAmpleCity : public myutils::Solution {
    public:
        FindAmpleCity():
            Solution("EPI Chapter 18.6",
                     "The gasup problem",
                     "If find when reach a city, the gas is not "
                     "enough, then start from this city.") { }

        ~FindAmpleCity() { }

        size_t findAmpleCity(const std::vector<int> &gallons, const std::vector<int> &distances);

        bool test();

    private:
        const int kMPG = 20;

    };

  } // chapter18
} // epi

#endif /* SRC_EPI_CHAPTER18_FINDAMPLECITY_HPP_ */
