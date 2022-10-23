#include <iostream>
#include <vector>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-225497-1-1.html
// http://www.1point3acres.com/bbs/thread-203816-1-1.html
// http://www.1point3acres.com/bbs/thread-222643-1-1.html

struct Node {
    Node(int x): val(x), up(NULL), down(NULL), left(NULL), right(NULL) { }
    int val;
    Node *up, *down, *left, *right;
};

// [Solution]: try to insert the whole up or down list to next of current node.
class Solution {
public:
    void flattenList(Node *head, Node *tail) {
        bool noUpDownNodes = false;
        while (!noUpDownNodes) {
Node *tmp = head; while (tmp != NULL) {cout << tmp->val << "->"; tmp = tmp->right; } cout << endl;
            // check if there is a cycle
            Node *slow = head, *fast = head;
            while (fast != NULL && fast->next != NULL) {
                fast = fast->next->next;
                slow = slow->next;
                if (slow == fast) {
                    return; // cycle detected
                }
            }

            // try to merge lists
            noUpDownNodes = true;
            Node *cur = head;
            while (cur != tail) {
                Node *next = cur->right;
                if (cur->up != NULL) {
                    noUpDownNodes = false;
                    // break the link first
                    cur->up->down = NULL;
                    cur->up = NULL;
                    // insert the whole up list to next of the node
                    vector<Node*> upHeadTail = traverse(cur->up);
                    Node *upHead = upHeadTail[0], *upTail = upHeadTail[1];
                    // it might link back to the main list
                    if (upHead == head)
                        continue;
                    cur->right = upHead;
                    upHead->left = cur;
                    upTail->right = next;
                    next->left = upTail;
                } else if (cur->down != NULL) {
                    noUpDownNodes = false;
                    // insert down to next of the node
                    cur->down->up = NULL;
                    cur->down = NULL;
                    vector<Node*> downHeadTail = traverse(cur->down);
                    Node *downHead = downHeadTail[0], *downTail = downHeadTail[1];
                    if (downHead == head)
                        continue;
                    cur->right = downHead;
                    downHead->left = cur;
                    downTail->right = next;
                    next->left = downTail;
                }

                cur = next;
            }
        }
    }

    vector<Node*> traverse(Node *node) {
        Node *head = node, *tail = node;
        while (head->left != NULL)
            head = head->left;
        while (tail->right != NULL)
            tail = tail->right;
        return {head, tail};
    }
};

int main() {
    Solution sol;

    Node n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8), n9(9), n10(10);
    n1.right = &n2; n2.left = &n1;
    n2.right = &n3; n3.left = &n2;
    n3.right = &n4; n4.left = &n3;
    n3.down = &n7; n7.up = &n3;
    n5.right = &n6; n6.left = &n5;
    n7.right = &n8; n8.left = &n7;
    n6.down = &n9; n9.up = &n6;
    n7.down = &n10; n10.up = &n7;
    n9.right = &n10; n10.left = &n9;

    sol.flattenList(&n1, &n4);

    Node *head = &n1;
    Node *tail;
    while (head != NULL) {
        cout << head->val << "->";
        tail = head;
        head = head->right;
    }
    cout << endl;
    while (tail != NULL) {
        cout << tail->val << "<-";
        tail = tail->left;
    }
    cout << endl;

    return 0;
}
