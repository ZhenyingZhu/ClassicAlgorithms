#ifndef SRC_EPI_CHAPTER8_LISTPIVOTING_HPP_
#define SRC_EPI_CHAPTER8_LISTPIVOTING_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"
#include "../../ListNode.h"

#include <memory>

namespace epi {
  namespace chapter8 {

    class ListPivoting : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        ListPivoting():
            Solution("EPI Chapter 8.12",
                     "Implement list pivoting",
                     "Maintain three lists.") { }

        ~ListPivoting() { }

        std::shared_ptr<myutils::ListNode<int>> listPivoting
          (const std::shared_ptr<myutils::ListNode<int>> &list, int k);

        bool test();
    };

  } // chapter8
} // epi

#endif /* SRC_EPI_CHAPTER8_LISTPIVOTING_HPP_ */
