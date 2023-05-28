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

    let dummy = new ListNode();
    let pre = dummy;
    let cur = head;
    while (cur !== null) {
        let val = cur.val;
        let run = cur.next;
        while (run !== null && run.val === val) {
            run = run.next;
        }

        if (run === cur.next) {
            pre.next = cur;
            pre = cur;
            cur = cur.next;
        } else {
            pre.next = null;
            cur = run;
        }
    }

    return dummy.next;
};

document.getElementById("remove-duplicates-from-sorted-list-ii").innerHTML =
    traverseListNode(deleteDuplicates(createList([0,1,1,1,2,2])));