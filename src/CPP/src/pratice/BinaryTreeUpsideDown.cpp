#include <iostream>

using namespace std;

struct TreeNode {
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
    int val;
    TreeNode *left, *right;
};

// [Source]: https://leetcode.com/problems/binary-tree-upside-down/
// http://www.1point3acres.com/bbs/thread-227305-1-1.html

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode *root) {
        if (root == NULL)
            return NULL;

        TreeNode *left = root->left, *right = root->right;
        root->left = NULL;
        root->right = NULL;
        return helper(root, left, right);
    }

    TreeNode* helper(TreeNode *node, TreeNode *oldLeft, TreeNode *oldRight) {
        if (oldLeft == NULL)
            return node;

        TreeNode *newLeft = oldLeft->left, *newRight = oldLeft->right;

        oldLeft->left = oldRight;
        oldLeft->right = node;
        return helper(oldLeft, newLeft, newRight);
    }
};

void traverse(TreeNode *node) {
    if (node == NULL) {
        cout << "#,";
        return;
    }

    cout << node->val << ",";
    traverse(node->left);
    traverse(node->right);
}

int main() {
    Solution sol;

    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.left = &n2; n1.right = &n3;
    n2.left = &n4; n2.right = &n5;

    TreeNode *root = sol.upsideDownBinaryTree(&n1);
    traverse(root);

    return 0;
}
