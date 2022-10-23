/*
 * [Source] https://leetcode.com/problems/binary-search-tree-iterator/
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Stack
 * [Tag]: Design
 */

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]: Use a stack. First push all nodes on the left path. Then when get nodes, pop the first one in stack, and then push all nodes on the left path of its right child
// [Corner Case]:
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root != NULL) {
            visiting.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !visiting.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *cur = visiting.top();
        visiting.pop();
        TreeNode *nxt = cur->right;
        while (nxt != NULL) {
            visiting.push(nxt);
            nxt = nxt->left;
        }
        return cur->val;
    }

private:
    stack<TreeNode*> visiting;
};

class Solution {
public:
    void traverse(TreeNode *root) {
        BSTIterator i = BSTIterator(root);
        while (i.hasNext()) {
            cout << i.next() << "->";
        }
        cout << endl;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n4.left = &n2; n4.right = &n5;
    n2.left = &n1; n2.right = &n3;
    sol.traverse(&n4);

    return 0;
}
