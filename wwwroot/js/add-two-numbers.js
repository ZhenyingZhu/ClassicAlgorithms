// Definition for singly-linked list.
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

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

    return dummy.next;
};

const traverseListNode = function(node) {
    val = "";
    while (node != null) {
        val += node.val + "->";
        node = node.next;
    }
}

let node13 = new ListNode(3, null);
let node12 = new ListNode(4, node13);
let node11 = new ListNode(2, node12);

let node23 = new ListNode(4, null);
let node22 = new ListNode(6, node23);
let node21 = new ListNode(5, node22);

document.getElementById("add-two-numbers").innerHTML = traverseListNode(addTwoNumbers(node11, node21));
