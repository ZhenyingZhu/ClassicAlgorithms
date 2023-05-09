/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
    let res = "";
    let m = s.length;
    let n = t.length;
    if (m === 0 || m < n) {
        return res;
    }

    let tdict = {};
    for (let i = 0; i < n; i++) {
        let c = t[i];
        tdict[c] = tdict[c] === undefined ? 1 : tdict[c] + 1;
    }

    // First scan from start until all the chars in t are find,
    // then move start until chars in t are just met, and use start to here as one of the result.
    // then move start one char ahead, so result is invalid, and find the next valid result.
    let st = 0;
    let totalLen = 0;
    let sdict = {};
    for (let i = 0; i < m; i++) {
        let c = s[i];
        // A char not in t, just go futher as it won't make the res matches t.
        if (tdict[c] === undefined) {
            continue;
        }

        // If a char appears more times in s than t, don't count it in.
        sdict[c] = sdict[c] === undefined ? 1 : sdict[c] + 1;
        if (sdict[c] > tdict[c]) {
            continue;
        }

        // A char appear to let res 1 step further to become t.
        totalLen += 1;
        if (totalLen < n) {
            continue;
        }

        // All the chars in t appear in res. Move start further.
        while (st <= i - n) {
            if (tdict[s[st]] !== undefined) {
                if (sdict[s[st]] == tdict[s[st]]) {
                    // Removing s[st] makes this char having less count than t, so cannot remove it.
                    break;
                } else {
                    sdict[s[st]]--;
                }
            }
            st++;
        }

        // console.log(s.substring(st, i + 1));

        // Compare it with the previous result.
        if (res.length === 0 || (i - st) < res.length) {
            res = s.substring(st, i + 1);
        }
        totalLen--;
        sdict[s[st]]--;
        st++;
    }

    return res;
};

document.getElementById("minimum-window-substring").innerHTML =
    // minWindow("ADOBECODEBANC", "ABC");
    minWindow("AAABBCA", "ABC");
