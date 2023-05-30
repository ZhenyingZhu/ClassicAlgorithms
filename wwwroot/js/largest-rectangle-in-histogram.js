/**
 * @param {number[]} heights
 * @return {number}
 */
var largestRectangleArea = function(heights) {
    // area = min(x ~ y) * (y - x + 1)
    // Use DP to find min(x ~ y)
    if (heights.length === 0) {
        return 0;
    }

    for (let i = 0; i < heights.length; i++) {

    }
};

let largestRectangleAreaNS = {
    helper: function(heights, end) {
        let max = 0;
        let 
        for (let i = 0; i < end; i++) {

        }
    }
};

document.getElementById("largest-rectangle-in-histogram").innerHTML =
    traverseListNode(deleteDuplicates(createList([0,1,1,1,2,2])));