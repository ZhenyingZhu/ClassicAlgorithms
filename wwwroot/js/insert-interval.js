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
    for (let i = 0; i < intervals.length; i++) {
        console.log(res);
        let cur = intervals[i];
        if (cur[0] > ed) {
            if (!inserted) {
                res.push([st, ed]);
                inserted = true;
            }
            res.push(cur);
        } else if (cur[1] < st) {
            res.push(cur);
        } else if (cur[1] >= st && !inserted) {
            st = Math.min(st, cur[0]);
            ed = Math.max(ed, cur[1]);
        }
    }

    if (!inserted) {
        res.push([st, ed]);
    }

    return res;
};

document.getElementById("insert-interval").innerHTML =
    // insert([[1,3],[6,9]], [2,5]);
    //insert([[1,2],[3,5],[6,7],[8,10],[12,16]], [4,8]);
    insert([[1,2],[3,5],[6,7],[8,10],[12,16]], [18,19]);
