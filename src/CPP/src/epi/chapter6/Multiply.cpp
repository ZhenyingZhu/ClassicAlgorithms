#include "Multiply.hpp"

#include <vector>
#include <iostream>
#include <algorithm>

#include "../../MyUtils.h"

using std::vector;
using std::cout;
using std::endl;
using std::reverse;
using myutils::vec_to_string;

namespace epi {
namespace chapter6 {
    vector<int> Multiply::multiply(vector<int> num1, vector<int> num2) {
        bool is_negative = (num1.front() < 0 && num2.front() >= 0)
                || (num1.front() >= 0 && num2.front() < 0);
        num1.front() = abs(num1.front()), num2.front() = abs(num2.front());
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> res(num1.size() + num2.size(), 0);
        for (vector<int>::size_type i = 0; i != num1.size(); ++i) {
            for (vector<int>::size_type j = 0; j != num2.size(); ++j) {
                res[i + j] += num1[i] * num2[j];
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        }

        // remove trailing 0
        while (res.size() != 1 && res.back() == 0)
            res.pop_back();

        reverse(res.begin(), res.end());
        if (is_negative)
            res.front() *= -1;

        return res;
    }

    int Multiply::convertVecToInt(const vector<int> &vec) {
        int res = 0;
        if (vec.size() == 0)
            return res;

        bool isNegative = vec.front() < 0;
        res = abs(vec.front());

        for (vector<int>::const_iterator iter = vec.begin() + 1; iter != vec.end(); ++iter)
            res = res * 10 + *iter;

        return isNegative ? -1 * res : res;
    }

    bool Multiply::test() {
        vector<int> num1 = { 9, 9, 9 };
        vector<int> num2 = { -9, 9 };
        int shouldBe = convertVecToInt(num1) * convertVecToInt(num2);
        vector<int> res = multiply(num1, num2);

        if ( shouldBe != convertVecToInt(res) ) {
            cout << vec_to_string(num1) << " * " << vec_to_string(num2)
                    << " = " << vec_to_string(res) << endl;
            cout << "Should be " << shouldBe << endl;

            return false;
        }

        return true;
    }
} // chapter6
} // epi
