#ifndef SRC_EPI_CHAPTER8_CYCLICALLYRIGHTSHIFTLIST_HPP_
#define SRC_EPI_CHAPTER8_CYCLICALLYRIGHTSHIFTLIST_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"
#include "../../ListNode.h"

#include <memory>

namespace epi {
  namespace chapter8 {

    class CyclicallyRightShiftList : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        CyclicallyRightShiftList():
            Solution("EPI Chapter 8.9",
                     "Implement cyclic right shift for singly linked lists",
                     "Right shift the list (length n) by k mod n nodes.") { }

        ~CyclicallyRightShiftList() { }

        std::shared_ptr<myutils::ListNode<int>> cyclicallyRightShiftList
          (const std::shared_ptr<myutils::ListNode<int>> &head, unsigned k);

        bool test();
    };

  } // chapter8
} // epi

#endif /* SRC_EPI_CHAPTER8_CYCLICALLYRIGHTSHIFTLIST_HPP_ */
