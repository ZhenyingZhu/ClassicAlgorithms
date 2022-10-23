#ifndef SRC_EPI_CHAPTER11_FINDCLOSESTKSTARS_HPP_
#define SRC_EPI_CHAPTER11_FINDCLOSESTKSTARS_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>
#include <sstream>

namespace epi {
  namespace chapter11 {
    class FindClosestKStars : myutils::Solution {
    public:
        struct Star;

        FindClosestKStars():
            Solution("EPI Chapter 11.4",
                     "Compute the k closest stars",
                     "Use a k size max heap.") { }

        ~FindClosestKStars() { }

        std::vector<Star> findClosestKStars(size_t k, std::istringstream *stars);

        bool test();

    };

  } // chapter11
} // epi

#endif /* SRC_EPI_CHAPTER11_FINDCLOSESTKSTARS_HPP_ */
