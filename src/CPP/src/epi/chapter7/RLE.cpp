#include "RLE.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::string;
using std::to_string;
using std::vector;
using std::cout;
using std::endl;
using std::invalid_argument;

namespace epi {
  namespace chapter7 {
    string RLE::encoding(const string &s) {
        string res("");

        size_t i = 0;
        while (i < s.size()) {
            if (!isalpha(s[i]))
                throw invalid_argument("Encode invalid char: " + s[i]);

            size_t j = i, cnt = 0;
            for (; j < s.size() && s[j] == s[i]; ++j) {
                ++cnt;
            }

            res += to_string(cnt) + s[i];
            i = j;
        }

        return res;
    }

    string RLE::decoding(const string &s) {
        string res("");

        size_t i = 0;
        while (i < s.size()) {
            size_t j = i, cnt = 0;

            for (;j < s.size() && isdigit(s[j]); ++j) {
                cnt = cnt * 10 + s[j] - '0';
                if (cnt == 0)
                    throw invalid_argument("A char with 0 count");
            }

            if ( !isalpha(s[j]) )
                throw invalid_argument("Decode invalid char: " + s[j]);

            res += string(cnt, s[j]);
            i = j + 1;
        }

        return res;
    }

    bool RLE::test() {
        vector<string> vec = {"aabbb", "abaab", string(11, 'a')};

        for (string s : vec) {
            string cs = encoding(s);
            string ds = decoding(cs);
            if (ds != s) {
                cout << "Origin: " << s << endl;
                cout << "Encoded: " << cs << endl;
                cout << "Decoded: " << ds << endl;
                return false;
            }
        }

        return true;
    }

  } // chapter7
} // epi
