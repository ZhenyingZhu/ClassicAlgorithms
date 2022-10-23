#include <iostream>
#include <vector>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-225639-1-1.html

struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode(int x): val(x) { }
};

class Solution {
public:
    int longestPath(TreeNode *root) {
        if (root == NULL)
            return 0;

        int maxLen = 1;
        helper(root, root->val - 1, 0, maxLen);
        return maxLen;
    }

    void helper(TreeNode *node, int prev, int cnt, int &maxLen) {
        if (node->val == prev + 1) {
            ++cnt;
            maxLen = max(maxLen, cnt);
        } else {
            cnt = 1;
        }

        for (TreeNode *child : node->children) {
            helper(child, node->val, cnt, maxLen);
        }
    }
};

int main() {
    Solution sol;

    TreeNode n0(0), n1(1), n2(2), n3(3), n4(4), n5(5);
    n0.children.push_back(&n1);
    n0.children.push_back(&n4);
    n1.children.push_back(&n2);
    n2.children.push_back(&n3);
    n4.children.push_back(&n5);

    cout << sol.longestPath(&n0) << endl;

    return 0;
}
