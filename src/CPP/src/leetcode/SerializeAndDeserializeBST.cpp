/*
 * [Source] https://leetcode.com/problems/serialize-and-deserialize-bst/
 * [Difficulty]: Medium
 * [Tag]: Tree
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]: Standard serialize way
// [Corner Case]:
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        serialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return deserialize(data, idx);
    }

private:
    void serialize(TreeNode *node, string &res) {
        if (node == NULL) {
            res += "N|";
            return;
        }
        res += to_string(node->val) + "|";
        serialize(node->left, res);
        serialize(node->right, res);
    }

    TreeNode* deserialize(string &data, int &idx) {
        if (idx == (int)data.length())
            return NULL;

        if (data[idx] == 'N') {
            idx += 2; // skip N and |
            return NULL;
        }

        int val = 0;
        while (isdigit(data[idx]))
            val = val * 10 + data[idx++] - '0';
        TreeNode *node = new TreeNode(val);

        ++idx; // is |
        node->left = deserialize(data, idx);
        node->right = deserialize(data, idx);
        return node;
    }
};

class Solution {
public:
    void test() {
        TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
        n1.left = &n2; n1.right = &n3;
        n2.left = &n4;
        n3.right = &n5;

        Codec c;
        string s = c.serialize(&n1);
        cout << s << endl;
        TreeNode *root = c.deserialize(s);

        inorder(root);
        cout << endl;
    }

    void inorder(TreeNode *node) {
        if (node == NULL)
            return;
        cout << node->val << " ";
        inorder(node->left);
        inorder(node->right);
    }
};

// [Solution]: Since it is BST, so inorder is guranetee. Use a serialize of preorder can do the job
/* Java solution

 */

int main() {
    Solution sol;
    sol.test();

    return 0;
}
