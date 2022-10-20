/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
const isMatch = function(s, p) {
    let i = 0;
    let j = 0;
    let k = s.length + 1; // init with an invalid value

    while (j < p.length - 1) {
        if (p[j + 1] === '*') {
            k = i; // to return

        }
        else if (s[i] === p[j] && p[j] === '.') {
            i++;
            j++;
        } else if (p[j] === '.') {

        }
    }

    return (i === s.length && j === p.length);
};


document.getElementById("regular-expression-matching").innerHTML = isMatch("aa", "a");