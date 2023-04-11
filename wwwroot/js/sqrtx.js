/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    // overflow?
    if (x <= 1) {
        return x;
    }

    let st = 1;
    let ed = Math.floor(x / 2);
    while (st + 1 < ed) {
        let md = Math.floor((st + ed) / 2);
        let val = md * md;
        if (val === x) {
            return md;
        }

        if (md * md < x) {
            st = md;
        } else {
            ed = md;
        }
    }

    if (ed * ed <= x) {
        return ed;
    } else {
        return st;
    }
};

document.getElementById("sqrtx").innerHTML =
    // mySqrt(8);
    // mySqrt(9);
    mySqrt(17);
