#ifndef SRC_EPI_CHAPTER8_REMOVEDUPLICATES_HPP_
#define SRC_EPI_CHAPTER8_REMOVEDUPLICATES_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"
#include "../../ListNode.h"

#include <memory>

namespace epi {
  namespace chapter8 {

    class RemoveDuplicates : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        RemoveDuplicates():
            Solution("EPI Chapter 8.8",
                     "Remove duplicates from a sorted list",
                     "Traverse until find another node that is different.") { }

        ~RemoveDuplicates() { }

        std::shared_ptr<myutils::ListNode<int>> removeDuplicates(const std::shared_ptr<myutils::ListNode<int>> &head);

        bool test();
    };

  } // chapter8
} // epi

#endif /* SRC_EPI_CHAPTER8_REMOVEDUPLICATES_HPP_ */
