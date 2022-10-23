#ifndef SRC_EPI_CHAPTER13_FINDALLSUBSTRINGS_HPP_
#define SRC_EPI_CHAPTER13_FINDALLSUBSTRINGS_HPP_

#include "../../Solution.h"

#include <string>
#include <vector>
#include <unordered_map>

namespace epi {
  namespace chapter13 {
    class FindAllSubstrings : myutils::Solution {
    public:
        FindAllSubstrings():
            Solution("EPI Chapter 13.12",
                     "Compute all string decompositions",
                     "Given a list of N same length m strings, "
                     "find substrings from a n length sentence "
                     "that contain all these strings exactly "
                     "once. Check all substrings that have "
                     "the expected length.") { }

        ~FindAllSubstrings() { }

        std::vector<size_t> findAllSubstrings(const std::string &s, const std::vector<std::string> &words);

        bool test();

    private:
        bool checkSubstring(const std::string &s, std::unordered_map<std::string, size_t> &wordFreq,
                            size_t start, size_t wordLen, size_t wordNum);

    };

  } // chapter13
} // epi

#endif /* SRC_EPI_CHAPTER13_FINDALLSUBSTRINGS_HPP_ */
