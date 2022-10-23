#include "NodesOnPath.hpp"

#include <memory>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../BSTNode.h"
#include "../../MyUtils.h"

using std::unique_ptr;
using std::vector;
using myutils::BSTNode;
using myutils::createBSTFromPreorder;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter15 {
    bool NodesOnPath::isAncestor(const unique_ptr<BSTNode<int>> &ancestor, const unique_ptr<BSTNode<int>> &descendant) {
        BSTNode<int> *cur = ancestor.get(), *desc = descendant.get();
        if (cur == desc)
            return false;

        while (cur) {
            if (cur == desc)
                break;
            if (cur->data > desc->data)
                cur = cur->left.get();
            else
                cur = cur->right.get();
        }

        if (!cur)
            return false;

        return true;
    }

    bool NodesOnPath::pairIncludesAncestorAndDescendantOfM(const unique_ptr<BSTNode<int>> &node0,
                                                           const unique_ptr<BSTNode<int>> &node1,
                                                           const unique_ptr<BSTNode<int>> &mid) {
        if ( isAncestor(node0, mid) && isAncestor(mid, node1) )
            return true;

        if ( isAncestor(node1, mid) && isAncestor(mid, node0) )
            return true;

        return false;
    }

    bool NodesOnPath::test() {
        vector<int> preOrder = {19, 7, 3, 2, 5, 11, 17, 13, 43, 23, 37, 29, 31, 41, 47, 53};
        unique_ptr<BSTNode<int>> tree = createBSTFromPreorder(preOrder);

        unique_ptr<BSTNode<int>> &mid = tree.get()->right.get()->left;

        unique_ptr<BSTNode<int>> &nodeA = tree;
        unique_ptr<BSTNode<int>> &nodeK = tree.get()->right.get()->left.get()->right;
        if (!pairIncludesAncestorAndDescendantOfM(nodeA, nodeK, mid)) {
            cout << "{A, K} return false" << endl;
            return false;
        }

        unique_ptr<BSTNode<int>> &nodeI = tree.get()->right;
        unique_ptr<BSTNode<int>> &nodeM = tree.get()->right.get()->left.get()->right.get()->left.get()->right;
        if (!pairIncludesAncestorAndDescendantOfM(nodeI, nodeM, mid)) {
            cout << "{I, M} return false" << endl;
            return false;
        }

        unique_ptr<BSTNode<int>> &nodeP = tree.get()->right.get()->right.get()->right;
        if (pairIncludesAncestorAndDescendantOfM(nodeI, nodeP, mid)) {
            cout << "{I, P} return true" << endl;
            return false;
        }

        unique_ptr<BSTNode<int>> &nodeJ = tree.get()->right.get()->left;
        if (pairIncludesAncestorAndDescendantOfM(nodeJ, nodeK, mid)) {
            cout << "{J, K} return true" << endl;
            return false;
        }

        return true;
    }

  } // chapter15
} // epi
