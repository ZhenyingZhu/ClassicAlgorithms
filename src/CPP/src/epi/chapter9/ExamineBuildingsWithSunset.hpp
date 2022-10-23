#ifndef SRC_EPI_CHAPTER9_EXAMINEBUILDINGSWITHSUNSET_HPP_
#define SRC_EPI_CHAPTER9_EXAMINEBUILDINGSWITHSUNSET_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <stack>
#include <memory>

namespace epi {
  namespace chapter9 {

    class ExamineBuildingsWithSunset : public myutils::Solution {
        friend class myutils::SmartPtr;

    private:
        struct BuildingWithHeight;

    public:
        ExamineBuildingsWithSunset():
            Solution("EPI Chapter 9.6",
                     "Compute buildings with a sunset view",
                     "Use stack to record builds that can view sunset") { }

        ~ExamineBuildingsWithSunset() { }

        std::vector<int> examineBuildingsWithSunset(std::istringstream *sin);

        bool test();
    };

  } // chapter9
} // epi

#endif /* SRC_EPI_CHAPTER9_EXAMINEBUILDINGSWITHSUNSET_HPP_ */
