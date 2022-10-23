/*
 * [Source] https://leetcode.com/problems/construct-binary-tree-from-string
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: String
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) { }
};

// [Solution]: 
class Solution {
public:
    TreeNode* str2tree(string s) {
        int idx = 0;
        return construct(s, idx);
    }

    TreeNode* construct(string &s, int &idx) {
        if (idx == (int)s.length())
            return NULL;

        int num = 0, sign = 1;
        if (s[idx] == '-') {
            sign = -1;
            ++idx;
        }

        while (idx < (int)s.length() && isdigit(s[idx]))
            num = num * 10 + sign * (s[idx++] - '0');

        TreeNode *node = new TreeNode(num);
        if (idx == (int)s.length() || s[idx] == ')')
            return node;

        ++idx; // '('
        node->left = construct(s, idx);
        ++idx; // ')'
        if (idx == (int)s.length() || s[idx] == ')')
            return node;

        ++idx; // '('
        node->right = construct(s, idx);
        ++idx; // ')'

        return node;
    }
};

void preorder(TreeNode *root) {
    if (root == NULL) {
        cout << "#,";
        return;
    }
    cout << root->val << ",";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Solution sol;

    //TreeNode *root = sol.str2tree("1(2(3))");
    TreeNode *root = sol.str2tree("-4(2(3)(1))(6(5))");
    preorder(root);
    cout << endl;

    return 0;
}
