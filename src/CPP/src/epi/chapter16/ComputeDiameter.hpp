#ifndef SRC_EPI_CHAPTER16_COMPUTEDIAMETER_HPP_
#define SRC_EPI_CHAPTER16_COMPUTEDIAMETER_HPP_

#include "../../Solution.h"

#include <vector>
#include <memory>

namespace epi {
  namespace chapter16 {
    class ComputeDiameter : public myutils::Solution {
    public:
        struct TreeNode;

        ComputeDiameter():
            Solution("EPI Chapter 16.11",
                     "Compute the diameter of a tree with weight on edges",
                     "Diameter is the max distance between two leaves. Traverse all the children. "
                     "One child could has the largest diameter. Otherwise the sum of distances to "
                     "two farthest leaves is the diameter.") { }

        ~ComputeDiameter() { }

        double computeDiameter(const std::unique_ptr<TreeNode> &tree);

        bool test();

    private:
        double diameterHelper(const std::unique_ptr<TreeNode> &node, double &maxDiameter);

    };

  } // chapter16
} // epi

#endif /* SRC_EPI_CHAPTER16_COMPUTEDIAMETER_HPP_ */
