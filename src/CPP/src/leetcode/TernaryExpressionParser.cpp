/*
 * [Source] https://leetcode.com/problems/ternary-expression-parser/
 * [Difficulty]: Medium
 * [Tag]: Depth-first Search
 * [Tag]: Stack
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Build a tree.
// [Corner Case]:
class Solution {
public:
    struct Node {
        Node(char a): c(a) {
            left = NULL;
            right = NULL;
        }

        ~Node() {
            if (left != NULL)
                delete left;
            if (right != NULL)
                delete right;
        }

        char c;
        Node *left;
        Node *right; 
    };

    string parseTernary(string expression) {
        if (expression.length() <= 1)
            return expression;

        int idx = 0;
        Node *root = parseTree(expression, idx);

        char res = '*';
        Node *cur = root;
        while (cur != NULL) {
            res = cur->c;
            if (cur->c == 'T')
                cur = cur->left;
            else if (cur->c == 'F')
                cur = cur->right;
            else
                break;
        }

        delete root;
        return string(1, res);
    }

    Node* parseTree(string &expression, int &idx) {
        Node *node = new Node(expression[idx++]);

        if (idx == (int)expression.length() || expression[idx] == ':')
            return node;

        ++idx; // should be ?
        Node *left = parseTree(expression, idx);
        ++idx; // should be :
        Node *right = parseTree(expression, idx);
        node->left = left;
        node->right = right;

        return node;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //cout << sol.parseTernary("T?T?1:2:T?3:4") << endl;
    //cout << sol.parseTernary("T?T:T?3:4") << endl;
    cout << sol.parseTernary("F?T:T?3:4") << endl;

    return 0;
}
