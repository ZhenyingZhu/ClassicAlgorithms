// Definition for a binary tree node.
function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}

const createTree = function(preorder, inorder) {
    if (preorder.length !== inorder.length) {
        throw new Error("length not equal!");
    }

    if (preorder.length === 0) {
        return null;
    }

    let val = preorder[0];
    let idx = inorder.indexOf(val);
    let left = createTree(preorder.slice(1, idx + 1), inorder.slice(0, idx));
    let right = createTree(preorder.slice(idx + 1), inorder.slice(idx + 1));

    return new TreeNode(val, left, right);
};

const traverseTree = function(node) {
    let str = "node: " + node.val;
    if (node.left !== null) {
        str += "; left: " + node.left.val;
    }
    if (node.right !== null) {
        str += "; right: " + node.right.val;
    }
    console.log(str);

    if (node.left !== null) {
        traverseTree(node.left);
    }
    if (node.right !== null) {
        traverseTree(node.right);
    }
};