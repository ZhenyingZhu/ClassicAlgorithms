/*
 * [Source] https://leetcode.com/problems/binary-tree-upside-down/
 * [Difficulty]: Medium
 * [Tag]: Tree
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]: Need pass current root as new right child, current left as new root and current right as new left child
// [Corner Case]: The root node needs to be disconnected
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == NULL || root->left == NULL)
            return root;

        TreeNode *newRoot = helper(root->left, root->right, root);
        root->left = NULL;
        root->right = NULL;
        return newRoot;
    }

    TreeNode* helper(TreeNode *left, TreeNode *right, TreeNode *root) {
        TreeNode *newRoot = left;
        if (left->left != NULL) {
            newRoot = helper(left->left, left->right, left);
        }

        left->left = right;
        left->right = root;
        return newRoot;
    }
};

// [Solution]:
/* Java solution

 */

void traverse(TreeNode *node) {
    if (node == NULL) {
        cout << "#, ";
        return;
    }
    cout << node->val << ", ";
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
    cout << endl;

    return 0;
}
