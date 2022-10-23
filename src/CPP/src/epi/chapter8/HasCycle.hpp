#ifndef SRC_EPI_HASCYCLE_HPP_
#define SRC_EPI_HASCYCLE_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"
#include "../../ListNode.h"

#include <memory>

namespace epi {
  namespace chapter8 {

    class HasCycle : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        HasCycle():
            Solution("EPI Chapter 8.3",
                     "Test for cyclicity",
                     "fast and slow pointers") { }

        ~HasCycle() { }

        std::shared_ptr<myutils::ListNode<int>> hasCycle(const std::shared_ptr<myutils::ListNode<int>> &head);

        bool test();
    };

  } // chapter8
} // epi

#endif /* SRC_EPI_HASCYCLE_HPP_ */
