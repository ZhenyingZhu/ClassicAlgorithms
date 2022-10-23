#ifndef SRC_BINARYTREENODE_H_
#define SRC_BINARYTREENODE_H_

#include <climits>
#include <memory>
#include <iostream>

namespace myutils {
  const int BTNULL = INT_MAX;

  template <typename T>
  struct BinaryTreeNode {
      BinaryTreeNode(T d): data(d), parent(nullptr), size(0) { }

      ~BinaryTreeNode() {
          // cannot delete parent because it is another node which has unique_ptr points to
//          delete parent;
//          parent = nullptr;
      }

      T data;
      std::unique_ptr<BinaryTreeNode<T>> left, right;
      BinaryTreeNode<T> *parent;
      size_t size;
  };
} // myutils

#endif /* SRC_BINARYTREENODE_H_ */
