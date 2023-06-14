/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} x
 * @return {ListNode}
 */
var partition = function(head, x) {
    let smaller = new ListNode();
    let equalGreater = new ListNode();
    let start = smaller;
    let mid = equalGreater;

    let cur = head;
    while (cur != null) {
        if (cur.val < x) {
            smaller.next = cur;
            smaller = smaller.next;
            console.log("smaller: " + smaller.val);
        } else {
            equalGreater.next = cur;
            equalGreater = equalGreater.next;
            console.log("greater: " + equalGreater.val);
        }
        cur = cur.next;
    }

    smaller.next = mid.next;
    equalGreater.next = null;

    return start.next;
};

document.getElementById("partition-list").innerHTML =
    traverseListNode(partition(createList([1,4,3,2,5,2]), 3));