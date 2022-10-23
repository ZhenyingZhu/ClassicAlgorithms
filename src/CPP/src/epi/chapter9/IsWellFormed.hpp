#ifndef SRC_EPI_CHAPTER9_ISWELLFORMED_HPP_
#define SRC_EPI_CHAPTER9_ISWELLFORMED_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <stack>
#include <string>

namespace epi {
  namespace chapter9 {

    class IsWellFormed : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        IsWellFormed():
            Solution("EPI Chapter 9.3",
                     "Test a string over {,},(,),[,] for well-formedness",
                     "Check the top is match with the income char. "
                     "Check at the end the stack is empty.") { }

        ~IsWellFormed() { }

        bool isWellFormed(const std::string &s);

        bool test();
    };

  } // chapter9
} // epi

#endif /* SRC_EPI_CHAPTER9_ISWELLFORMED_HPP_ */
