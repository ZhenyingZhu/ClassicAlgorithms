#include "BinaryTreeFromPreorderInorder.hpp"

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
using std::find;
using std::move;
using myutils::traversePreInOrder;
using myutils::BinaryTreeNode;
using myutils::BTNULL;
using std::invalid_argument;
using myutils::createPreOrderIntBTree;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter10 {
    unique_ptr<BinaryTreeNode<int>> BinaryTreeFromPreorderInorder::btConstructHelper(
            const vector<int> &preorder, vector<int>::const_iterator pst, vector<int>::const_iterator ped,
            const vector<int> &inorder, vector<int>::const_iterator ist, vector<int>::const_iterator ied) {
        assert (ped - pst == ied - ist);
        if (ped < pst)
            return nullptr;

        int data = *pst;

        unique_ptr<BinaryTreeNode<int>> node( new BinaryTreeNode<int>(data) );
        if (ped == pst) {
            return node;
        }

        vector<int>::const_iterator p = find(ist, ied + 1, data);
        if (p == inorder.end())
            throw invalid_argument("InOrder and PreOrder arrays are not same");
        int eleNum = p - ist;

        node.get()->left = move( btConstructHelper(preorder, pst + 1, pst + eleNum, inorder, ist, ist + eleNum - 1) );
        node.get()->right = move( btConstructHelper(preorder, pst + eleNum + 1, ped, inorder, ist + eleNum + 1, ied) );

        return node;
    }

    unique_ptr<BinaryTreeNode<int>> BinaryTreeFromPreorderInorder::binaryTreeFromPreorderInorder(
          const vector<int> &preorder,
          const vector<int> &inorder) {
        if (preorder.size() != inorder.size())
            throw invalid_argument("InOrder and PreOrder arrays are not the same length");

        vector<int>::const_iterator pst = preorder.begin(), ped = preorder.end() - 1;
        vector<int>::const_iterator ist = inorder.begin(), ied = inorder.end() - 1;
        return btConstructHelper(preorder, pst, ped, inorder, ist, ied);
    }

    bool BinaryTreeFromPreorderInorder::test() {
        vector<int> inorder = {1, 2, 3, 4, 5, 6, 7};
        vector<int> preorder = {5, 3, 1, 2, 4, 6, 7};
        unique_ptr<BinaryTreeNode<int>> res = binaryTreeFromPreorderInorder(preorder, inorder);

        vector<int> respre, resin;
        traversePreInOrder(res, respre, resin);
        if (respre != preorder) {
            cout << "preorder should be " << vec_to_string(preorder) << endl;
            cout << "result " << vec_to_string(respre) << endl;
            return false;
        }

        if (resin != inorder) {
            cout << "inorder should be " << vec_to_string(inorder) << endl;
            cout << "result " << vec_to_string(resin) << endl;
            return false;
        }

        return true;
    }

  } // chapter10
} // epi
