#include "ApplyPermutation.hpp"

#include <vector>
#include <iostream>

#include "../../MyUtils.h"

using std::vector;
using std::cout;
using std::endl;
using myutils::vec_to_string;

namespace epi {
  namespace chapter6 {
    void ApplyPermutation::swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    void ApplyPermutation::applyPermutationMutatePerm(vector<int> &perm, vector<int> &vec) {
        if ( vec.empty() || vec.size() != perm.size() )
            return;

        for (size_t i = 0; i != perm.size(); ++i) {
            // Actually not needed, because while condition deal with it
            if (perm[i] < 0)
                continue;

            // i never change in the while. So can use it as a tmp storage
            size_t cur = i;
            while (perm[cur] >= 0) {
                swap(vec[i], vec[ perm[cur] ]);
                int tmp = perm[cur];
                perm[cur] -= perm.size();
                cur = tmp;
            }
        }

        for (size_t i = 0; i != perm.size(); ++i) {
            perm[i] = perm[i] + perm.size(); // not use -perm[i] because 0 becomes 0
        }
    }

    void ApplyPermutation::applyPermutation(const vector<int> &perm, vector<int> &vec) {
        if ( perm.empty() || perm.size() != vec.size() )
            return;

        for (size_t st = 0; st != perm.size(); ++st) {
            bool cycleStart = true;
            size_t ed = perm[st];
            while (ed != st) {
                if (ed < st) {
                    cycleStart = false;
                    break;
                }
                ed = perm[ed];
            }

            if (!cycleStart)
                continue;

            size_t cur = st;
            int put = vec[st];
            do {
                int take = vec[ perm[cur] ];
                vec[ perm[cur] ] = put;
                put = take;
                cur = perm[cur];
            } while (cur != st);
        }
    }

    bool ApplyPermutation::test() {
        vector<int> A1 = {1, 2, 3, 4}, A2(A1);
        vector<int> P1 = {2, 0, 1, 3}, P2(P1);

        applyPermutationMutatePerm(P1, A1);
        if (P1 != P2) {
            cout << "After permute P didn't restored: " << vec_to_string(P1) << endl;
            return false;
        }

        applyPermutation(P2, A2);

        if (A1 != A2) {
            cout << "After permute: " << vec_to_string(A1) << endl;
            cout << "After permute: " << vec_to_string(A2) << endl;
            return false;
        }

        return true;
    }
  } // chapter6

} // epi
