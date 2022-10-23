#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// [Source]: http://www.meetqun.net/thread-44981-1-1.html
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// http://www.1point3acres.com/bbs/thread-223433-1-1.html

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    string serialize(TreeNode *root) {
        string res;
        if (root == NULL)
            return res;

        stack<TreeNode*> visiting;
        visiting.push(root);

        while (!visiting.empty()) {
            TreeNode *cur = visiting.top();
            visiting.pop();

            if (cur == NULL) {
                res += "#,";
                continue;
            }

            res += to_string(cur->val) + ",";

            visiting.push(cur->right);
            visiting.push(cur->left);
        }

        return res;
    }

    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;
        vector<string> vec = split(data, ",");
        int idx = 0;
        return helper(vec, idx);
    }

    TreeNode* helper(vector<string> &vec, int &idx) {
        if (idx == (int)vec.size())
            return NULL;

        if (vec[idx] == "#") {
            ++idx;
            return NULL;
        }

        TreeNode *cur = new TreeNode(stoi(vec[idx++]));
        cur->left = helper(vec, idx);
        cur->right = helper(vec, idx);
        return cur;
    }

    vector<string> split(string &data, string token) {
        vector<string> res;
        int st = 0;
        size_t pos = data.find_first_of(token);
        while (pos != string::npos) {
            res.push_back(data.substr(st, pos - st));
            st = pos + 1;
            pos = data.find_first_of(token, st);
        }
        res.push_back(data.substr(st));
        return res;
    }
};

void traverse(TreeNode *node) {
    if (node == NULL)
        return;
    cout << node->val << " ";
    traverse(node->left);
    traverse(node->right);
}

int main() {
    TreeNode n0(0), n1(1), n2(2), n3(3), n4(4);
    n0.left = &n1; n0.right = &n2;
    n1.left = &n3; n1.right = &n4;

    Solution sol;
    /*
    string res = sol.serialize(&n0);
    cout << res << endl;
    TreeNode *root = sol.deserialize(res);
    traverse(root);
    */
    string res = sol.serialize(NULL);
    cout << res << endl;
    TreeNode *root = sol.deserialize(res);
}

