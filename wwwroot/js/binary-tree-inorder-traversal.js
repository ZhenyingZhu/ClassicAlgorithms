/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function(root) {
    let res = new Array();
    if (root === null) {
        return res;
    }

    inorderTraversalNS.helper(root, res);
    return res;
};

const inorderTraversalNS = {
    helper: function(node, res) {
        if (node.left !== null) {
            this.helper(node.left, res);
        }

        res.push(node.val);

        if (node.right !== null) {
            this.helper(node.right, res);
        }
    }
};

document.getElementById("binary-tree-inorder-traversal").innerHTML =
    inorderTraversal(createTree([1, 2, 3], [1, 3, 2]));
