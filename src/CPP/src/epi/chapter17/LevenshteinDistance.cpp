#include "LevenshteinDistance.hpp"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::string;
using std::min;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter17 {
    size_t LevenshteinDistance::levenshteinDistance(const string &str1, const string &str2) {
        vector<vector<size_t>> strIToStrJ( str1.size() + 1, vector<size_t>(str2.size() + 1) );
        for (size_t i = 0; i != strIToStrJ.size(); ++i)
            strIToStrJ[i][0] = i;
        for (size_t j = 1; j != strIToStrJ[0].size(); ++j)
            strIToStrJ[0][j] = j;

        for (size_t i = 0; i != str1.size(); ++i) {
            for (size_t j = 0; j != str2.size(); ++j) {
                if (str1[i] == str2[j]) {
                    strIToStrJ[i + 1][j + 1] = strIToStrJ[i][j];
                    continue;
                }

                size_t minSteps = min( strIToStrJ[i][j], min(strIToStrJ[i][j + 1], strIToStrJ[i + 1][j]) ) + 1;
                strIToStrJ[i + 1][j + 1] = minSteps;
            }
        }

        return strIToStrJ[str1.size()][str2.size()];
    }

    bool LevenshteinDistance::test() {
        string str1("Saturday"), str2("Sundays");

        size_t res = levenshteinDistance(str1, str2);

        if (res != 4) {
            cout << "Should be: 4" << endl;
            cout << "Result: " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter17
} // epi
