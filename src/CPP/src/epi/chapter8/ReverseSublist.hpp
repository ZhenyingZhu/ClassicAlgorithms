#ifndef SRC_EPI_CHAPTER8_REVERSESUBLIST_HPP_
#define SRC_EPI_CHAPTER8_REVERSESUBLIST_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"
#include "../../ListNode.h"

#include <memory>

namespace epi {
  namespace chapter8 {

    class ReverseSublist : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        ReverseSublist():
            Solution("EPI Chapter 8.2",
                     "Reverse a single sublist",
                     "Move each node start from start"
                     " node to the next of finish node") { }

        ~ReverseSublist() { }

        std::shared_ptr<myutils::ListNode<int>> reverseSublist(std::shared_ptr<myutils::ListNode<int>> list,
                                                               int start, int finish);

        bool test();
    };

  } // chapter8
} // epi

#endif /* SRC_EPI_CHAPTER8_REVERSESUBLIST_HPP_ */
