#ifndef SRC_EPI_CHAPTER8_OVERLAPPINGLISTS_HPP_
#define SRC_EPI_CHAPTER8_OVERLAPPINGLISTS_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"
#include "../../ListNode.h"

#include <memory>

namespace epi {
  namespace chapter8 {

    class OverlappingLists : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        OverlappingLists():
            Solution("EPI Chapter 8.5",
                     "Test for overlapping lists—lists may have cycles",
                     "Use the entrance of cycle as the end of the list.") { }

        ~OverlappingLists() { }

        std::shared_ptr<myutils::ListNode<int>> overlappingLists
          (std::shared_ptr<myutils::ListNode<int>> list1, std::shared_ptr<myutils::ListNode<int>> list2);

        bool test();

    private:
        std::shared_ptr<myutils::ListNode<int>> hasCycle(const std::shared_ptr<myutils::ListNode<int>> &list);
    };

  } // chapter8
} // epi

#endif /* SRC_EPI_CHAPTER8_OVERLAPPINGLISTS_HPP_ */
