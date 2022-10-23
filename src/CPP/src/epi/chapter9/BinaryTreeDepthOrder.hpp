#ifndef SRC_EPI_CHAPTER9_BINARYTREEDEPTHORDER_HPP_
#define SRC_EPI_CHAPTER9_BINARYTREEDEPTHORDER_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include "../../BinaryTreeNode.h"
#include <stack>
#include <memory>

namespace epi {
  namespace chapter9 {

    class BinaryTreeDepthOrder : public myutils::Solution {
        friend class myutils::SmartPtr;

//    private:
//        template <typename T>
//        struct BinaryTreeNode {
//            T data;
//            std::unique_ptr<BinaryTreeNode<T>> left;
//            std::unique_ptr<BinaryTreeNode<T>> right;
//        };

    public:
        BinaryTreeDepthOrder():
            Solution("EPI Chapter 9.7",
                     "Compute binary tree nodes in order of increasing depth",
                     "Return a vector that contains vectors that have node value "
                     "of same levels. Use two queues to record level i and level i + 1.") { }

        ~BinaryTreeDepthOrder() { }

        std::vector<std::vector<int>> binaryTreeDepthOrder(const std::unique_ptr<myutils::BinaryTreeNode<int>> &tree);

        bool test();
    };

  } // chapter9
} // epi

#endif /* SRC_EPI_CHAPTER9_BINARYTREEDEPTHORDER_HPP_ */
