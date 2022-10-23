#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    ListNode(int x): val(x), next(NULL) { }
    int val;
    ListNode *next;
};

// [Source]: https://leetcode.com/problems/merge-k-sorted-lists/
// http://www.1point3acres.com/bbs/thread-227329-1-1.html

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        if (lists.empty())
            return NULL;

        priority_queue<NodeVal, vector<NodeVal>, NodeValCmp> pq;
        for (ListNode *node : lists) {
            if (node == NULL)
                continue;
            pq.push( {node->val, node} );
        }

        ListNode dummy(0);
        ListNode *run = &dummy;
        while (!pq.empty()) {
            ListNode *node = pq.top().node;
            pq.pop();
            ListNode *nextNode = node->next;
            if (nextNode != NULL)
                pq.push( {nextNode->val, nextNode} );

            run->next = node;
            run = run->next;
        }

        ListNode *head = dummy.next;
        return head;
    }

private:
    struct NodeVal {
        int val;
        ListNode *node;
    };

    struct NodeValCmp {
        bool operator()(const NodeVal &n1, const NodeVal &n2) {
            return n1.val > n2.val;
        }
    };
};

int main() {
    Solution sol;

    ListNode l0(0), l1(1), l2(2), l3(3), l4(4), l5(5), l6(6);
    l0.next = &l2; l2.next = &l3;
    l1.next = &l4; l4.next = &l6;
    vector<ListNode*> lists = {&l0, &l1, &l5};
    ListNode *head = sol.mergeKLists(lists);

    while (head != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;

    return 0;
}
