#include "OnlineRandomSample.hpp"

#include <sstream>
#include <iostream>
#include <vector>
#include <random>
#include <string>

#include "../../MyUtils.h"

using std::cout;
using std::endl;
using std::vector;
using std::istringstream;
using myutils::vec_to_string;
using std::random_device;
using std::uniform_int_distribution;
using std::default_random_engine;

namespace epi {
  namespace chapter6 {
    vector<int> OnlineRandomSample::onlineRandomSample(istringstream *sin, int k) {
        int x;
        vector<int> runningSample;

        for (int i = 0; i != k && *sin >> x; ++i) {
            runningSample.push_back(x);
        }

        default_random_engine seed( (random_device()) () );
        int dataSeenCnt = k;

        while (*sin >> x) {
            cout << vec_to_string(runningSample) << endl;

            ++dataSeenCnt;
            int randomIdx = uniform_int_distribution<int>{ 0, dataSeenCnt - 1 }(seed);
            if (randomIdx < k) {
                runningSample[randomIdx] = x;
            }
        }

        return runningSample;
    }

    bool OnlineRandomSample::test() {
        std::ifstream file;
        file.open("resources/randomint");

        if (!file) {
            cout << "Error: cannot read file" << endl;
            return false;
        }

        std::string line;
        getline(file, line);
        cout << line << endl;
        istringstream iss(line);
        vector<int> res = onlineRandomSample(&iss, 3);

        cout << vec_to_string(res) << endl;

        return true;
    }
  } // chapter6
} // epi
