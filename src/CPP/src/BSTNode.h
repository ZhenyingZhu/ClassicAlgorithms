#ifndef SRC_BSTNODE_H_
#define SRC_BSTNODE_H_

#include <climits>
#include <memory>

namespace myutils {
  const int BST_INT_NULL = INT_MAX;

  template <typename T>
  struct BSTNode {
      BSTNode(T d): data(d) { }

      ~BSTNode() { }

      T data;
      std::unique_ptr<BSTNode<T>> left, right;
  };
} // myutils

#endif /* SRC_BSTNODE_H_ */
