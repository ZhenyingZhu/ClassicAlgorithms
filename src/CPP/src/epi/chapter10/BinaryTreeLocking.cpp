#include "BinaryTreeLocking.hpp"

#include <memory>
#include <vector>
#include <assert.h>
#include <stdexcept>
#include <iostream>

#include "../../MyUtils.h"

using std::shared_ptr;
using std::vector;
using std::invalid_argument;
using myutils::createPreOrderIntBTree;
using myutils::vec_to_string;
using myutils::BTNULL;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter10 {
    class BinaryTreeLocking::BinaryTreeNode {
    public:
        BinaryTreeNode(int d): data_(d), locked_(false), numLockedDescendants_(0) { }

        bool isLocked() const {
            return locked_;
        }

        bool lock() {
            if (numLockedDescendants_ > 0 || locked_)
                return false;

            for (auto iter = parent_; iter != nullptr; iter = iter->parent_) {
                if (iter->isLocked())
                    return false;
            }

            locked_ = true;
            for (auto iter = parent_; iter != nullptr; iter = iter->parent_) {
                ++iter->numLockedDescendants_;
            }

            return true;
        }

        void unlock() {
            if (!isLocked())
                return;

            locked_ = false;
            for (auto iter = parent_; iter != nullptr; iter = iter->parent_) {
                --iter->numLockedDescendants_;
            }
        }

        int getData() const {
            return data_;
        }

        shared_ptr<BinaryTreeNode> getLeft() {
            return left_;
        }

        void setLeft(shared_ptr<BinaryTreeNode> node) {
            left_ = node;
        }

        shared_ptr<BinaryTreeNode> getRight() {
            return right_;
        }

        void setRight(shared_ptr<BinaryTreeNode> node) {
            right_ = node;
        }

        shared_ptr<BinaryTreeNode> getParent() {
            return parent_;
        }

        void setParent(shared_ptr<BinaryTreeNode> node) {
            parent_ = node;
        }

    private:
        int data_;
        shared_ptr<BinaryTreeNode> left_, right_, parent_;
        bool locked_ = false;
        int numLockedDescendants_ = 0;
    };

    shared_ptr<BinaryTreeLocking::BinaryTreeNode> BinaryTreeLocking::createPreOrderIntBTree(
            const vector<int> &vec, size_t *pos) {
        if (*pos >= vec.size() || vec[*pos] == BTNULL) {
            return nullptr;
        }

        shared_ptr<BinaryTreeNode> root( new BinaryTreeNode(vec[*pos]) );
        ++(*pos);
        root->setLeft(createPreOrderIntBTree(vec, pos));
        if (root->getLeft())
            root->getLeft()->setParent(root);
        ++(*pos);
        root->setRight(createPreOrderIntBTree(vec, pos));
        if (root->getRight())
            root->getRight()->setParent(root);

        return root;
    }

    bool BinaryTreeLocking::test() {
        vector<int> preOrder1 = {314, 6, 271, 28, BTNULL, BTNULL, 0, BTNULL, BTNULL,
                561, BTNULL, 3, 17, BTNULL, BTNULL, BTNULL,
                6, 2, BTNULL, 1, 401, BTNULL, 641, BTNULL, BTNULL, 257, BTNULL, BTNULL,
                271, BTNULL, 28
        };
        size_t pos = 0;
        shared_ptr<BinaryTreeNode> root1 = createPreOrderIntBTree(preOrder1, &pos);
        shared_ptr<BinaryTreeNode> node561 = root1->getLeft()->getRight();
        if (!node561->lock()) {
            cout << "Cannot lock node " << node561->getData() << endl;
            return false;
        }

        shared_ptr<BinaryTreeNode> node3 = node561->getRight();
        if (node3->lock()) {
            cout << "Lock node " << node3->getData() << " succeed by mistake" << endl;
            return false;
        }

        shared_ptr<BinaryTreeNode> node6 = node561->getParent();
        if (node6->lock()) {
            cout << "Lock node " << node6->getData() << " succeed by mistake" << endl;
            return false;
        }

        return true;
    }

  } // chapter10
} // epi
