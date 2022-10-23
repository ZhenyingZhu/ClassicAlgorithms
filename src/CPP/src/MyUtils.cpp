#include "MyUtils.h"

#include <fstream>
#include <vector>
#include <memory>
#include <iostream>

#include "BinaryTreeNode.h"
#include "BSTNode.h"

using std::ifstream;
using std::string;
using std::vector;
using std::unique_ptr;
using std::move;

namespace myutils {

extern ifstream& open_file(ifstream &in, char *file) {
    // Open a file by name and bind it to a stream.
    in.close();
    in.clear();
    in.open(file);
    return in;
}

extern string make_plural(size_t ctr, const string &word, const string &ending) {
    // Return a the plural form of a word
    return (ctr == 1) ? word : word + ending;
}

extern unique_ptr<BinaryTreeNode<int>> createPreOrderIntBTree(const vector<int> &vec, size_t *pos) {
    // use INTMAX to indicate a null ptr
    if (*pos >= vec.size() || vec[*pos] == myutils::BTNULL) {
        return nullptr;
    }

    unique_ptr<BinaryTreeNode<int>> root( new BinaryTreeNode<int>{vec[*pos]} );
    root.get()->parent = nullptr;
    ++(*pos);
    root.get()->left = move( createPreOrderIntBTree(vec, pos) );
    if (root.get()->left)
        root.get()->left.get()->parent = root.get();
    ++(*pos);
    root.get()->right = move( createPreOrderIntBTree(vec, pos) );
    if (root.get()->right)
        root.get()->right.get()->parent = root.get();

    return root;
}

extern unique_ptr<BSTNode<int>> createPreOrderIntBST(const vector<int> &vec, size_t *pos) {
    // use INTMAX to indicate a null ptr
    if (*pos >= vec.size() || vec[*pos] == myutils::BST_INT_NULL) {
        return nullptr;
    }

    unique_ptr<BSTNode<int>> root( new BSTNode<int>{vec[*pos]} );
    ++(*pos);
    root.get()->left = move( createPreOrderIntBST(vec, pos) );
    ++(*pos);
    root.get()->right = move( createPreOrderIntBST(vec, pos) );

    return root;
}

unique_ptr<BSTNode<int>> preorderBSTHelper(const vector<int> &preorderSeq,
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

extern unique_ptr<BSTNode<int>> createBSTFromPreorder(const vector<int> &preorderSeq) {
    size_t pos = 0;
    size_t &p = pos;
    return preorderBSTHelper(preorderSeq, p, INT_MIN, INT_MAX);
}

extern void traversePreInOrder(unique_ptr<BinaryTreeNode<int>> &tree,
        vector<int> &preorder, vector<int> &inorder) {
    if (!tree)
        return;

    auto *node = tree.get();
    preorder.push_back(node->data);
    if (node->left)
        traversePreInOrder(node->left, preorder, inorder);
    inorder.push_back(node->data);
    if (node->right)
        traversePreInOrder(node->right, preorder, inorder);
}

} // myutils
