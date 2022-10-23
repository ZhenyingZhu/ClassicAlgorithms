#include "GeneratePascalTriangle.hpp"

#include <vector>
#include <iostream>

#include "../../MyUtils.h"

using std::vector;
using std::cout;
using std::endl;
using myutils::matrix_to_string;

namespace epi {
  namespace chapter6 {
    vector< vector<int> > GeneratePascalTriangle::generatePascalTriangle(unsigned numRows) {
        vector< vector<int> > pascalTriangle;

        for (unsigned row = 0; row != numRows; ++row) {
            vector<int> pascalRow;
            for (unsigned i = 0; i != row + 1; ++i) {
                if (i == 0 || i == row)
                    pascalRow.push_back(1);
                else
                    pascalRow.push_back( pascalTriangle.back()[i - 1] + pascalTriangle.back()[i] );
            }
            pascalTriangle.push_back(pascalRow);
        }

        return pascalTriangle;
    }

    int GeneratePascalTriangle::combine(unsigned m, unsigned n) {
        int res = 1;

        for (unsigned i = m - n + 1; i != m + 1; ++i)
            res *= i;

        for (unsigned i = 1; i != n + 1; ++i)
            res /= i;

        return res;
    }

    vector< vector<int> > GeneratePascalTriangle::generatePascalTriangleMath(unsigned numRows) {
        vector< vector<int> > pascalTriangle;

        for (unsigned i = 0; i != numRows; ++i) {
            vector<int> pascalRow;
            for (unsigned j = 0; j != i + 1; ++j) {
                if (j > (i + 1) / 2)
                    pascalRow.push_back(  pascalRow[i - j] );
                else
                    pascalRow.push_back( combine(i, j) );
            }
            pascalTriangle.push_back(pascalRow);
        }

        return pascalTriangle;
    }

    bool GeneratePascalTriangle::test() {
        vector<vector<int>> shouldBe = generatePascalTriangleMath(5);
        vector<vector<int>> res = generatePascalTriangle(5);

        if (shouldBe != res) {
            cout << "Should be: " << endl;
            cout << matrix_to_string(shouldBe) << endl;
            cout << "Result: " << endl;
            cout << matrix_to_string(res) << endl;

            return false;
        }

        return true;
    }

  } // chapter6
} // epi
