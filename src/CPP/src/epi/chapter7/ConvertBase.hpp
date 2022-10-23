#ifndef SRC_EPI_CHAPTER7_CONVERTBASE_HPP_
#define SRC_EPI_CHAPTER7_CONVERTBASE_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <string>

namespace epi {
  namespace chapter7 {

    class ConvertBase : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        ConvertBase():
            Solution("EPI Chapter 7.2",
                     "Base conversion",
                     "First convert to base 10, and then convert to result.") { }

        bool test();

        ~ConvertBase() { }

        std::string convertBase(const std::string &s, int b1, int b2);

    private:
        std::string constructFromBase(int x, int base);
    };

  } // chapter7
} // epi

#endif /* SRC_EPI_CHAPTER7_CONVERTBASE_HPP_ */
