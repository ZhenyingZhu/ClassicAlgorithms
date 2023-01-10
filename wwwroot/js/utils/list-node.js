// Definition for singly-linked list.
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

const traverseListNode = function(node) {
    val = "";
    let cycle = 0;
    while (node != null && cycle < 100) {
        cycle++;
        val += node.val + "->";
        node = node.next;
    }

    return val;
};

const createList = function(array) {
    var next = null;
    var curr = null;
    for (let i = array.length - 1; i >= 0; i--) {
        curr = new ListNode(array[i], next);
        next = curr;
    }

    return curr;
};
