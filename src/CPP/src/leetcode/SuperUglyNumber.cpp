/*
 * [Source] https://leetcode.com/problems/super-ugly-number/
 * [Difficulty]: Medium
 * [Tag]: Math
 * [Tag]: Heap
 */

#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <climits>

using namespace std;

// [Solution]: Use priority queue. Will out of memeory.
// [Corner Case]:
class SolutionPQ {
public:
    struct NumIdx {
        long num;
        int idx;

        bool operator<(const NumIdx& other) const {
            return num < other.num;
        }
    };

    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n <= 1)
            return 1;

        priority_queue< NumIdx, vector<NumIdx>, function<bool(NumIdx, NumIdx)> > pq
            ( [](const NumIdx& first, const NumIdx& second)->bool {return first.num > second.num;} );

        for (int i = 0; i < (int)primes.size(); ++i) {
            pq.push({(long)primes[i], i});
        }

        for (int i = 2; i < n; ++i) {
            NumIdx minVal = pq.top();
            pq.pop();

            for (int idx = minVal.idx; idx < (int)primes.size(); ++idx) {
                pq.push({minVal.num * (long)primes[idx], idx});
            }
        }

        return (int)pq.top().num;
    }
};

// [Solution]: Multiple previous min value with all primes, but only insert the minimal one to result. This same the memory. Use a index vector to indicate the next min val the prime should multiple. When increase these indexes, need to increase all of them that multiple to the same value
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long> uglyNums(n);
        uglyNums[0] = 1;

        vector<int> primeFront(primes.size(), 0); // indicate primes[i] has multipled with which uglyNums already
        for (int i = 1; i < n; ++i) {
            long minUglyNum = INT_MAX;
            for (int primeIdx = 0; primeIdx < (int)primes.size(); ++primeIdx) {
                if (minUglyNum > primes[primeIdx] * uglyNums[primeFront[primeIdx]]) {
                    minUglyNum = primes[primeIdx] * uglyNums[primeFront[primeIdx]];
                }
            }
            // to avoid duplicate, increase all primeFront that are equal to min
            for (int primeIdx = 0; primeIdx < (int)primes.size(); ++primeIdx) {
                if (minUglyNum == primes[primeIdx] * uglyNums[primeFront[primeIdx]])
                    ++primeFront[primeIdx];
            }

            uglyNums[i] = minUglyNum;
cout << minUglyNum << endl;
        }

        return (int)uglyNums.back();
    }
};

int main() {
    Solution sol;

    //vector<int> primes = {2, 7, 13, 19};
    //cout << sol.nthSuperUglyNumber(12, primes) << endl;
    vector<int> primes = {7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251};
    cout << sol.nthSuperUglyNumber(100000, primes) << endl;

    return 0;
}
