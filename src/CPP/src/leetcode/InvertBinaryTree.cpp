/*
 * [Source] https://leetcode.com/problems/invert-binary-tree/
 * [Difficulty]: Easy
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

// [Solution]:
// [Corner Case]:
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;

        if (root->left == NULL) {
            root->left = root->right;
            root->right = NULL;
        } else if (root->right == NULL) {
            root->right = root->left;
            root->left = NULL;
        } else {
            swap(root->left, root->right);
        }
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    TreeNode n1(1), n2(2), n3(3), n4(4);
    n1.left = &n2; n1.right = &n3;
    n2.left = &n4;
    TreeNode* root = sol.invertTree(&n1);
    cout << root->left->val << endl;
    cout << root->right->right->val << endl;

    return 0;
}
