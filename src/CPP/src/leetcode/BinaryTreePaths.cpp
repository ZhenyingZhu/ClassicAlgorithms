/*
 * [Source] https://leetcode.com/problems/binary-tree-paths/
 * [Difficulty]: Easy
 * [Tag]: Tree
 * [Tag]: Dpeth-first Search
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]: Backtracking
// [Corner Case]:
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL)
            return res;

        btPathsHelper(root, "", res);
        return res;
    }

    void btPathsHelper(TreeNode* node, string pre, vector<string>& res) {
        pre += to_string(node->val);
        if (node->left == NULL && node->right == NULL) {
            res.push_back(pre);
            return;
        }

        pre += "->";
        if (node->left != NULL)
            btPathsHelper(node->left, pre, res);
        if (node->right != NULL)
            btPathsHelper(node->right, pre, res);
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    TreeNode n1(1), n2(2), n3(3), n5(5);
    n1.left = &n2; n1.right = &n3;
    n2.right = &n5;

    vector<string> res = sol.binaryTreePaths(&n1);
    for (string& s : res)
        cout << s << endl;

    return 0;
}
