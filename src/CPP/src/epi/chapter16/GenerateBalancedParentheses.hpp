#ifndef SRC_EPI_CHAPTER16_GENERATEBALANCEDPARENTHESES_HPP_
#define SRC_EPI_CHAPTER16_GENERATEBALANCEDPARENTHESES_HPP_

#include "../../Solution.h"

#include <vector>
#include <string>

namespace epi {
  namespace chapter16 {
    class GenerateBalancedParentheses : public myutils::Solution {
    public:
        GenerateBalancedParentheses():
            Solution("EPI Chapter 16.6",
                     "Generate strings of matched parens",
                     "For right each paren, can add at this time, or add at next time, "
                     "unless it has a left paren already. So to create a recursive, "
                     "add left paren when available, then call recursive; add right paren "
                     "when available, then call recursive make the program walk through "
                     "all possibility.") { }

        ~GenerateBalancedParentheses() { }

        std::vector<std::string> generateBalancedParentheses(size_t k);

        bool test();

    private:
        void parenthesesHelper(size_t left, size_t right, const std::string &prefix, std::vector<std::string> &result);

    };

  } // chapter16
} // epi

#endif /* SRC_EPI_CHAPTER16_GENERATEBALANCEDPARENTHESES_HPP_ */
