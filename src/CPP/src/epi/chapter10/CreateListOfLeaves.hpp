#ifndef SRC_EPI_CHAPTER10_CREATELISTOFLEAVES_HPP_
#define SRC_EPI_CHAPTER10_CREATELISTOFLEAVES_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <memory>
#include <list>

#include "../../BinaryTreeNode.h"

namespace epi {
  namespace chapter10 {

    class CreateListOfLeaves : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        CreateListOfLeaves():
            Solution("EPI Chapter 10.14",
                     "Form a linked list from the leaves of a binary tree",
                     "Use recursive call to traverse. If the node doesn't "
                     "have left and right child, append to the list.") { }

        ~CreateListOfLeaves() { }

        std::list< const std::unique_ptr<myutils::BinaryTreeNode<int>>* > createListOfLeaves(
                const std::unique_ptr<myutils::BinaryTreeNode<int>> &tree);

        bool test();

    private:
        void traverseLeavesHelper(
                const std::unique_ptr<myutils::BinaryTreeNode<int>> &node,
                std::list< const std::unique_ptr<myutils::BinaryTreeNode<int>>* > &list);
    };

  } // chapter10
} // epi

#endif /* SRC_EPI_CHAPTER10_CREATELISTOFLEAVES_HPP_ */
