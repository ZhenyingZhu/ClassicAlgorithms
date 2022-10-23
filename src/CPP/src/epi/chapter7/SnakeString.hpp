#ifndef SRC_EPI_CHAPTER7_SNAKESTRING_HPP_
#define SRC_EPI_CHAPTER7_SNAKESTRING_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <string>

namespace epi {
  namespace chapter7 {

    class SnakeString : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        SnakeString():
            Solution("EPI Chapter 7.11",
                     "Write a string sinusoidally",
                     "In a snake shape. Start from middle line, "
                     "go first to upper line then lower line.") { }

        ~SnakeString() { }

        std::string snakeString(const std::string &s);

        bool test();
    };

  } // chapter7
} // epi

#endif /* SRC_EPI_CHAPTER7_SNAKESTRING_HPP_ */
