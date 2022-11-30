/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
 var removeNthFromEnd = function(head, n) {
    let fast = head;
    for (let i = 0; i < n; i++) {
        if (fast === null) {
            return;
        }

        fast = fast.next;
    }

    let pre = new ListNode(0);
    pre.next = head;
    let slow = pre;

    while (fast != null) {
        fast = fast.next;
        slow = slow.next;
    }

    slow.next = slow.next.next;
    return pre.next;
};

document.getElementById("remove-nth-node-from-end-of-list").innerHTML = traverseListNode(removeNthFromEnd(createList([1,2,3,4,5]), 2));