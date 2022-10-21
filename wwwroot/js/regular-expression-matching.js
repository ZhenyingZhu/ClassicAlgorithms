/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
const isMatch = function(s, p) {
    // Solution: when see *, need to match multiple possibles.
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