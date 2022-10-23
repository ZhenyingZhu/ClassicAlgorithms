#ifndef SRC_EPI_CHAPTER8_REMOVEKTHLAST_HPP_
#define SRC_EPI_CHAPTER8_REMOVEKTHLAST_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"
#include "../../ListNode.h"

#include <memory>

namespace epi {
  namespace chapter8 {

    class RemoveKthLast : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        RemoveKthLast():
            Solution("EPI Chapter 8.7",
                     "Remove the kth last element from a list",
                     "Use two pointers. One move k steps first.") { }

        ~RemoveKthLast() { }

        std::shared_ptr<myutils::ListNode<int>> removeKthLast(const std::shared_ptr<myutils::ListNode<int>> &head, size_t k);

        bool test();
    };

  } // chapter8
} // epi

#endif /* SRC_EPI_CHAPTER8_REMOVEKTHLAST_HPP_ */
