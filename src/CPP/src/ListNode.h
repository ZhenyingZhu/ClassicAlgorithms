#ifndef SRC_LISTNODE_H_
#define SRC_LISTNODE_H_

#include <memory>
#include <vector>

namespace myutils {
  template <typename T>
  struct ListNode {
      ListNode(): data() { }

      ListNode(const T &d): data(d) { }

      // Should return a deep copy of next rather than the pointer
//      ListNode(ListNode &copy): data(copy.data), next(copy.next) { }
//
//      ListNode& operator=(const ListNode &copy) {
//          data = copy.data;
//          next = copy.next;
//          return *this;
//      }

      T data;
      std::shared_ptr<ListNode<T>> next;
  };
} // myutils

#endif /* SRC_LISTNODE_H_ */
