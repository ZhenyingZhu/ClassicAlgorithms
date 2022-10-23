#ifndef SRC_EPI_CHAPTER11_STACKBYHEAP_HPP_
#define SRC_EPI_CHAPTER11_STACKBYHEAP_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>
#include <sstream>

namespace epi {
  namespace chapter11 {
    class StackByHeap : myutils::Solution {
    public:
        class Stack;

        StackByHeap():
            Solution("EPI Chapter 11.7",
                     "Implement a stack API using a heap",
                     "The element is the value with a timestamp. "
                     "So when pop, pop the lastest one.") { }

        ~StackByHeap() { }

        bool test();

    };

  } // chapter11
} // epi

#endif /* SRC_EPI_CHAPTER11_STACKBYHEAP_HPP_ */
