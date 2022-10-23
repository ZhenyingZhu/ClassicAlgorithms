#include "BSTInSortedOrder.hpp"

#include <memory>
#include <vector>
#include <stack>
#include <stdexcept>
#include <iostream>

#include "../../BinaryTreeNode.h"
#include "../../MyUtils.h"

using std::unique_ptr;
using std::vector;
using std::stack;
using myutils::BinaryTreeNode;
using myutils::BTNULL;
using std::invalid_argument;
using myutils::createPreOrderIntBTree;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter10 {
    struct BSTInSortedOrder::Status {
        BinaryTreeNode<int> *nodePtr;
        bool leftTraversed;
    };

    vector<int> BSTInSortedOrder::inSortedOrder(const unique_ptr<BinaryTreeNode<int>> &tree) {
        vector<int> inOrder;
        if (!tree)
            return inOrder;

        stack<Status> pendingNodes;
        pendingNodes.push({tree.get(), false});

        while (!pendingNodes.empty()) {
            Status cur = pendingNodes.top();
            pendingNodes.pop();

            if (cur.leftTraversed) {
                inOrder.push_back(cur.nodePtr->data);
            } else {
                cur.leftTraversed = true;
                if (cur.nodePtr->right)
                    pendingNodes.push({cur.nodePtr->right.get(), false});

                pendingNodes.push(cur);

                if (cur.nodePtr->left)
                    pendingNodes.push({cur.nodePtr->left.get(), false});
            }
        }

        return inOrder;
    }

    bool BSTInSortedOrder::test() {
        vector<int> preOrder1 = {314, 6, 271, 28, BTNULL, BTNULL, 0, BTNULL, BTNULL,
                561, BTNULL, 3, 17, BTNULL, BTNULL, BTNULL,
                6, 2, BTNULL, 1, 401, BTNULL, 641, BTNULL, BTNULL, 257, BTNULL, BTNULL,
                271, BTNULL, 28
        };
        size_t pos = 0;
        unique_ptr<BinaryTreeNode<int>> root1 = createPreOrderIntBTree(preOrder1, &pos);

        vector<int> res = inSortedOrder(root1);
        vector<int> ans = {28, 271, 0, 6, 561, 17, 3, 314, 2, 401, 641, 1, 257, 6, 271, 28};

        if (res != ans) {
            cout << "should be " << vec_to_string(ans) << endl;
            cout << "result " << vec_to_string(res) << endl;
            return false;
        }

        return true;
    }

  } // chapter10
} // epi
