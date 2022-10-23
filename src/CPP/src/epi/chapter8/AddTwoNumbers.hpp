#ifndef SRC_EPI_CHAPTER8_ADDTWONUMBERS_HPP_
#define SRC_EPI_CHAPTER8_ADDTWONUMBERS_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"
#include "../../ListNode.h"

#include <memory>

namespace epi {
  namespace chapter8 {

    class AddTwoNumbers : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        AddTwoNumbers():
            Solution("EPI Chapter 8.13",
                     "Add list-based integers",
                     "LSD is the head of the list. "
                     "Use a variable to record carry over.") { }

        ~AddTwoNumbers() { }

        std::shared_ptr<myutils::ListNode<int>> addTwoNumbers
          (std::shared_ptr<myutils::ListNode<int>> list1, std::shared_ptr<myutils::ListNode<int>> list2);

        bool test();
    };

  } // chapter8
} // epi

#endif /* SRC_EPI_CHAPTER8_ADDTWONUMBERS_HPP_ */
