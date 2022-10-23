#ifndef SRC_EPI_CHAPTER17_DECOMPOSEINTODICTIONARYWORDS_HPP_
#define SRC_EPI_CHAPTER17_DECOMPOSEINTODICTIONARYWORDS_HPP_

#include "../../Solution.h"

#include <vector>
#include <string>
#include <unordered_set>

namespace epi {
  namespace chapter17 {
    class DecomposeIntoDictionaryWords : public myutils::Solution {
    public:
        DecomposeIntoDictionaryWords():
            Solution("EPI Chapter 17.7",
                     "The BEDBATHANDBEYOND.COM problem",
                     "Use an array to record the length of each substring. For every char, "
                     "check backward to see if a substring end at this char is in the dictionary"
                     " and the previous chars have length in array.") { }

        ~DecomposeIntoDictionaryWords() { }

        std::vector<std::string> decomposeIntoDictionaryWords
               (const std::string &domain, const std::unordered_set<std::string> &dictionary);

        bool test();

    };

  } // chapter17
} // epi

#endif /* SRC_EPI_CHAPTER17_DECOMPOSEINTODICTIONARYWORDS_HPP_ */
