#include "PlusOne.hpp"

#include <vector>
#include <iostream>

#include "../../MyUtils.h"

using std::vector;
using std::cout; 
using std::endl; 

using myutils::vec_to_string;

namespace epi {
namespace chapter6 {
    vector<int> PlusOne::generateVectorFromNum(int num) {
        vector<int> res;
        while (num) {
            res.insert(res.begin(), num % 10);
            num /= 10;
        }

        return res;

    }

    vector<int> PlusOne::plusOneBruteForce(vector<int> A) {
        int origin(0);
        for (vector<int>::const_iterator iter = A.begin(); iter != A.end(); ++iter) {
            origin = origin * 10 + *iter;
        }

        origin += 1;
        return generateVectorFromNum(origin);
    }

    vector<int> PlusOne::plusOne(vector<int> A) {
        if (A.size() == 0) {
            vector<int> res = {1};
            return res;
        }
        ++A.back();
        for (vector<int>::iterator iter = --A.end(); iter != A.begin() && *iter == 10; --iter) {
            *iter = 0;
            ++*(iter - 1);
        }

        if (*A.begin() == 10) {
            *A.begin() = 0;
            A.insert(A.begin(), 1);
        }

        return A;
    }

    bool PlusOne::test() {
        for (int i = 0; i != 131; ++i) {
            vector<int> input = generateVectorFromNum(i);

            vector<int> shouldBe = plusOneBruteForce(input);
            vector<int> res = plusOne(input);

            if (res != shouldBe) {
                cout << "Increase " << vec_to_string(input)
                        << " by one is " << vec_to_string(res)
                        << endl;
                return false;
            }
        }

        return true;
    }

} // chapter6
} // epi
