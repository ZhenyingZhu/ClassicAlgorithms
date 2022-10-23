#include "ReplaceAndRemove.hpp"

#include <assert.h>
#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::string;

namespace epi {
  namespace chapter7 {
    int ReplaceAndRemove::replaceAndRemove(int size, char s[]) {
        int p(0), resSize(size);

        for (int i = 0; i != size; ++i) {
            if (s[i] == 'b')
                --resSize;
            else {
                s[p++] = s[i];
                if (s[i] == 'a')
                    ++resSize;
            }
        }

        int writingPtr(resSize - 1);
        --p;
        for (; p >= 0; --p) {
            if (s[p] == 'a') {
                s[writingPtr--] = 'd';
                s[writingPtr--] = 'd';
            } else {
                s[writingPtr--] = s[p];
            }
        }

        return resSize;
    }

    bool ReplaceAndRemove::test() {
        char s[] = "acdbbca"; // ddcdcdd
        char result[] = "ddcdcdd";

        if (replaceAndRemove(7, s) != 7 && s != result) {
            cout << "Result string is: " << s << endl;
            return false;
        }


        return true;
    }

  } // chapter7
} // epi
