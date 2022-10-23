#include "ExamineBuildingsWithSunset.hpp"

#include <stack>
#include <memory>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <vector>

#include "../../MyUtils.h"

using std::stack;
using std::shared_ptr;
using std::string;
using std::stringstream;
using std::istringstream;
using std::stoi;
using std::length_error;
using std::invalid_argument;
using std::cout;
using std::endl;
using std::vector;
using myutils::vec_to_string;

namespace epi {
  namespace chapter9 {
    struct ExamineBuildingsWithSunset::BuildingWithHeight {
        int id;
        int height;
    };

    vector<int> ExamineBuildingsWithSunset::examineBuildingsWithSunset(istringstream *sin) {
        stack<BuildingWithHeight> buildings;

        int buildingId = 0, buildingHeight;
        while (*sin >> buildingHeight) {
            while (!buildings.empty() && buildings.top().height <= buildingHeight)
                buildings.pop();
            buildings.push(BuildingWithHeight{buildingId++, buildingHeight});
        }

        vector<int> res;
        while (!buildings.empty()) {
            res.push_back(buildings.top().id);
            buildings.pop();
        }

        return res;
    }

    bool ExamineBuildingsWithSunset::test() {
        string input = "2 6 3 4 5 1";
        istringstream ss(input);

        vector<int> ans = {5, 4, 1};
        vector<int> res = examineBuildingsWithSunset(&ss);

        if (res != ans) {
            cout << "Should be: " << vec_to_string(ans) << endl;
            cout << "Result: " << vec_to_string(res) << endl;
            return false;
        }
        return true;
    }

  } // chapter9
} // epi
