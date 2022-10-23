#ifndef SRC_EPI_CHAPTER7_RLE_HPP_
#define SRC_EPI_CHAPTER7_RLE_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <string>

namespace epi {
  namespace chapter7 {

    class RLE : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        RLE():
            Solution("EPI Chapter 7.12",
                     "Implement run-length encoding",
                     "encode converts a string with no digits from "
                     "'aabbb' to '2a3b', and decode do it reversely.") { }

        ~RLE() { }

        std::string encoding(const std::string &s);

        std::string decoding(const std::string &s);

        bool test();
    };

  } // chapter7
} // epi

#endif /* SRC_EPI_CHAPTER7_RLE_HPP_ */
