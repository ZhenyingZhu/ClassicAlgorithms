#ifndef SRC_EPI_CHAPTER9_CIRCULARQUEUE_HPP_
#define SRC_EPI_CHAPTER9_CIRCULARQUEUE_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
  namespace chapter9 {

    class CircularQueue : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        class Queue;

    public:
        CircularQueue():
            Solution("EPI Chapter 9.8",
                     "Implement a circular queue",
                     "Use an vector to store elements. Two pointers indicate "
                     "start and end. When vector is full and need enque, resize.") { }

        ~CircularQueue() { }

        bool test();
    };

  } // chapter9
} // epi

#endif /* SRC_EPI_CHAPTER9_CIRCULARQUEUE_HPP_ */
