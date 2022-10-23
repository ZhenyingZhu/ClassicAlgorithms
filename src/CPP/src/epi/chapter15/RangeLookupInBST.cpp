#include "RangeLookupInBST.hpp"

#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../BSTNode.h"
#include "../../MyUtils.h"

using std::unique_ptr;
using std::vector;
using std::sort;
using myutils::BSTNode;
using myutils::createBSTFromPreorder;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter15 {
    struct RangeLookupInBST::Interval {
        int left, right;
    };

    void RangeLookupInBST::rangeLookupInBSTHelper(const unique_ptr<BSTNode<int>> &root, int st, int ed, vector<int> &result) {
        if (root == nullptr)
            return;

        BSTNode<int> *node = root.get();
        if (node->data > ed) {
            rangeLookupInBSTHelper(node->left, st, ed, result);
        } else if (node->data < st) {
            rangeLookupInBSTHelper(node->right, st, ed, result);
        } else {
            result.push_back(node->data);
            rangeLookupInBSTHelper(node->left, st, node->data, result);
            rangeLookupInBSTHelper(node->right, node->data, ed, result);
        }
    }

    vector<int> RangeLookupInBST::rangeLookupInBST(const unique_ptr<BSTNode<int>> &tree, const Interval &interval) {
        assert(interval.left <= interval.right);

        vector<int> result;
        rangeLookupInBSTHelper(tree, interval.left, interval.right, result);

        sort(result.begin(), result.end());
        return result;
    }

    bool RangeLookupInBST::test() {
        vector<int> preOrder = {19, 7, 3, 2, 5, 11, 17, 13, 43, 23, 37, 29, 31, 41, 47, 53};
        unique_ptr<BSTNode<int>> tree = createBSTFromPreorder(preOrder);
        Interval interval{16, 31};

        vector<int> ans = {17,19, 23,29,31};
        vector<int> res = rangeLookupInBST(tree, interval);

        if (res != ans) {
            cout << "Should be " << vec_to_string(ans) << endl;
            cout << "Result " << vec_to_string(ans) << endl;

            return false;
        }

        return true;
    }

  } // chapter15
} // epi
