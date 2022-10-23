#ifndef SRC_EPI_CHAPTER9_STACKQUEUE_HPP_
#define SRC_EPI_CHAPTER9_STACKQUEUE_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <stack>

namespace epi {
  namespace chapter9 {

    class StackQueue : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        class Queue;

    public:
        StackQueue():
            Solution("EPI Chapter 9.9",
                     "Implement a queue using stacks",
                     "Use two stacks.") { }

        ~StackQueue() { }

        bool test();
    };

  } // chapter9
} // epi

#endif /* SRC_EPI_CHAPTER9_STACKQUEUE_HPP_ */
