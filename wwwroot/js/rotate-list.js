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
var rotateRight = function(head, k) {
    if (head === null) {
        return head;
    }

    let len = 0;
    let cur = head;
    while (cur !== null) {
        cur = cur.next;
        len++;
    }

    k = k % len;
    if (k === 0) {
        return head;
    }

    let cnt = len - k - 1;
    cur = head;
    for (let i = 0; i < cnt; i++) {
        cur = cur.next;
    }

    let res = cur.next;
    let pre = cur;
    while (cur.next !== null) {
        cur = cur.next;
    }
    cur.next = head;
    pre.next = null;


    return res;
};

document.getElementById("rotate-list").innerHTML =
    // traverseListNode(rotateRight(createList([0, 1, 2]), 4));
    traverseListNode(rotateRight(createList([1, 2, 3, 4, 5]), 5));
