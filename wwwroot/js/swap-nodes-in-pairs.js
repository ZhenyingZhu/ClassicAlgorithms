/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function(head) {
    let dummy = new ListNode(0);
    let pre = dummy;
    let cur = head;
    while (cur != null && cur.next != null) {
        let next = cur.next.next;
        pre.next = swapNodes(cur);
        pre = cur;
        cur = next;
    }

    pre.next = cur;
    return dummy.next;
};

const swapNodes = function(node) {
    let next = node.next;
    next.next = node;
    return next;
};

document.getElementById("swap-nodes-in-pairs").innerHTML = traverseListNode(swapPairs(createList([1, 2, 3, 4, 5])));
