/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function(intervals, newInterval) {
    let res = [];

    let st = newInterval[0];
    let ed = newInterval[1];
    let inserted = false;
    for (let i = 0; i < intervals; i++) {
        let cur = intervals[i];
        if (cur[1] < st) {
            res.push(cur);
        } else if (cur[0] > ed) {
            if (!inserted) {
                res.push([st, ed]);
                inserted = true;
            }
            res.push(cur);
        } else if (cur[1] >= st) {
            st = Math.min(st, cur[0]);
            ed = Math.max(ed, cur[1]);
        }
    }
};

document.getElementById("insert-interval").innerHTML =
    merge([[1,3],[2,6],[8,10],[15,18]]);
