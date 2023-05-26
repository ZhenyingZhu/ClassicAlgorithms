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
    let dummy = new ListNode();
    dummy.next = head;

    let pre = dummy;
    let cur = head;
    while (cur !== null) {
        let val = cur.val;
        let next = cur.next;
        while (next !== null && next.val === val) {
            next = next.next;
        }
    }
};

document.getElementById("remove-duplicates-from-sorted-list-ii").innerHTML =
    // search([2,5,6,0,0,1,2], 0);
    // search([2,5,6,0,0,1,2], 3);
    search([3,1,1], 0);