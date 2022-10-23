#include "PhoneMnemonic.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <array>
#include <assert.h>

using std::string;
using std::vector;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter7 {
    const std::array<std::string, 10> PhoneMnemonic::kMapping_= {
            {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"}
    };

    string PhoneMnemonic::digitMapping(int num) {
        assert (num >= 0);
        assert (num < 10);

        return kMapping_[num];
    }

    void PhoneMnemonic::phoneMnemonicHelper(const string &phoneNumber,
                                           string &partialMnemonic,
                                           size_t mnemonicPos,
                                           vector<string> &vec) {
        if (mnemonicPos == phoneNumber.size()) {
            vec.push_back(string(partialMnemonic));
            return;
        }

        string seq = kMapping_[phoneNumber[mnemonicPos] - '0'];
        for (char c : seq) {
            string copy(partialMnemonic);
            copy[mnemonicPos] = c;
            phoneMnemonicHelper(phoneNumber, copy, mnemonicPos + 1, vec);
        }
    }

    vector<string> PhoneMnemonic::phoneMnemonic(const string &phoneNumber) {
        vector<string> res;

        string mnemonic(phoneNumber.size(), ' ');
        phoneMnemonicHelper(phoneNumber, mnemonic, 0, res);

        return res;
    }

    bool PhoneMnemonic::test() {
        string s1 = "23";
        vector<string> res = phoneMnemonic(s1);

        if (res.size() != 9) {
            cout << "Result should contains 9 strings. " << endl;
            for (string s : res) {
                cout << s << endl;
            }
        }

        return true;
    }

  } // chapter7
} // epi
