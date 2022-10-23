/*
 * FindSuccessor.hpp
 *
 *  Created on: Jun 4, 2016
 *      Author: zhu91
 */

#ifndef SRC_EPI_CHAPTER10_FINDSUCCESSOR_HPP_
#define SRC_EPI_CHAPTER10_FINDSUCCESSOR_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <memory>
#include <vector>

#include "../../BinaryTreeNode.h"

namespace epi {
  namespace chapter10 {

    class FindSuccessor : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        FindSuccessor():
            Solution("EPI Chapter 10.10",
                     "Compute the inorder successor",
                     "Nodes have parent pointer. If this node doesn't have "
                     "right child, successor is its parent; otherwise is its"
                     " left most node of its right subtree.") { }

        ~FindSuccessor() { }

        myutils::BinaryTreeNode<int>* findSuccessor(const std::unique_ptr<myutils::BinaryTreeNode<int>> &node);

        bool test();
    };

  } // chapter10
} // epi

#endif /* SRC_EPI_CHAPTER10_FINDSUCCESSOR_HPP_ */
