/*
 * [Source] https://leetcode.com/problems/delete-node-in-a-bst/
 * [Difficulty]: Medium
 * [Tag]: Tree
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]: Should use reference of the node
// [Corner Case]:
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *dummy = new TreeNode(INT_MAX);
        dummy->left = root;

        vector<TreeNode*> nodes = search(dummy, key);
        TreeNode *node = nodes[0], *par = nodes[1];
        if (node == NULL)
            return root;

        if (node->right == NULL) {
            // no right child, use left child to replace it
            if (node->left == NULL) {
                if (node == par->left)
                    par->left = NULL;
                else
                    par->right = NULL;
                //delete node;
            } else {
                TreeNode *left = node->left;
                node->val = left->val;
                node->left = left->left;
                node->right = left->right;
                //delete left;
            }
       } else if (node->right->left == NULL) {
            // right child doesn't have left child, use right child to replace it
            TreeNode *right = node->right;
            node->val = right->val;
            node->right = right->right;
            //delete right;
        } else {
            // right child has left child, use left most child to replace it
            TreeNode *pre = node->right, *cur = node->right->left;
            while (cur->left != NULL) {
                pre = cur;
                cur = cur->left;
            }
            node->val = cur->val;
            pre->left = cur->right; // use right node to replace this node
            //delete cur;
        }

        TreeNode *newRoot = dummy->left;
        delete dummy;
        return newRoot;
    }

    vector<TreeNode*> search(TreeNode *root, int key) {
        TreeNode *par = root;
        while (root != NULL) {
            if (root->val == key)
                break;
            if (root->val > key) {
                par = root;
                root = root->left;
            } else {
                par = root;
                root = root->right;
            }
        }
        return {root, par};
    }
};

// [Solution]:
/* Java solution

 */

void inorder(TreeNode *node) {
    if (!node)
        return;
    cout << node->val << " ";
    inorder(node->left);
    inorder(node->right);
}

int main() {
    Solution sol;

    TreeNode n1(5), n2(3), n3(6), n4(2), n5(4), n6(7);
    n1.left = &n2; n1.right = &n3;
    n2.left = &n4; n2.right = &n5;
    n3.right = &n6;

    TreeNode *root = sol.deleteNode(&n1, 2);
    inorder(root);
    cout << endl;

    return 0;
}
