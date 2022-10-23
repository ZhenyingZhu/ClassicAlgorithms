#ifndef SRC_EPI_CHAPTER15_RANGELOOKUPINBST_HPP_
#define SRC_EPI_CHAPTER15_RANGELOOKUPINBST_HPP_

#include "../../Solution.h"
#include "../../BSTNode.h"

#include <memory>
#include <vector>

namespace epi {
  namespace chapter15 {
    class RangeLookupInBST : public myutils::Solution {
    public:
        struct Interval;

        RangeLookupInBST():
            Solution("EPI Chapter 15.12",
                     "The range lookup problem",
                     "Recursive call to check if root is in the range.") { }

        ~RangeLookupInBST() { }

        std::vector<int> rangeLookupInBST(const std::unique_ptr<myutils::BSTNode<int>> &tree, const Interval &interval);

        bool test();

    private:
        void rangeLookupInBSTHelper(const std::unique_ptr<myutils::BSTNode<int>> &root, int st, int ed, std::vector<int> &result);

    };

  } // chapter15
} // epi

#endif /* SRC_EPI_CHAPTER15_RANGELOOKUPINBST_HPP_ */
