#ifndef SRC_EPI_CHAPTER9_EVAL_HPP_
#define SRC_EPI_CHAPTER9_EVAL_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <stack>
#include <string>

namespace epi {
  namespace chapter9 {

    class Eval : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        Eval():
            Solution("EPI Chapter 9.2",
                     "Evaluate RPN(Reverse Polish notation) expressions",
                     "Use a stack to record operants. When an "
                     "operator shows, pop two operants.") { }

        ~Eval() { }

        int eval(const std::string &RpnExpression);

        bool test();
    };

  } // chapter9
} // epi

#endif /* SRC_EPI_CHAPTER9_EVAL_HPP_ */
