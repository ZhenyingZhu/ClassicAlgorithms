/*
 * [Source] https://leetcode.com/problems/count-complete-tree-nodes/
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Binary Search
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

// [Solution]: Since it is complete tree, the expect node numbers is 2^depth-1. Find if those depth-1 nodes have both left and right nodes. If not, minus from total nodes.
// [Corner Case]:
class SolutionTimeout {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        TreeNode* searchLeft = root;
        int height = 0;
        while (searchLeft != NULL) {
            ++height;
            searchLeft = searchLeft->left;
        }
        int totalNodes = (1 << height) - 1;

        stack<TreeNode*> nodes;
        stack<int> heights;
        nodes.push(root);
        heights.push(1);
        while (!nodes.empty()) {
            TreeNode* cur = nodes.top();
            int h = heights.top();
            nodes.pop();
            heights.pop();

            if (h == height)
                break; // since complete tree meets left leaves
            if (h == height - 1) {
                if (cur->right == NULL)
                    --totalNodes;
                if (cur->left == NULL)
                    --totalNodes;
            }

            if (cur->left != NULL) {
                nodes.push(cur->left);
                heights.push(h + 1);
            }
            if (cur->right != NULL) {
                nodes.push(cur->right);
                heights.push(h + 1);
            }
        }

        return totalNodes;
    }
};

// [Solution]:
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftHeight = countLeftHeight(root->left);
        int rightHeight = countRightHeight(root->right);
        if (leftHeight == rightHeight) {
            int height = leftHeight + 1;
            return (1 << height) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1; // root itself
    }

    int countLeftHeight(TreeNode* node) {
        int h = 0;
        while (node != NULL) {
            ++h;
            node = node->left;
        }
        return h;
    }

    int countRightHeight(TreeNode* node) {
        int h = 0;
        while (node != NULL) {
            ++h;
            node = node->right;
        }
        return h;
    }
};

int main() {
    Solution sol;

    TreeNode n0(0), n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8), n9(9), n10(10), n11(11);
    n0.left = &n1; n0.right = &n2;

    n1.left = &n3; n1.right = &n4;
    n2.left = &n5; n2.right = &n6;

    n3.left = &n7; n3.right = &n8;
    n4.left = &n9; n4.right = &n10;
    n5.left = &n11;

    cout << sol.countNodes(&n0) << endl;

    return 0;
}
