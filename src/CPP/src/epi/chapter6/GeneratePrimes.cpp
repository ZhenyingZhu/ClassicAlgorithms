#include "GeneratePrimes.hpp"

#include <vector>
#include <iostream>
#include <math.h>

#include "../../MyUtils.h"

using std::vector;
using std::cout;
using std::endl;
using myutils::vec_to_string;

namespace epi {
namespace chapter6 {

    vector<int> GeneratePrimes::generatePrimesBruteForce(int n) {
        vector<int> res;
        if (n < 2)
            return res;

        for (int i = 2; i != n + 1; ++i) {
            bool isPrime = true;

            for (int j = 2; j <= sqrt(i); ++j) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime)
                res.push_back(i);
        }

        return res;
    }

    int GeneratePrimes::idxToNum(int idx) {
        return (idx + 1) * 2 + 1;
    }

    int GeneratePrimes::numToIdx(int num) {
        return num / 2 - 1;
    }

    vector<int> GeneratePrimes::generatePrimes(int n) {
        vector<int> res;
        if (n < 2)
            return res;

        res.push_back(2);

        // present 3, 5, 7, 9 ...
        int size = n % 2 == 0 ? n / 2 - 1 : n / 2;
        vector<bool> isPrimes(size, true);

        for (int i = 0; i != static_cast<int>( isPrimes.size() ); ++i) {
            if (!isPrimes[i])
                continue;

            int num = idxToNum(i);
            res.push_back(num);

            // if not 2*num, then j could be an even number
            for (int j = num * num; j <= n; j += 2 * num) {
                isPrimes[numToIdx(j)] = false;
            }
        }

        return res;
    }

    bool GeneratePrimes::test() {
        for (int n = 97; n != 101; ++n) {
            vector<int> shouldBe = generatePrimesBruteForce(n);
            vector<int> result = generatePrimes(n);

            if (shouldBe != result) {
                cout << "Should be: " << vec_to_string(shouldBe) << endl;
                cout << "Result: " << vec_to_string(result) << endl;
                return false;
            }
        }

        return true;
    }

} // chapter6
} // epi
