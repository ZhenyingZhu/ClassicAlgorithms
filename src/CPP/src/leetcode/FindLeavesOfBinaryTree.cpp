/*
 * [Source] https://leetcode.com/problems/find-leaves-of-binary-tree/
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Depth-first Search
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]: Actually remove leaves
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        while (root != NULL) {
            vector<int> leaves;
            if (dfs(root, leaves)) {
                root = NULL;
            }
            res.push_back(leaves);
        }
        return res;
    }

    bool dfs(TreeNode *node, vector<int> &leaves) {
        if (node == NULL)
            return true;

        if (node->left == NULL && node->right == NULL) {
            leaves.push_back(node->val);
            return true;
        }

        if (dfs(node->left, leaves))
            node->left = NULL;
        if (dfs(node->right, leaves))
            node->right = NULL;
        return false;
    }
};

// [Solution]:
// [Corner Case]:
class SolutionNotRemove {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        helper(root, res);
        return res;
    }

    int helper(TreeNode *node, vector<vector<int>> &res) {
        if (node->left == NULL && node->right == NULL) {
            if (res.empty())
                res.resize(1);
            res[0].push_back(node->val);
            return 0;
        }

        int level = 0;
        if (node->left != NULL)
            level = max(level, helper(node->left, res));
        if (node->right != NULL)
            level = max(level, helper(node->right, res));
        ++level;
        if ((int)res.size() <= level)
            res.resize(level + 1);
        res[level].push_back(node->val);
        return level;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.left = &n2; n1.right = &n3;
    n2.left = &n4; n2.right = &n5;

    for (vector<int> &vec : sol.findLeaves(&n1)) {
        for (int &n : vec)
            cout << n << " ";
        cout << endl;
    }

    return 0;
}
