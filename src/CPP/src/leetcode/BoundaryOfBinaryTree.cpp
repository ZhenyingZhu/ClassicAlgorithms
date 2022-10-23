/*
 * [Source] https://leetcode.com/problems/boundary-of-binary-tree
 * [Difficulty]: Medium
 * [Tag]: Tree
 */

#include <iostream>
#include <vector>
#include <algorithm>

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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;

        res.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
            return res; // otherwise getLeaves push root again

        if (root->left != NULL) {
            getLeftMostPath(root->left, res);
            res.pop_back(); // because get leaves push it again
        }

        getLeaves(root, res);

        if (root->right != NULL) {
            res.pop_back(); // because get right most push it again
            int size = res.size();
            getRightMostPath(root->right, res);
            reverse(res.begin() + size, res.end()); // testcase: if no rightmost
        }

        return res;
    }

    void getLeftMostPath(TreeNode *node, vector<int> &res) {
        if (node == NULL)
            return;

        res.push_back(node->val);
        if (node->left != NULL)
            getLeftMostPath(node->left, res);
        else
            getLeftMostPath(node->right, res);
    }

    void getRightMostPath(TreeNode *node, vector<int> &res) {
        if (node == NULL)
            return;

        res.push_back(node->val);
        if (node->right != NULL)
            getRightMostPath(node->right, res);
        else
            getRightMostPath(node->left, res);
    }

    void getLeaves(TreeNode *node, vector<int> &res) {
        if (node->left == NULL && node->right == NULL) {
            res.push_back(node->val);
            return;
        }

        if (node->left != NULL)
            getLeaves(node->left, res);
        if (node->right != NULL)
            getLeaves(node->right, res);
    }
};

int main() {
    Solution sol;

    TreeNode n1(1), n2(2), n3(3), n4(4);
    n1.left = &n2;
    n2.left = &n3; n2.right = &n4;

    for (int num : sol.boundaryOfBinaryTree(&n1))
        cout << num << ",";
    cout << endl;

    return 0;
}
