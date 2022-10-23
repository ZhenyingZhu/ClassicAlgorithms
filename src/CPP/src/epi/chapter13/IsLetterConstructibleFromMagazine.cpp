#include "IsLetterConstructibleFromMagazine.hpp"

#include <string>
#include <unordered_map>
#include <cctype>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include "../../MyUtils.h"

using std::string;
using std::unordered_map;
using std::isalnum;
using std::runtime_error;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter13 {
    bool IsLetterConstructibleFromMagazine::isLetterConstructibleFromMagazine(const string &letter, const string &magazine) {
        unordered_map<char, int> wordFreq;
        for (char c : letter) {
            if (isalnum(c))
                ++wordFreq[c];
        }

        for (char c : magazine) {
            if (!isalnum(c))
                continue;

            unordered_map<char, int>::iterator it = wordFreq.find(c);
            if (it != wordFreq.cend()) {
                --it->second;
                if (it->second == 0) {
                    wordFreq.erase(it);
                }

                if (wordFreq.empty())
                    return true;
            }
        }

        return false;
    }

    bool IsLetterConstructibleFromMagazine::test() {
        string letter("apple pie");
        string magazine("a p p l e p i e");

        if (!isLetterConstructibleFromMagazine(letter, magazine)) {
            cout << "Should be able to construct " << letter << endl;
            cout << "Result cannot" << endl;
            return false;
        }

        return true;
    }

  } // chapter13
} // epi
