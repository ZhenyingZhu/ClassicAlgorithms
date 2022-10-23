#include "RandomSubset.hpp"

#include <vector>
#include <unordered_map>
#include <random>
#include <iostream>
#include <algorithm>
#include <string>

#include "../../MyUtils.h"

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::default_random_engine;
using std::random_device;
using std::uniform_int_distribution;
using std::sort;
using std::swap;
using std::string;
using myutils::vec_to_string;

namespace epi {
  namespace chapter6 {
    vector<int> RandomSubset::randomSubset(int n, int k) {
        unordered_map<int, int> changedElements;

        default_random_engine seed( (random_device()) () );

        for (int i = 0; i != k; ++i) {
            int randomIdx = uniform_int_distribution<int>{ i, n - 1 }(seed);

            auto ptr1 = changedElements.find(randomIdx);
            auto ptr2 = changedElements.find(i);
            if ( ptr1 == changedElements.end() && ptr2 == changedElements.end() ) {
                changedElements[i] = randomIdx;
                changedElements[randomIdx] = i;
            } else if ( ptr1 == changedElements.end() && ptr2 != changedElements.end() ) {
                changedElements[randomIdx] = ptr2->second;
                ptr2->second = randomIdx;
            } else if ( ptr1 != changedElements.end() && ptr2 == changedElements.end() ) {
                changedElements[i] = ptr1->second;
                ptr1->second = i;
            } else {
                int tmp = ptr2->second;
                changedElements[i] = ptr1->second;
                changedElements[randomIdx] = tmp;
            }
        }

        vector<int> res;
        for (int i = 0; i != k; ++i) {
            res.push_back(changedElements[i]);
        }

        sort(res.begin(), res.end());

        return res;
    }

    vector<int> RandomSubset::randomSubsetBruteForce(int n, int k) {
        vector<int> fullset;
        for (int i = 0; i != n; ++i) {
            fullset.push_back(i);
        }

        default_random_engine seed( (random_device()) () );

        for (int i = 0; i != k; ++i) {
            int randomIdx = uniform_int_distribution<int>{ i, n - 1 }(seed);

            swap( fullset[i], fullset[randomIdx] );
        }

        vector<int> res(fullset.begin(), fullset.begin() + k);
        sort(res.begin(), res.end());

        return res;

    }

    bool RandomSubset::test() {
        unordered_map<string, int> bfmap;
        for (int i = 0; i != 16; ++i) {
            vector<int> res = randomSubset(4, 3);
            if ( bfmap.find(vec_to_string(res)) == bfmap.end() ) {
                bfmap[vec_to_string(res)] = 0;
            }
            ++bfmap[vec_to_string(res)];
        }

        for (unordered_map<string, int>::const_iterator ptr = bfmap.begin(); ptr != bfmap.end(); ++ptr) {
            cout << ptr->first << " : " << ptr->second << endl;
        }

        return true;
    }
  } // chapter6
} // epi
