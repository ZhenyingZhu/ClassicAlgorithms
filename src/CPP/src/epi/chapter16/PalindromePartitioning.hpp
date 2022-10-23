#ifndef SRC_EPI_CHAPTER16_PALINDROMEPARTITIONING_HPP_
#define SRC_EPI_CHAPTER16_PALINDROMEPARTITIONING_HPP_

#include "../../Solution.h"

#include <vector>
#include <string>

namespace epi {
  namespace chapter16 {
    class PalindromePartitioning : public myutils::Solution {
    public:
        PalindromePartitioning():
            Solution("EPI Chapter 16.7",
                     "Generate palindromic decompositions",
                     "") { }

        ~PalindromePartitioning() { }

        std::vector<std::vector<std::string>> palindromePartitioning(const std::string &input);

        bool test();

    private:
        bool isPalindrome(const std::string &prefix);

        void partitioningHelper(const std::string &input, size_t offset,
                std::vector<std::string> &partitions, std::vector<std::vector<std::string>> &result);

    };

  } // chapter16
} // epi

#endif /* SRC_EPI_CHAPTER16_PALINDROMEPARTITIONING_HPP_ */
