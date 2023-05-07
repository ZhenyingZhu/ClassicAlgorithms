/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
    let res = "";
    let m = t.length;
    let n = s.length;
    if (m === 0 || m < n) {
        return res;
    }

    let tdict = {};
    for (let i = 0; i < n; i++) {
        let c = t[i];
        tdict[c] = tdict[c] === undefined ? 1 : tdict[c] + 1;
    }

    let st = 0;
    let totalLen = 0;
    let sdict = {};
    for (let i = 0; i < m; i++) {
        let c = s[i];
        if (tdict[c] !== undefined) {
            sdict[c] = sdict[c] === undefined ? 1 : sdict[c] + 1;
            if (sdict[c] <= tdict[c]) {
                totalLen += 1;
                if (totalLen === n) {
                    while (st <= i - n) {
                        if (tdict[s[st]] !== undefined) {
                            if (sdict[s[st]] > tdict[s[st]]) {
                                sdict[s[st]]--;
                            } else {
                                break;
                            }
                        }
                        st++;
                    }
                    if (res.length === 0 || (i - st + 1) < res.length) {
                        res = s.substring(st, i);
                    }
                    totalLen--;
                    sdict[s[st]]--;
                    st++;
                }
            }
        }
    }

    return res;
};

document.getElementById("minimum-window-substring").innerHTML =
    minWindow("ADOBECODEBANC", "ABC");
