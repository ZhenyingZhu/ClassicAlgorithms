#ifndef SRC_EPI_CHAPTER8_OVERLAPPINGNOCYCLELISTS_HPP_
#define SRC_EPI_CHAPTER8_OVERLAPPINGNOCYCLELISTS_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"
#include "../../ListNode.h"

#include <memory>

namespace epi {
  namespace chapter8 {

    class OverlappingNoCycleLists : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        OverlappingNoCycleLists():
            Solution("EPI Chapter 8.4",
                     "Test for overlapping lists—lists are cycle-free",
                     "First count the list lengths. Then traverse the longer one first.") { }

        ~OverlappingNoCycleLists() { }

        std::shared_ptr<myutils::ListNode<int>> overlappingNoCycleLists
          (std::shared_ptr<myutils::ListNode<int>> list1, std::shared_ptr<myutils::ListNode<int>> list2);

        bool test();

    private:
        size_t listLen(const std::shared_ptr<myutils::ListNode<int>> &list);
    };

  } // chapter8
} // epi

#endif /* SRC_EPI_CHAPTER8_OVERLAPPINGNOCYCLELISTS_HPP_ */
