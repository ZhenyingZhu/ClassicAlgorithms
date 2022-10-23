#include <iostream>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-224642-1-1.html
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    int rob(TreeNode *root) {
        RobStatus rs = helper(root);
        return max(rs.rob, rs.notRob);
    }

private:
    struct RobStatus {
        int rob;
        int notRob;
    };

    RobStatus helper(TreeNode *node) {
        if (node == NULL)
            return {0, 0};

        RobStatus left = helper(node->left);
        RobStatus right = helper(node->right);

        int notRob = left.rob + right.rob;
        int rob = max(notRob, node->val + left.notRob + right.notRob);
        return {rob, notRob};
    }
};

int main() {
    Solution sol;

    TreeNode n0(4), n1(1), n2(2), n3(3);
    n0.left = &n1;
    n1.right = &n2;
    n2.right = &n3;

    cout << sol.rob(&n0) << endl;

    return 0;
}
