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
    return generateTreesNS.helper(1, n);
};

const generateTreesNS = {
    helper: function(st, ed) {
        if (st > ed) {
            return [null];
        }

        if (st === ed) {
            return [new TreeNode(st)];
        }

        let res = [];
        for (let i = st; i <= ed; i++) {
            let leftNodes = this.helper(st, i - 1);
            let rightNodes = this.helper(i + 1, ed);

            for (let leftNode of leftNodes) {
                for (let rightNode of rightNodes) {
                    let cur = new TreeNode(i);
                    cur.left = leftNode;
                    cur.right = rightNode;
                    res.push(cur);
                }
            }
        }

        return res;
    }
};

document.getElementById("unique-binary-search-trees-ii").innerHTML =
    generateTrees(3)
    .map(printTree).join("<br/>");
