#include "RabinKarp.hpp"

#include <string>
#include <cmath>
#include <iostream>

using std::string;
using std::pow;
using std::cout;
using std::endl;

namespace {
  int BASE = 26;
}

namespace epi {
  namespace chapter7 {
    int RabinKarp::rabinKarp(const string &text, const string &search) {
        if (search.size() > text.size())
            return -1;

        // create rolling hash
        int tHash = 0, sHash = 0;
        for (size_t i = 0; i != search.size(); ++i) {
            tHash = tHash * BASE + text[i];
            sHash = sHash * BASE + search[i];
        }

        int mostLeftDigitWeight = pow(BASE, search.size() - 1);

        for (size_t i = search.size(); i < text.size(); ++i) {
            if (tHash == sHash && text.compare(i - search.size(), i, search) == 0)
                return i - search.size();

            // update rolling hash
            tHash -= text[i - search.size()] * mostLeftDigitWeight;
            tHash = tHash * BASE + text[i];
        }

        if (tHash == sHash && text.compare(text.size() - search.size(), text.size(), search) == 0)
            return text.size() - search.size();

        return -1;
    }

    bool RabinKarp::test() {
        string text("abcdefg");
        string search("efg");

        if (rabinKarp(text, search) != 4) {
            cout << "Find 'efg' in 'abcdefg' got index " << rabinKarp(text, search) << endl;
            return false;
        }

        return true;
    }
  } // chapter7
} // epi
