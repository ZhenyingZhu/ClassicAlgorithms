/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number} n
 * @return {TreeNode[]}
 */
var generateTrees = function(n) {
    
};

const generateTreesNS = {
    helper: function(st, ed) {
        if (st > ed) {
            return [null];
        }

        if (st === ed) {
            return [new TreeNode(st)];
        }

        for (let i = st; i <= ed; i++) {
            
        }
    }
};

document.getElementById("unique-binary-search-trees-ii").innerHTML =
    restoreIpAddresses("101023");
