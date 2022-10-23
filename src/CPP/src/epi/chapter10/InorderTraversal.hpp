#ifndef SRC_EPI_CHAPTER10_INORDERTRAVERSAL_HPP_
#define SRC_EPI_CHAPTER10_INORDERTRAVERSAL_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <memory>
#include <vector>

#include "../../BinaryTreeNode.h"

namespace epi {
  namespace chapter10 {

    class InorderTraversal : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        InorderTraversal():
            Solution("EPI Chapter 10.11",
                     "Implement an inorder traversal with O(1) space",
                     "Node has its parent pointer. Use a prev ptr indicate "
                     "where does traverse come from(3 cases). Use a next ptr "
                     "to predict where should go based on if nodes have left/right child(2 cases).") { }

        ~InorderTraversal() { }

        std::vector<int> inorderTraversal(const std::unique_ptr<myutils::BinaryTreeNode<int>> &tree);

        bool test();
    };

  } // chapter10
} // epi

#endif /* SRC_EPI_CHAPTER10_INORDERTRAVERSAL_HPP_ */
