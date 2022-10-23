/*
 * [Source] https://leetcode.com/problems/find-mode-in-binary-search-tree/
 * [Difficulty]: Easy
 * [Tag]: Tree
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]: Mode is the number that shows most often than other numbers
// [Corner Case]:
class SolutionONSpace {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> nodeCnt;
        traverse(root, nodeCnt);

        int maxCnt = 0;
        for (auto it = nodeCnt.begin(); it != nodeCnt.end(); ++it) {
             maxCnt = max(maxCnt, it->second);
        }

        vector<int> res;
        for (auto it = nodeCnt.begin(); it != nodeCnt.end(); ++it) {
            if (it->second == maxCnt)
                res.push_back(it->first);
        }
        return res;
    }

    void traverse(TreeNode *node, unordered_map<int, int> &nodeCnt) {
        if (node == NULL)
            return;

        ++nodeCnt[node->val];
        traverse(node->left, nodeCnt);
        traverse(node->right, nodeCnt);
    }
};

// [Solution]: In order traverse. Maintain a count and current number
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if (root == NULL)
            return candidates_;

        // get first node
        TreeNode *first = root;
        while (first->left != NULL)
            first = first->left;

        // use global vars to transmit info
        num_ = first->val;
        cnt_ = 0;
        maxCnt_ = 0;

        inorder(root);
        // deal with the last number
        if (cnt_ > maxCnt_)
            return {num_};
        if (cnt_ == maxCnt_)
            candidates_.push_back(num_);

        return candidates_;
    }

private:
    void inorder(TreeNode *node) {
        if (node == NULL)
            return;

        inorder(node->left);

        // traverse the tree like an array
        if (node->val == num_) {
            ++cnt_;
        } else {
            if (cnt_ == maxCnt_) {
            candidates_.push_back(num_);
            } else if (cnt_ > maxCnt_) {
                maxCnt_ = cnt_;
                candidates_ = {num_};
            }
            num_ = node->val;
            cnt_ = 1;
        }

        inorder(node->right);
    }

    int num_;
    int cnt_;
    int maxCnt_;
    vector<int> candidates_;
};

int main() {
    Solution sol;

    return 0;
}
