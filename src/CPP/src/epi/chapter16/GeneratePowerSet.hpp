#ifndef SRC_EPI_CHAPTER16_GENERATEPOWERSET_HPP_
#define SRC_EPI_CHAPTER16_GENERATEPOWERSET_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter16 {
    class GeneratePowerSet : public myutils::Solution {
    public:
        GeneratePowerSet():
            Solution("EPI Chapter 16.4",
                     "Generate power set",
                     "All possible subsets with entries from input. Use recursion.") { }

        ~GeneratePowerSet() { }

        std::vector<std::vector<int>> generatePowerSet(const std::vector<int> &array);

        bool test();

    private:
        void generatePowerSetHelper(const std::vector<int> &array, size_t pos,
                std::vector<int> &prevAdded, std::vector<std::vector<int>> &result);

    };

  } // chapter16
} // epi

#endif /* SRC_EPI_CHAPTER16_GENERATEPOWERSET_HPP_ */
