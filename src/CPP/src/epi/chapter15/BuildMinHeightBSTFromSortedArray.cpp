#include "BuildMinHeightBSTFromSortedArray.hpp"

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
using std::move;
using std::ostream;
using myutils::BSTNode;
using myutils::createPreOrderIntBST;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter15 {
    unique_ptr<BSTNode<int>> BuildMinHeightBSTFromSortedArray::buildBSTHelper(const vector<int> &sortedArray, int st, int ed) {
        if (st > ed)
            return nullptr;

        size_t md = st + (ed - st) / 2;

        unique_ptr<BSTNode<int>> left = buildBSTHelper(sortedArray, st, md - 1);
        unique_ptr<BSTNode<int>> right = buildBSTHelper(sortedArray, md + 1, ed);

        unique_ptr<BSTNode<int>> root(new BSTNode<int>(sortedArray[md]));
        root.get()->left = move(left);
        root.get()->right = move(right);

        return root;
    }

    unique_ptr<BSTNode<int>> BuildMinHeightBSTFromSortedArray::buildMinHeightBSTFromSortedArray(const vector<int> &sortedArray) {
        return buildBSTHelper(sortedArray, 0, sortedArray.size() - 1);
    }

    bool BuildMinHeightBSTFromSortedArray::test() {
        vector<int> array = {2,3,5,7,11,13,17,19,23};

        unique_ptr<BSTNode<int>> res = buildMinHeightBSTFromSortedArray(array);
        if (res.get()->data != 11) {
            cout << "Should be " << 11 << endl;
            cout << "Result " << res.get()->data << endl;

            return false;
        }

        return true;
    }

  } // chapter15
} // epi
