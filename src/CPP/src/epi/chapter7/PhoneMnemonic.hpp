#ifndef SRC_EPI_CHAPTER7_PHONEMNEMONIC_HPP_
#define SRC_EPI_CHAPTER7_PHONEMNEMONIC_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <string>
#include <vector>
#include <array>

namespace epi {
  namespace chapter7 {

    class PhoneMnemonic : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        PhoneMnemonic():
            Solution("EPI Chapter 7.7",
                     "Compute all mnemonics for a phone number",
                     "Use recursive.") {
        }

        bool test();

        ~PhoneMnemonic() { }

        std::vector<std::string> phoneMnemonic(const std::string &phoneNumber);

    private:
        std::string digitMapping(int num);

        void phoneMnemonicHelper(const std::string &phoneNumber,
                                 std::string &partialMnemonic,
                                 size_t mnemonicPos,
                                 std::vector<std::string> &vec);

        const static std::array<std::string, 10> kMapping_;
    };

  } // chapter7
} // epi

#endif /* SRC_EPI_CHAPTER7_PHONEMNEMONIC_HPP_ */
