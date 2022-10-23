#include "ReconstructPreorder.hpp"

#include <memory>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "../../BinaryTreeNode.h"
#include "../../MyUtils.h"

using std::unique_ptr;
using std::vector;
using std::move;
using myutils::BinaryTreeNode;
using myutils::BTNULL;
using std::invalid_argument;
using myutils::createPreOrderIntBTree;
using myutils::traversePreInOrder;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter10 {
    unique_ptr<BinaryTreeNode<int>> ReconstructPreorder::btConstructHelper(const vector<int*> &preorder, int &pos) {
        assert (preorder.begin() + pos <= preorder.end());
        if (preorder.begin() + pos == preorder.end() || preorder[pos] == nullptr)
            return nullptr;

        unique_ptr<BinaryTreeNode<int>> node( new BinaryTreeNode<int>(*preorder[pos]) );
        ++(pos);
        node.get()->left = move( btConstructHelper(preorder, pos) );
        ++(pos);
        node.get()->right = move( btConstructHelper(preorder, pos) );

        return node;
    }

    unique_ptr<BinaryTreeNode<int>> ReconstructPreorder::reconstructPreorder(const vector<int*> &preorder) {
        int idx = 0;
        int &pos = idx;
        return btConstructHelper(preorder, pos);
    }

    bool ReconstructPreorder::test() {
        vector<int*> preorder = {new int(1), new int(2), new int(3), nullptr, nullptr, new int(4), new int(5), nullptr, nullptr, nullptr,
                new int(6), nullptr, new int(7), nullptr, new int(8), new int(9), nullptr, nullptr, nullptr
        };
        unique_ptr<BinaryTreeNode<int>> res = reconstructPreorder(preorder);

        vector<int> respre, resin;
        traversePreInOrder(res, respre, resin);
        vector<int> anspre = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        if (respre != anspre) {
            cout << "preorder should be " << vec_to_string(anspre) << endl;
            cout << "result " << vec_to_string(respre) << endl;
            return false;
        }

        return true;
    }

  } // chapter10
} // epi
