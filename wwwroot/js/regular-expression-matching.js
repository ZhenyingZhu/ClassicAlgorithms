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