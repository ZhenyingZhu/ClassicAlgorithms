/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
    if (lists.length <= 0) {
        return null;
    }

    let list = lists[0];
    for (let i = 1; i < lists.length; i++) {
        list = mergeTwoListsInKLists(list, lists[i]);
    }

    return list;
};

const mergeTwoListsInKLists = function(list1, list2) {
    let head = new ListNode(0);
    let cur = head;
    while (list1 !== null && list2 !== null) {
        if (list1.val < list2.val) {
            cur.next = list1;
            list1 = list1.next;
        } else {
            cur.next = list2;
            list2 = list2.next;
        }

        cur = cur.next;
    }

    if (list1 !== null) {
        cur.next = list1;
    } else {
        cur.next = list2;
    }

    return head.next;
};

document.getElementById("merge-k-sorted-lists").innerHTML = traverseListNode(mergeKLists([
    createList([1,4,5]),
    createList([1,3,4]),
    createList([2,6])
]));

document.getElementById("merge-k-sorted-lists").innerHTML = mergeKLists([]);
