#include "RebuildBSTFromPreorder.hpp"

#include <memory>
#include <vector>
#include <climits>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../BSTNode.h"
#include "../../MyUtils.h"

using std::unique_ptr;
using std::vector;
using myutils::BSTNode;
using myutils::createPreOrderIntBST;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter15 {
    unique_ptr<BSTNode<int>> RebuildBSTFromPreorder::preorderBSTHelper(const vector<int> &preorderSeq,
            size_t &pos, int lowerBound, int higherBound) {
        if (pos >= preorderSeq.size())
            return nullptr;

        int data = preorderSeq[pos];
        if ( data < lowerBound || data > higherBound )
            return nullptr;

        ++pos;
        unique_ptr<BSTNode<int>> res(new BSTNode<int>(data));
        res.get()->left = move( preorderBSTHelper(preorderSeq, pos, lowerBound, data) );
        res.get()->right = move( preorderBSTHelper(preorderSeq, pos, data, higherBound) );

        return res;
    }

    unique_ptr<BSTNode<int>> RebuildBSTFromPreorder::rebuildBSTFromPreorder(const vector<int> &preorderSeq) {
        size_t pos = 0;
        size_t &p = pos;
        return preorderBSTHelper(preorderSeq, p, INT_MIN, INT_MAX);
    }

    void RebuildBSTFromPreorder::inPreOrderTraverse(const unique_ptr<BSTNode<int>> &tree, vector<int> &inorder, vector<int> &preorder) {
        if (tree == nullptr)
            return;

        preorder.push_back(tree.get()->data);
        inPreOrderTraverse(tree.get()->left, inorder, preorder);
        inorder.push_back(tree.get()->data);
        inPreOrderTraverse(tree.get()->right, inorder, preorder);
    }

    bool RebuildBSTFromPreorder::test() {
        vector<int> preOrder = {19, 7, 3, 2, 5, 11, 17, 13, 43, 23, 37, 29, 31, 41, 47, 53};

        unique_ptr<BSTNode<int>> tree = rebuildBSTFromPreorder(preOrder);

        vector<int> inorderAns = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
        vector<int> inorderTraverse, preorderTraverse;
        inPreOrderTraverse(tree, inorderTraverse, preorderTraverse);

        if (inorderTraverse != inorderAns || preorderTraverse != preOrder) {
            cout << "Inorder res " << vec_to_string(inorderTraverse) << endl;
            cout << "Preorder res " << vec_to_string(preorderTraverse) << endl;

            return false;
        }

        return true;
    }

  } // chapter15
} // epi
