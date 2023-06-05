/**
 * @param {number[]} heights
 * @return {number}
 */
var largestRectangleAreaDP = function(heights) {
    // area = minHeight(x, y) * (y - x + 1)
    // minHeight(x, y) = min(minHeight(x, y - 1), height(y))
    let m = heights.length;
    if (m === 0) {
        return 0;
    }

    let matrix = new Array(m);
    for (let i = 0; i < m; i++) {
        matrix[i] = new Array(m);
    }

    let maxArea = 0;
    for (let i = 0; i < m; i++) {
        for (let j = i; j < m; j++) {
            if (j === i) {
                matrix[i][j] = heights[i];
            } else {
                matrix[i][j] = Math.min(matrix[i][j - 1], heights[j]);
            }

            maxArea = Math.max(maxArea, matrix[i][j] * (j - i + 1));
        }
    }

    return maxArea;
};

/**
 * @param {number[]} heights
 * @return {number}
 */
 var largestRectangleArea = function(heights) {
    // use stack to record previous min height
    let m = heights.length;
    if (m === 0) {
        return 0;
    }

    let hStack = [0];
    let iStack = [-1];
    let maxArea = 0;
    let i = 0;
    while (i <= m) {
        if (i === m || hStack[hStack.length - 1] > heights[i]) {
            if (hStack.length === 0) {
                break;
            }

            let h = hStack.pop();
            let st = iStack.pop();
            maxArea = Math.max(h * (i - st), maxArea);
        } else if (hStack[hStack.length - 1] < heights[i]) {
            hStack.push(heights[i]);
            iStack.push(iStack[iStack.length - 1] + 1);
            i++;
        } else {
            // the current height same as the top of the stack.
            i++;
        }
    }

    return maxArea;
};

document.getElementById("largest-rectangle-in-histogram").innerHTML =
    largestRectangleArea([2,1,5,5,6,2,3]);
    // largestRectangleArea([2,4]);
    // largestRectangleArea([2,1,2]);
