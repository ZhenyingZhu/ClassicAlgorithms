/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    if (intervals.length === 0) {
        return;
    }

    intervals.sort(function(a, b) { return a[0] - b[0]; });

    let res = [];

    let st = intervals[0][0];
    let ed = intervals[0][1];
    for (let i = 1; i < intervals.length; i++) {
        let cur = intervals[i];
        if (cur[0] > ed) {
            console.log(st, ed);
            res.push([st, ed]);
            st = cur[0];
            ed = cur[1];
        } else {
            ed = Math.max(ed, cur[1]);
        }
    }

    res.push([st, ed]);
    return res;
};

document.getElementById("merge-intervals").innerHTML =
    merge([[1,3],[2,6],[8,10],[15,18]]);
