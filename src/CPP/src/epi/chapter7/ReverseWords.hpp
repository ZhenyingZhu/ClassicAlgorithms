#ifndef SRC_EPI_CHAPTER7_REVERSEWORDS_HPP_
#define SRC_EPI_CHAPTER7_REVERSEWORDS_HPP_

#include <string>

#include "../../Solution.h"
#include "../../SmartPtr.h"

namespace epi {
  namespace chapter7 {

    class ReverseWords : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        ReverseWords():
            Solution("EPI Chapter 7.6",
                     "Reverse all the words in a sentence",
                     "First reverse words, then reverse the whole sentence.") { }

        bool test();

        ~ReverseWords() { }

        void reverseWords(std::string&);
    };

  } // chapter7
} // epi

#endif /* SRC_EPI_CHAPTER7_REVERSEWORDS_HPP_ */
