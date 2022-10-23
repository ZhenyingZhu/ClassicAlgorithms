#ifndef SRC_EPI_CHAPTER22_WEAKPTRUSAGE_HPP_
#define SRC_EPI_CHAPTER22_WEAKPTRUSAGE_HPP_

#include "../../Solution.h"

namespace epi {
  namespace chapter22 {
    class WeakPtrUsage : public myutils::Solution {
    public:
        struct Cycle1;
        
        struct Cycle2;

        WeakPtrUsage():
            Solution("EPI Chapter 22.3",
                     "Refer to an object that is held by shared_ptr but shouldn't participate in reference count.",
                     "It is used to solve reference cycle.") { }

        ~WeakPtrUsage() { }

        bool test();

    };

  } // chapter22
} // epi

#endif /* SRC_EPI_CHAPTER22_WEAKPTRUSAGE_HPP_ */
