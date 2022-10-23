#ifndef SRC_EPI_CHAPTER10_RECONSTRUCTPREORDER_HPP_
#define SRC_EPI_CHAPTER10_RECONSTRUCTPREORDER_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <memory>
#include <vector>

#include "../../BinaryTreeNode.h"

namespace epi {
  namespace chapter10 {

    class ReconstructPreorder : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        ReconstructPreorder():
            Solution("EPI Chapter 10.13",
                     "Reconstruct a binary tree from a preorder traversal with markers",
                     "Use a static pointer to point to the current index"
                     " of the array. Use recursive call to add nodes.") { }

        ~ReconstructPreorder() { }

        std::unique_ptr<myutils::BinaryTreeNode<int>> reconstructPreorder(const std::vector<int*> &preorder);

        bool test();

    private:
        std::unique_ptr<myutils::BinaryTreeNode<int>> btConstructHelper(const std::vector<int*> &preorder, int &pos);
    };

  } // chapter10
} // epi

#endif /* SRC_EPI_CHAPTER10_RECONSTRUCTPREORDER_HPP_ */
