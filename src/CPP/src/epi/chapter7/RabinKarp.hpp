#ifndef SRC_EPI_CHAPTER7_RABINKARP_HPP_
#define SRC_EPI_CHAPTER7_RABINKARP_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <string>

namespace epi {
  namespace chapter7 {

    class RabinKarp : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        RabinKarp():
            Solution("EPI Chapter 7.13",
                     "Find the first occurrence of a substring",
                     "Use a rolling hash on each substring.") { }

        ~RabinKarp() { }

        int rabinKarp(const std::string &text, const std::string &search);

        bool test();
    };

  } // chapter7
} // epi

#endif /* SRC_EPI_CHAPTER7_RABINKARP_HPP_ */
