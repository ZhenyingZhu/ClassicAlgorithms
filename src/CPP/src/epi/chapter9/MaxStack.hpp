#ifndef SRC_EPI_CHAPTER9_MAXSTACK_HPP_
#define SRC_EPI_CHAPTER9_MAXSTACK_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <stack>

namespace epi {
  namespace chapter9 {

    class MaxStack : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        MaxStack():
            Solution("EPI Chapter 9.1",
                     "Implement a stack with max API",
                     "Push same or larger value to another private stack.") { }

        ~MaxStack() { }

        int max() const;

        bool empty() const;

        void push(int);

        int pop();

        int top() const;

        bool test();

    private:
        std::stack<int> elements_;
        std::stack<int> maxes_;
    };

  } // chapter9
} // epi

#endif /* SRC_EPI_CHAPTER9_MAXSTACK_HPP_ */
