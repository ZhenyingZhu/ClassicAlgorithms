#include "FindClosestKStars.hpp"

#include <vector>
#include <queue>
#include <sstream>
#include <string>
#include <cmath>
#include <functional>
#include <iterator>
#include <iostream>
#include <ostream>
#include <array>
#include "../../MyUtils.h"

using std::vector;
using std::priority_queue;
using std::greater;
using std::istringstream;
using std::stringstream;
using std::string;
using std::sqrt;
using std::getline;
using std::array;
using std::stod;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter11 {
    struct FindClosestKStars::Star {
        double distance() const {
            return sqrt(x * x + y * y + z * z);
        }

        bool operator<(const Star &that) const {
            return distance() < that.distance();
        }

        double x, y, z;
    };

    std::ostream& operator<<(std::ostream &stream, FindClosestKStars::Star &star) {
        stream << "(" << star.x << "," << star.y << "," << star.z << ")" << ":" << star.distance();
        return stream;
    }

    vector<FindClosestKStars::Star> FindClosestKStars::findClosestKStars(size_t k, istringstream *stars) {
        priority_queue<Star, vector<Star>> maxHeap;

        string line;
        array<double, 3> data;
        while (getline(*stars, line)) {
            stringstream lineStream(line);
            for (int i = 0; i != 3; ++i) {
                string buf;
                getline(lineStream, buf, ',');
                data[i] = stod(buf);
            }

            Star star{data[0], data[1], data[2]};
            if (maxHeap.size() == k) {
                if (maxHeap.top() < star) {
                    continue;
                }
                maxHeap.pop();
            }
            maxHeap.push(star);
        }

        vector<Star> res;
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return res;
    }

    bool FindClosestKStars::test() {
        string input("1,0,0\n2,0,0\n0,1,0\n1,1,0");
        istringstream *iss = new istringstream(input);

        vector<Star> res = findClosestKStars(3, iss);

        for (Star s : res) {
            cout << s << endl;
        }

        delete iss;

        return true;
    }

  } // chapter11
} // epi
