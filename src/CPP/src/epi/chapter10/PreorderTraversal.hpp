#ifndef SRC_EPI_CHAPTER10_PREORDERTRAVERSAL_HPP_
#define SRC_EPI_CHAPTER10_PREORDERTRAVERSAL_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <memory>
#include <vector>

#include "../../BinaryTreeNode.h"

namespace epi {
  namespace chapter10 {

    class PreorderTraversal : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        PreorderTraversal():
            Solution("EPI Chapter 10.8",
                     "Implement a preorder traversal without recursion",
                     "Use a stack. Notice when push to stack, "
                     "first push right, then push left.") { }

        ~PreorderTraversal() { }

        std::vector<int> preorderTraversal(const std::unique_ptr<myutils::BinaryTreeNode<int>> &tree);

        bool test();

    private:
        struct Status;
    };

  } // chapter10
} // epi

#endif /* SRC_EPI_CHAPTER10_PREORDERTRAVERSAL_HPP_ */
