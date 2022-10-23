/*
 * [Source] https://leetcode.com/problems/merge-k-sorted-lists/
 * [Difficulty]: Hard
 * [Tag]: Divide and Conquer
 * [Tag]: Linked List
 * [Tag]: Heap
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// [Solution]: Use a min heap, which take O(logn) to update but O(1) to pop.
// [Corner Case]:
class Solution {
private:
    struct cmp {
        bool operator()(const ListNode* larger, const ListNode* smaller) {
            return larger->val > smaller->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);

        priority_queue< ListNode*, vector<ListNode*>, cmp > minHeap;
        for (ListNode* node : lists) {
            if (node != NULL) {
                minHeap.push(node);
            }
        }

        ListNode* cur = &dummy;
        while (!minHeap.empty()) {
            cur->next = minHeap.top();
            cur = cur->next;

            ListNode* next = minHeap.top()->next;
            minHeap.pop();
            if (next != NULL) {
                minHeap.push(next);
            }
        }

        return dummy.next;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/linkedlist/MergekSortedLists.java
 */

// [Solution]: Merge two lists each time
/* Java solution
public class Solution {
    public ListNode mergeKLists(List<ListNode> lists) {
        if (lists == null || lists.size() == 0) {
            return null; 
        }
        ListNode first = lists.get(0); 
        if (lists.size() == 1) {
            return first; 
        }
        ListNode second; 
        for (int i = 1; i < lists.size(); ++i) {
            second = lists.get(i); 
            first = mergeTwoLists(first, second); 
        }
        return first; 
    }
    
    public ListNode mergeTwoLists(ListNode head1, ListNode head2) {
        ListNode dummy = new ListNode(0); 
        ListNode pt = dummy; 
        ListNode pt1 = head1; 
        ListNode pt2 = head2; 
        while (pt1 != null && pt2 != null) {
            if (pt1.val < pt2.val) {
                pt.next = pt1; 
                pt1 = pt1.next; 
            } else {
                pt.next = pt2; 
                pt2 = pt2.next; 
            }
            pt = pt.next; 
        }
        if (pt1 == null) {
            pt.next = pt2; 
        } else {
            pt.next = pt1; 
        }
        return dummy.next; 
    }
}
 */

int main() {
    Solution sol;

    ListNode n0(0), n1(1), n2(2), n3(3), n4(4);
    
    n0.next = &n1; n1.next = &n3;
    n2.next = &n4;

    vector<ListNode*> lists = {&n0, &n2};
    ListNode* res = sol.mergeKLists(lists);

    while (res != NULL) {
        cout << res->val << "->";
        res = res->next;
    }
    cout << endl;

    return 0;
}
