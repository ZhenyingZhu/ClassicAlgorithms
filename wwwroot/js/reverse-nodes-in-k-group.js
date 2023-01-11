/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var reverseKGroup = function(head, k) {
    if (k <= 1) {
        return head;
    }

    let dummy = new ListNode(0);
    let pre = dummy;
    let cur = head;

    while (cur != null) {
        let kRemains = true;
        let next = cur;
        for (let i = 0; i < k; i++) {
            if (next === null) {
                kRemains = false;
                break;
            }
            next = next.next;
        }

        if (!kRemains) {
            break;
        }

        pre.next = reverseKNodes(cur, k);
        pre = cur;
        cur.next = next;
        cur = next;
    }

    return dummy.next;
};

const reverseKNodes = function(node, k) {
    let pre = node;
    let cur = node.next;
    pre.next = null;
    for (let i = 0; i < k - 1; i++) {
        let next = cur.next;
        cur.next = pre;
        pre = cur;
        cur = next;
    }

    return pre;
};

document.getElementById("reverse-nodes-in-k-group").innerHTML = traverseListNode(reverseKGroup(createList([1,2,3,4,5,6,7,8,9]), 3));