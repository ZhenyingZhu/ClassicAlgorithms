#include <iostream>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-214001-1-1.html
struct Node {
    int val;
    Node *left, *right;
    Node *prev, *next;
    Node(int x): val(x), left(NULL), right(NULL), prev(NULL), next(NULL) { }
};

class Solution {
public:
    // link the BST nodes with prev and next. Return the head
    Node* link(Node *root) {
        Node *prev = NULL;
        inorder(root, prev);
        Node *cur = root;
        while (cur->left != NULL)
            cur = cur->left;
        return cur;
    }

    // insert a node into BST and link prev and next. Return root
    Node* insert(Node *root, int value) {
        Node *node = new Node(value);
        if (root == NULL)
            return node;

        Node *cur = root, *parent;
        while (cur != NULL) {
            parent = cur;
            if (value > cur->val)
                cur = cur->right;
            else
                cur = cur->left;
        }

        if (value > parent->val) {
            node->prev = parent;
            node->next = parent->next;
            if (parent->next != NULL)
                parent->next->prev = node;
            parent->next = node;

            parent->right = node;
        } else { // left child can be smaller than or same to the node
            node->next = parent;
            node->prev = parent->prev;
            if (parent->prev != NULL)
                parent->prev->next = node;
            parent->prev = node;

            parent->left = node;
        }

        return root;
    }

private:
    void inorder(Node *node, Node* &prev) {
        if (node == NULL)
            return;

        inorder(node->left, prev);

        if (prev != NULL) {
            prev->next = node;
            node->prev = prev;
        }
        prev = node;

        inorder(node->right, prev);
    }


};

void traverse(Node *node) {
    if (node == NULL)
        cout << "#->";
    else {
        cout << node->val << "->";
        traverse(node->left);
        traverse(node->right);
    }
}

int main() {
    Solution sol;

    Node n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
    n4.left = &n2; n4.right = &n6;
    n2.left = &n1; n2.right = &n3;
    n6.left = &n5;

    Node *head = sol.link(&n4), *tail;

    sol.insert(&n4, 3);

    traverse(&n4);
    cout << endl;

    while (head != NULL) {
        cout << head->val << " ";
        tail = head;
        head = head->next;
    }
    cout << endl;
    while (tail != NULL) {
        cout << tail->val << " ";
        tail = tail->prev;
    }
    cout << endl;

    return 0;
}
