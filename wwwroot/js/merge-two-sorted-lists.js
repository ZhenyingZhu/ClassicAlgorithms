/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function(list1, list2) {
    let n1 = list1;
    let n2 = list2;
    let n0 = new ListNode(0);
    let cur = n0;
    while (n1 !== null && n2 !== null) {
        if (n1.val < n2.val) {
            cur.next = n1;
            n1 = n1.next;
        } else {
            cur.next = n2;
            n2 = n2.next;
        }

        cur = cur.next;
    }

    if (n1 !== null) {
        cur.next = n1;
    } else {
        cur.next = n2;
    }

    return n0.next;
};

document.getElementById("merge-two-sorted-lists").innerHTML = traverseListNode(mergeTwoLists(createList([1, 2, 4]), createList([1, 3, 4])));