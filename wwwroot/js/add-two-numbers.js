/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
const addTwoNumbers = function(l1, l2) {
    if (l1 === null) {
        return l2;
    }
    if (l2 === null) {
        return l1;
    }

    let dummy = new ListNode(0, null);
    let prev = dummy;

    let val = 0;
    while (l1 !== null && l2 !== null) {
        val = val + l1.val + l2.val;
        l1 = l1.next;
        l2 = l2.next;

        let curr = new ListNode(val % 10, undefined);
        prev.next = curr;
        prev = curr;

        val = Math.floor(val / 10);
    }

    while (l1 !== null) {
        val = val + l1.val;
        l1 = l1.next;

        let curr = new ListNode(val % 10, undefined);
        prev.next = curr;
        prev = curr;

        val = Math.floor(val / 10);
    }

    while (l2 !== null) {
        val = val + l2.val;
        l2 = l2.next;

        let curr = new ListNode(val % 10, undefined);
        prev.next = curr;
        prev = curr;

        val = Math.floor(val / 10);
    }

    if (val !== 0) {
        let curr = new ListNode(val, null);
        prev.next = curr;
    }

    return dummy.next;
};

let list1 = createList([9, 9, 9, 9, 9, 9, 9]);
// console.log(traverseListNode(list1));

let list2 = createList([9, 9, 9, 9]);
// console.log(traverseListNode(list2));

document.getElementById("add-two-numbers").innerHTML = traverseListNode(addTwoNumbers(list1, list2));
