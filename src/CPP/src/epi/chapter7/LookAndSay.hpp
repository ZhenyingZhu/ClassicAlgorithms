#ifndef SRC_EPI_CHAPTER7_LOOKANDSAY_HPP_
#define SRC_EPI_CHAPTER7_LOOKANDSAY_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <string>

namespace epi {
  namespace chapter7 {

    class LookAndSay : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        LookAndSay():
            Solution("EPI Chapter 7.8",
                     "The look-and-say problem",
                     "Do it n times.") {
        }

        ~LookAndSay() { }

        std::string lookAndSay(int n);

        bool test();
    private:
        std::string nextNumber(std::string &s);
    };

  } // chapter7
} // epi

#endif /* SRC_EPI_CHAPTER7_LOOKANDSAY_HPP_ */
