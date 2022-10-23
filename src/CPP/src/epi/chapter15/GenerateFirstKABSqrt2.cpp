#include "GenerateFirstKABSqrt2.hpp"

#include <memory>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <climits>
#include <ostream>
#include <iostream>
#include <stdexcept>
#include <cassert>
#include <string>

#include "../../BSTNode.h"
#include "../../MyUtils.h"

using std::unique_ptr;
using std::vector;
using std::set;
using std::sqrt;
using std::min;
using std::next;
using std::ostream;
using myutils::BSTNode;
using myutils::createPreOrderIntBST;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter15 {
    struct GenerateFirstKABSqrt2::ABSqrt2 {
        ABSqrt2(int a, int b): a(a), b(b), val(a + b * sqrt(2)) { }

        bool operator<(const ABSqrt2 &that) const {
            return val < that.val;
        }

        bool operator==(const ABSqrt2 &that) const {
            return a == that.a && b == that.b;
        }

        int a, b;
        double val;
    };

    ostream& operator<<(ostream &os, const GenerateFirstKABSqrt2::ABSqrt2 &abSqrt2) {
        os << abSqrt2.val;

        return os;
    }

    vector<GenerateFirstKABSqrt2::ABSqrt2> GenerateFirstKABSqrt2::generateFirstKABSqrt2BST(size_t k) {
        set<ABSqrt2> candidates;
        candidates.insert(ABSqrt2(0, 0));

        vector<ABSqrt2> res;
        while (res.size() != k) {
            set<ABSqrt2>::const_iterator smallest = candidates.cbegin();
            res.push_back(*smallest);

            candidates.insert(ABSqrt2(smallest->a + 1, smallest->b));
            candidates.insert(ABSqrt2(smallest->a, smallest->b + 1));
            candidates.erase(smallest);
        }

        return res;
    }

    vector<GenerateFirstKABSqrt2::ABSqrt2> GenerateFirstKABSqrt2::generateFirstKABSqrt2Ptrs(size_t k) {
        vector<ABSqrt2> res = {ABSqrt2(0, 0)};

        size_t i = 0, j = 0;

        while (res.size() != k) {
            ABSqrt2 plusI(res[i].a + 1, res[i].b);
            ABSqrt2 plusJ(res[j].a, res[j].b + 1);
            if (plusI < plusJ) {
                res.push_back(plusI);
                ++i;
            } else if (plusI == plusJ) {
                res.push_back(plusI);
                ++i, ++j;
            } else {
                res.push_back(plusJ);
                ++j;
            }
        }

        return res;
    }

    bool GenerateFirstKABSqrt2::test() {
        vector<ABSqrt2> res1 = generateFirstKABSqrt2BST(10);
        vector<ABSqrt2> res2 = generateFirstKABSqrt2Ptrs(10);

        if (res1 != res2) {
            cout << "res1 <";
            for (ABSqrt2 tmp : res1) {
                cout << tmp << ", ";
            }
            cout << ">" << endl;

            cout << "res2 <";
            for (ABSqrt2 tmp : res2) {
                cout << tmp << ", ";
            }
            cout << ">" << endl;

            return false;
        }

        return true;
    }

  } // chapter15
} // epi
