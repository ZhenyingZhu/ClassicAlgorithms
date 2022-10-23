#ifndef SRC_EPI_CHAPTER8_MERGETWOSORTEDLISTS_HPP_
#define SRC_EPI_CHAPTER8_MERGETWOSORTEDLISTS_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"
#include "../../ListNode.h"

#include <memory>

namespace epi {
  namespace chapter8 {

    class MergeTwoSortedLists : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        MergeTwoSortedLists():
            Solution("EPI Chapter 8.1",
                     "Merge two sorted lists",
                     "Pick the smaller node in two"
                     " lists to add to the new list.") { }

        ~MergeTwoSortedLists() { }

        std::shared_ptr<myutils::ListNode<int>> mergeTwoSortedLists(std::shared_ptr<myutils::ListNode<int>> list1,
                                                                    std::shared_ptr<myutils::ListNode<int>> list2);

        bool test();
    };

  } // chapter8
} // epi

#endif /* SRC_EPI_CHAPTER8_MERGETWOSORTEDLISTS_HPP_ */
