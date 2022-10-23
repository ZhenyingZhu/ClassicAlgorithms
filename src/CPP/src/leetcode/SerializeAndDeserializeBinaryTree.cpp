/*
 * [Source] https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
 * [Difficulty]: Hard
 * [Tag]: Tree
 * [Tag]: Design
 */

#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

// [Solution]: Use in order traverse. Notice need push to stack in reverse order. when reach null child, cannot print, still push to stack
// [Corner Case]:
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "";

        string str;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *cur = stk.top();
            stk.pop();

            if (cur == NULL) {
                str += "null,";
                continue;
            }

            str += to_string(cur->val) + ",";

            stk.push(cur->right);
            stk.push(cur->left);
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0)
            return NULL;

        vector<string> vec = split(data);
        size_t idx = 0;
        return helper(vec, idx);
    }

    TreeNode* helper(vector<string>& vec, size_t& idx) {
        if (idx >= vec.size())
            return NULL;

        string& cur = vec[idx];
        if (cur == "null")
            return NULL;

        int val = stoi(cur);
        TreeNode* n = new TreeNode(val);
        n->left = helper(vec, ++idx);
        n->right = helper(vec, ++idx);

        return n;
    }

    vector<string> split(string& data) {
        vector<string> vec;
        size_t st = 0;
        size_t find = data.find_first_of(",");
        while (find != string::npos) {
            vec.push_back(data.substr(st, find - st));
            st = find + 1;
            find = data.find_first_of(",", st);
        }
        vec.push_back(data.substr(st));
        return vec;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Codec codec;

    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
    n1.left = &n2; n1.right = &n3;
    n2.right = &n6;
    n3.left = &n4; n3.right = &n5;

    string s = codec.serialize(&n1);
    cout << s << endl;
    TreeNode *n1p = codec.deserialize(s);
    cout << n1p->val << endl;
    cout << n1p->left->right->val << endl;
    cout << n1p->right->right->val << endl;

    return 0;
}
