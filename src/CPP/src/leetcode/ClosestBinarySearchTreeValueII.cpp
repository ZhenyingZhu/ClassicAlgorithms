/*
 * [Source] https://leetcode.com/problems/closest-binary-search-tree-value-ii/
 * [Difficulty]: Hard
 * [Tag]: Tree
 * [Tag]: Stack
 */

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]: Use two stacks to store path to the closest node, which are parents. Then call find pre and find succ to find previous k nodes and next k nodes, and then merge the result
// [Corner Case]:
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*> succStack;
        TreeNode *cur = root, *closest = root;
        while (cur != NULL) {
            if ( abs(target - cur->val) < abs(target - closest->val) )
                closest = cur;
            succStack.push(cur);
            if ((double)cur->val > target) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        while (succStack.top() != closest)
            succStack.pop();
        stack<TreeNode*> predStack = succStack;

        vector<int> succes = getNext(succStack, k, true);
        vector<int> predes = getNext(predStack, k, false);
        return merge(succes, predes, target, k);
    }

    vector<int> getNext(stack<TreeNode*> &stack, int k, bool succ) {
        vector<int> res;
        while (!stack.empty() && (int)res.size() < k) {
            TreeNode *cur = stack.top();
            res.push_back(cur->val);
            stack.pop();

            if (nextChild(cur, succ) != NULL) {
                stack.push(cur); // it needs access as parent
                cur = nextChild(cur, succ);
                while (cur != NULL) {
                    stack.push(cur);
                    cur = prevChild(cur, succ);
                }
            } else if (stack.empty()) {
                break; // last node
            } else if ( cur == nextChild(stack.top(), succ) ) {
                while (!stack.empty() && nextChild(stack.top(), succ) == cur) {
                    cur = stack.top();
                    stack.pop();
                }
            } // else if (cur = prevChild(stack.top()) next is the parent of cur, so do nothing
        }
        return res;
    }

    TreeNode* nextChild(TreeNode *cur, bool succ) {
        if (succ)
            return cur->right;
        else
            return cur->left;
    }

    TreeNode* prevChild(TreeNode *cur, bool succ) {
        if (succ)
            return cur->left;
        else
            return cur->right;
    }

    vector<int> merge(vector<int> &succ, vector<int> &pred, double target, int k) {
        int ps = 0, pp = 0;
        // notice succ[0] is same as pred[0]
        if ((double)succ[0] < target)
            ps = 1;
        else
            pp = 1;

        vector<int> res;
        while ((int)res.size() < k) {
            if (ps == (int)succ.size()) {
                res.push_back(pred[pp++]);
            } else if (pp == (int)pred.size()) {
                res.push_back(succ[ps++]);
            } else if ((double)succ[ps] - target < target - (double)pred[pp]) {
                res.push_back(succ[ps++]);
            } else {
                res.push_back(pred[pp++]);
            }
        }
        return res;
    }
};

// [Solution]: Use a k size list to store the result. If the list is full and the head is not closer than the tail, replace head, otherwise return.

int main() {
    Solution sol;

    TreeNode n0(0), n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);
    n5.left = &n3; n5.right = &n6;
    n3.left = &n1; n3.right = &n4;
    n3.left = &n1; n3.right = &n4;
    n1.left = &n0; n1.right = &n2;
    n6.left = &n7;

    for (int &i : sol.closestKValues(&n5, 5.0, 8))
        cout << i << " ";
    cout << endl;

    return 0;
}
