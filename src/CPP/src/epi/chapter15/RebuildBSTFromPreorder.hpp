#ifndef SRC_EPI_CHAPTER15_REBUILDBSTFROMPREORDER_HPP_
#define SRC_EPI_CHAPTER15_REBUILDBSTFROMPREORDER_HPP_

#include "../../Solution.h"
#include "../../BSTNode.h"

#include <memory>
#include <vector>

namespace epi {
  namespace chapter15 {
    class RebuildBSTFromPreorder : public myutils::Solution {
    public:
        RebuildBSTFromPreorder():
            Solution("EPI Chapter 15.5",
                     "Reconstruct a BST from unique traversal preorder data",
                     "Use a static pointer points to preorder vector elements. "
                     "If the current element is added to the tree, pointer "
                     "move on, otherwise stay and return a nullptr.") { }

        ~RebuildBSTFromPreorder() { }

        std::unique_ptr<myutils::BSTNode<int>> rebuildBSTFromPreorder(const std::vector<int> &preorderSeq);

        bool test();

    private:
        std::unique_ptr<myutils::BSTNode<int>> preorderBSTHelper(const std::vector<int> &preorderSeq,
                size_t &pos, int lowerBound, int higherBound);

        void inPreOrderTraverse(const std::unique_ptr<myutils::BSTNode<int>> &tree, std::vector<int> &inorder, std::vector<int> &preorder);
    };

  } // chapter15
} // epi

#endif /* SRC_EPI_CHAPTER15_REBUILDBSTFROMPREORDER_HPP_ */
