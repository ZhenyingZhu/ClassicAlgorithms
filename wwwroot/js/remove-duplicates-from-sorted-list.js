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
var deleteDuplicates = function(head) {
    if (head === null) {
        return head;
    }

    let pre = head;
    let val = pre.val;
    let cur = head.next;
    while (cur !== null) {
        if (cur.val !== val) {
            pre.next = cur;
            pre = cur;
            val = cur.val;
        } else {
            pre.next = null;
        }

        cur = cur.next;
    }

    return head;
};

document.getElementById("remove-duplicates-from-sorted-list").innerHTML =
    traverseListNode(deleteDuplicates(createList([0,1,1,1,2,2])));