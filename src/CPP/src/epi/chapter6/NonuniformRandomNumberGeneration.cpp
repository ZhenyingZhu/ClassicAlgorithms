#include "NonuniformRandomNumberGeneration.hpp"

#include <vector>
#include <unordered_map>
#include <iostream>
#include <random>
#include <numeric>
#include <iterator>
#include <limits>
#include <algorithm>
#include <string>
#include <stdexcept>

#include "../../MyUtils.h"

using std::vector;
using std::cout;
using std::endl;
using std::partial_sum;
using std::back_inserter;
using std::default_random_engine;
using std::random_device;
using std::generate_canonical;
using std::numeric_limits;
using std::distance;
using std::upper_bound;
using std::unordered_map;
using std::to_string;
using std::invalid_argument;
using std::runtime_error;

namespace epi {
  namespace chapter6 {
        int NonuniformRandomNumberGeneration::nonuniformRandomNumberGeneration(
                const vector<int> &values, const vector<double> &probabilities) {
            if (values.size() != probabilities.size()) {
                throw invalid_argument("Not all values have probabilities or move probabilities than values.");
            }

            vector<double> prefixSumOfProbabilities;

            prefixSumOfProbabilities.push_back(0.0);
            partial_sum( probabilities.cbegin(), probabilities.cend(), back_inserter(prefixSumOfProbabilities) );

            default_random_engine seed( (random_device()) () );
            double uniform_0_1 = generate_canonical< double, numeric_limits<double>::digits >(seed);

            int intervalIdx = distance( prefixSumOfProbabilities.cbegin(),
                                        upper_bound(prefixSumOfProbabilities.cbegin(), prefixSumOfProbabilities.cend(), uniform_0_1)
                                      ) - 1;

            if ( intervalIdx >= static_cast<int>(values.size()) ) {
                throw runtime_error("Index " + to_string(intervalIdx) + " out of bound.");
            }

            return values[intervalIdx];
        }

        bool NonuniformRandomNumberGeneration::test() {
            vector<double> probabilities = {9.0/18.0, 6.0/18.0, 2.0/18.0, 1.0/18.0};
            vector<int> values = {3, 5, 7, 11};

            unordered_map<int, int> resMap;
            for (int i = 0; i != 18; ++i) {
                int res = nonuniformRandomNumberGeneration(values, probabilities);

                if (resMap.find(res) == resMap.end())
                    resMap[res] = 0;
                ++resMap[res];
            }

            for (unordered_map<int, int>::const_iterator iter = resMap.begin(); iter != resMap.end(); ++iter) {
                cout << iter->first << ": " << iter->second << endl;
            }

            return true;
        }
  } // chapter6
} // epi
