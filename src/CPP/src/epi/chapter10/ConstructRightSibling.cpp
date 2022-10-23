#include "ConstructRightSibling.hpp"

#include <memory>
#include <queue>
#include <vector>
#include <assert.h>
#include <stdexcept>
#include <iostream>

#include "../../MyUtils.h"

using std::unique_ptr;
using std::queue;
using std::vector;
using std::move;
using std::invalid_argument;
using myutils::createPreOrderIntBTree;
using myutils::vec_to_string;
using myutils::BTNULL;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter10 {
    void ConstructRightSibling::updateRightSibling(BTSiblingNode<int> *node, BTSiblingNode<int> *parent) {
        if (node == parent->left.get() && parent->right) {
            node->next = parent->right.get();
            return;
        }

        parent = parent->next;
        while (parent != nullptr) {
            if (parent->left) {
                node->next = parent->left.get();
                return;
            } else if (parent->right) {
                node->next = parent->right.get();
                return;
            } else {
                parent = parent->next;
            }
        }

        node->next = nullptr;
    }

    void ConstructRightSibling::constructRightSibling(BTSiblingNode<int> *tree) {
        if (tree == nullptr)
            return;

        queue<BTSiblingNode<int>*> levelNodes;
        levelNodes.push(tree);

        while (!levelNodes.empty()) {
            for (int size = levelNodes.size(); size > 0; --size) {
                BTSiblingNode<int> *node = levelNodes.front();
                levelNodes.pop();

                if (node->left) {
                    BTSiblingNode<int> *leftChild = node->left.get();
                    updateRightSibling(leftChild, node);
                    levelNodes.push(leftChild);
                }

                if (node->right) {
                    BTSiblingNode<int> *rightChild = node->right.get();
                    updateRightSibling(rightChild, node);
                    levelNodes.push(rightChild);
                }
            }
        }
    }

    unique_ptr<ConstructRightSibling::BTSiblingNode<int>> ConstructRightSibling::createPreOrderIntBTree(
            const vector<int> &vec, size_t *pos) {
        if (*pos >= vec.size() || vec[*pos] == myutils::BTNULL) {
            return nullptr;
        }

        unique_ptr<BTSiblingNode<int>> root( new BTSiblingNode<int>{vec[*pos]} );
        ++(*pos);
        root.get()->left = move( createPreOrderIntBTree(vec, pos) );
        ++(*pos);
        root.get()->right = move( createPreOrderIntBTree(vec, pos) );

        return root;
    }

    bool ConstructRightSibling::test() {
        vector<int> preOrder1 = {314, 6, 271, 28, BTNULL, BTNULL, 0, BTNULL, BTNULL,
                561, BTNULL, 3, 17, BTNULL, BTNULL, BTNULL,
                6, 2, BTNULL, 1, 401, BTNULL, 641, BTNULL, BTNULL, 257, BTNULL, BTNULL,
                271, BTNULL, 28
        };
        size_t pos = 0;
        unique_ptr<BTSiblingNode<int>> root1 = createPreOrderIntBTree(preOrder1, &pos);

        constructRightSibling(root1.get());

        BTSiblingNode<int> *node28 = root1.get()->left.get()->left.get()->left.get();
        vector<int> ans1 = {28, 0, 3, 1, 28};
        vector<int> res1;
        while (node28 != nullptr) {
            res1.push_back(node28->data);
            node28 = node28->next;
        }
        if (res1 != ans1) {
            cout << "Should be " << vec_to_string(ans1) << endl;
            cout << "Result " << vec_to_string(res1) << endl;
            return false;
        }

        BTSiblingNode<int> *node401 = root1.get()->right.get()->left.get()->right.get()->left.get();
        vector<int> ans2 = {401, 257};
        vector<int> res2;
        while (node401 != nullptr) {
            res2.push_back(node401->data);
            node401 = node401->next;
        }
        if (res2 != ans2) {
            cout << "Should be " << vec_to_string(ans2) << endl;
            cout << "Result " << vec_to_string(res2) << endl;
            return false;
        }

        BTSiblingNode<int> *node641 = root1.get()->right.get()->left.get()->right.get()->left.get()->right.get();
        vector<int> ans3 = {641};
        vector<int> res3;
        while (node641 != nullptr) {
            res3.push_back(node641->data);
            node641 = node641->next;
        }
        if (res3 != ans3) {
            cout << "Should be " << vec_to_string(ans3) << endl;
            cout << "Result " << vec_to_string(res3) << endl;
            return false;
        }

        return true;
    }

  } // chapter10
} // epi
