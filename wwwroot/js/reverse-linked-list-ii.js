/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} left
 * @param {number} right
 * @return {ListNode}
 */
var reverseBetween = function(head, left, right) {
    let dummy = new ListNode(0);
    dummy.next = head;

    let cur = dummy;
    let prev = null;
    let idx = 0;
    while (idx++ < left) {
        prev = cur;
        cur = cur.next;
    }

    while (idx++ <= right) {
        let next = cur.next;
        cur.next = next.next;
        next.next = prev.next;
        prev.next = next;
    }

    return dummy.next;
};

document.getElementById("reverse-linked-list-ii").innerHTML =
    traverseListNode(reverseBetween(createList([1, 2, 3, 4, 5]), 1, 5));
