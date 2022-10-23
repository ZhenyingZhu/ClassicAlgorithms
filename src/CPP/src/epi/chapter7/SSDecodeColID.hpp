#ifndef SRC_EPI_CHAPTER7_SSDECODECOLID_HPP_
#define SRC_EPI_CHAPTER7_SSDECODECOLID_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <string>

namespace epi {
  namespace chapter7 {

    class SSDecodeColID : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        SSDecodeColID():
            Solution("EPI Chapter 7.3",
                     "Compute the spreadsheet column encoding",
                     "A means 1 and ZA mean 27. It is 26 base to 10 base convert") { }

        bool test();

        ~SSDecodeColID() { }

        int sSDecodeColID(const std::string &col);
    };

  } // chapter7
} // epi

#endif /* SRC_EPI_CHAPTER7_SSDECODECOLID_HPP_ */
