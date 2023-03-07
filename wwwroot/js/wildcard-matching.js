/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    // d[i][j] = T means s(0, i] matches p(0, j].
    // d[i][j] = (s[i] == p[j] || p[j] == ?) && d[i - 1, j - 1] == T
    //        || p[j] == * && d[i - k, j - 1] == T
    let d = new Array(s.length + 1);
    for (let i = 0; i < s.length + 1; i++) {
        d[i] = new Array(p.length + 1);
    }

    d[0][0] = true;
    for (let i = 1; i < s.length + 1; i++) {
        d[i][0] = false;
    }

    for (let j = 1; j < p.length + 1; j++) {
        d[0][j] = d[0][j - 1] && p[j - 1] === "*";
    }

    for (let i = 1; i < s.length + 1; i++) {
        for (let j = 1; j < p.length + 1; j++) {
            if (s[i - 1] === p[j - 1] || p[j - 1] === "?") {
                d[i][j] = d[i - 1][j - 1];
            } else if (p[j - 1] === "*") {
                d[i][j] = false;
                for (let k = 0; k <= i; k++) {
                    if (d[k][j - 1]) {
                        d[i][j] = true;
                        break;
                    }
                }
            } else {
                d[i][j] = false;
            }
        }
        // console.log(d[i]);
    }

    return d[s.length][p.length];
};

document.getElementById("wildcard-matching").innerHTML =
    // isMatch("aa", "a");
    isMatch("aa", "*");
