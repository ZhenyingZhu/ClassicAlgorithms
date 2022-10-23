/*
 * [Source] https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * [Difficulty]: Medium
 * [Tag]: Binary Search
 * [Tag]: Tree
 */

#include <iostream>
#include <stack>
#include <climits>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]: Inorder traversal.
// [Corner Case]:
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL)
            return INT_MAX;

        stack<TreeNode*> st;
        unordered_set<TreeNode*> visited;

        st.push(root);
        int i = 0;
        TreeNode* cur;
        while (!st.empty()) {
            cur = st.top();
            st.pop();
            if (visited.find(cur) != visited.end()) {
                ++i;
                if (i == k)
                    return cur->val;
            } else {
                if (cur->right != NULL)
                    st.push(cur->right);
                st.push(cur);
                if (cur->left != NULL)
                    st.push(cur->left);

                visited.insert(cur);
            }
        }

        return cur->val;
    }
};

// [Solution]: If need repeatly called, store number of subnodes on root, and do binary search

int main() {
    Solution sol;

    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n4.left = &n2; n4.right = &n5;
    n2.left = &n1; n2.right = &n3;

    for (int i = 1; i <= 6; ++i) {
        cout << sol.kthSmallest(&n4, i) << endl;
    }

    return 0;
}
