#include "BinarySearchTree.hpp"

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
using myutils::createBSTFromPreorder;
using myutils::vec_to_string;
using std::runtime_error;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter15 {
    class BinarySearchTree::BST {
    public:
        BST(std::unique_ptr<myutils::BSTNode<int>> &tree) {
            root_ = move(tree);
        }

        std::unique_ptr<myutils::BSTNode<int>>& getRoot();

        bool bstInsert(int key);

        bool bstDelete(int key);

    private:
        std::unique_ptr<myutils::BSTNode<int>> root_;

    };

    unique_ptr<BSTNode<int>>& BinarySearchTree::BST::getRoot() {
        return root_;
    }

    bool BinarySearchTree::BST::bstInsert(int key) {
        unique_ptr<BSTNode<int>> node(new BSTNode<int>(key));

        if (root_ == nullptr) {
            root_ = move(node);
            return true;
        }

        BSTNode<int> *cur = root_.get();
        while (cur) {
            if (cur->data == key) {
                return false;
            } else if (cur->data < key) {
                if (cur->right == nullptr) {
                    cur->right = move(node);
                    return true;
                } else {
                    cur = cur->right.get();
                }
            } else {
                if (cur->left == nullptr) {
                    cur->left = move(node);
                    return true;
                } else {
                    cur = cur->left.get();
                }
            }
        }

        throw runtime_error("Shouldn't reach this code");
    }

    bool BinarySearchTree::BST::bstDelete(int key) {
        if (root_ == nullptr)
            return false;

        BSTNode<int> *node = root_.get(), *prev = nullptr;
        while (node) {
            if (node->data == key) {
                break;
            } else if (node->data > key) {
                prev = node;
                node = node->left.get();
            } else {
                prev = node;
                node = node->right.get();
            }
        }

        if (!node)
            return false;

        if (node->right) {
            BSTNode<int> *successor = node->right.get(), *preSucc = node;
            while (successor->left != nullptr) {
                preSucc = successor;
                successor = successor->left.get();
            }
            node->data = successor->data;
            if (preSucc == node) {
                preSucc->right.reset(successor->right.release());
            } else {
                preSucc->left.reset(successor->right.release());
            }
        } else {
            if (root_.get() == node) {
                root_.reset(root_.get()->left.release());
            } else {
                if (prev->left.get() == node) {
                    prev->left.reset(node->left.release());
                } else {
                    prev->right.reset(node->left.release());
                }
            }
        }

        return true;
    }

    bool BinarySearchTree::test() {
        vector<int> preOrder = {19, 7, 3, 2, 5, 11, 17, 13, 43, 23, 37, 29, 31, 41, 47, 53};
        unique_ptr<BSTNode<int>> tree = createBSTFromPreorder(preOrder);

        BST bst(tree);

        if ( !bst.bstInsert(9) ) {
            cout << "Failed to insert" << endl;
            return false;
        }
        unique_ptr<BSTNode<int>> &root = bst.getRoot();
        if (root.get()->left.get()->right.get()->left.get()->data != 9) {
            cout << "The place for inserted node is not the right node " << endl;
            return false;
        }

        if ( !bst.bstDelete(43) ) {
            cout << "Failed to delete" << endl;
            return false;
        }

        if (root.get()->right.get()->data != 47) {
            cout << "The place for delete node is not the right node " << endl;
            return false;
        }

        return true;
    }

  } // chapter15
} // epi
