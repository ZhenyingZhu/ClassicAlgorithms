#include "LCA.hpp"

#include <memory>
#include <unordered_set>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "../../BinaryTreeNode.h"
#include "../../MyUtils.h"

using std::unique_ptr;
using myutils::BinaryTreeNode;
using myutils::BTNULL;
using myutils::createPreOrderIntBTree;
using std::unordered_set;
using std::runtime_error;
using std::vector;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter13 {
    BinaryTreeNode<int>* LCA::findLCA(const unique_ptr<BinaryTreeNode<int>> &node0,
                                      const unique_ptr<BinaryTreeNode<int>> &node1) {
        unordered_set<BinaryTreeNode<int>*> traversedNodes;

        BinaryTreeNode<int> *n0 = node0.get(), *n1 = node1.get();

        while (n0 || n1) {
            if (n0) {
                if ( !traversedNodes.insert(n0).second )
                    return n0;

                n0 = n0->parent;
            }

            if (n1) {
                if ( !traversedNodes.insert(n1).second )
                    return n1;

                n1 = n1->parent;
            }
        }

        throw runtime_error("Two nodes are in different trees.");
    }

    bool LCA::test() {
        vector<int> preOrder1 = {314, 6, BTNULL, 2, BTNULL, 3, BTNULL, BTNULL, 6, 2, 3};
        size_t pos = 0;
        unique_ptr<BinaryTreeNode<int>> root1 = createPreOrderIntBTree(preOrder1, &pos);
        unique_ptr<BinaryTreeNode<int>> &node11 = root1.get()->left;
        unique_ptr<BinaryTreeNode<int>> &node12 = root1.get()->right;

        if (findLCA(node11, node12)->data != 314) {
            cout << "root1 should be common ancestor" << endl;
            return false;
        }

        return true;
    }

  } // chapter13
} // epi
