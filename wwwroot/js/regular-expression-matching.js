/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
const isMatchDP = function(s, p) {
    // Solution: m[i][j] indicates s(0, i) matches p(0, j).
    // m[i][j] = m[i-1][j-1] && (s[i] == p[j] || p[j] == '.') ||
    //   p[j] == '*' && for k in (0, i), any (m[k][j-2] && s[k + 1] to s[i] == p[j - 1] || p[j - 1] == '.')
    if (p === ".*") {
        return true;
    }

    let match = new Array(s.length);
    for (let i = 0; i < s.length; i++) {
        match[i] = new Array(p.length);
    }

    for (let i = 0; i < s.length; i++) {
        for (let j = 0; j < p.length; j++) {
            if (s[i] === p[j] || p[j] === '.') {
                if (i === 0 && j === 0) {
                    match[i][j] = true;
                } else if (j === 0) {
                    if (p[j] === '*') {
                        // invalid case
                        console.log("Error case");
                        return false;
                    } else {
                        match[i][j] = false;
                    }
                } else if (i === 0) {
                    match[i][j] = match[i][j - 1];
                } else {

                }
            }
        }
    }
};

const isMatchJumpBackWrong = function(s, p) {
    // Solution: when see *, need to match multiple possibles. Use a pointer k to go back.
    let i = 0;
    let j = 0;
    let k = p.length; // the end of the string so the while look could exit

    while (j < p.length) {
        if (j < p.length - 1 && p[j + 1] === '*') {
            k = j; // to return
            j = k + 2;
        }
        else if (s[i] === p[j] || p[j] === '.') {
            i++;
            j++;
        } else if (k !== p.length) {
            j = k;
            if (s[i] === p[j] || p[j] === '.') {
                i++;
            }
            else {
                break;
            }
        }
    }

    return (i === s.length && j === p.length);
};

document.getElementById("regular-expression-matching").innerHTML = isMatch("abbc", "a*b*c");