#ifndef SRC_EPI_CHAPTER8_EVENODDMERGE_HPP_
#define SRC_EPI_CHAPTER8_EVENODDMERGE_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"
#include "../../ListNode.h"

#include <memory>

namespace epi {
  namespace chapter8 {

    class EvenOddMerge : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        EvenOddMerge():
            Solution("EPI Chapter 8.10",
                     "Implement even-odd merge",
                     "maintain two headers.") { }

        ~EvenOddMerge() { }

        std::shared_ptr<myutils::ListNode<int>> evenOddMerge(const std::shared_ptr<myutils::ListNode<int>> &list);


        bool test();
    };

  } // chapter8
} // epi

#endif /* SRC_EPI_CHAPTER8_EVENODDMERGE_HPP_ */
