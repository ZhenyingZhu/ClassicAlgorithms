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

    let match = new Array(s.length + 1);
    for (let i = 0; i < match.length; i++) {
        match[i] = new Array(p.length + 1);
    }

    match[0][0] = true;

    for (let i = 1; i < match.length; i++) {
        match[i][0] = false;
    }

    for (let j = 1; j < match[0].length; j++) {
        if (p[j - 1] === '*') {
            if (j === 1) {
                console.log("Invalid pattern");
                return false;
            }

            match[0][j] = match[0][j - 2];
        } else {
            match[0][j] = false;
        }
    }

    for (let i = 0; i < s.length; i++) {
        for (let j = 0; j < p.length; j++) {
            if (s[i] === p[j] || p[j] === '.') {
                match[i + 1][j + 1] = match[i][j];
            } else if (p[j] === '*') {
                match[i + 1][j + 1] = false;
                for (let k = 0; k <= i + 1; k++) {
                    if (!match[k][j - 1]) {
                        continue;
                    }

                    let allMatch = true;
                    for (let l = k; l <= i; l++) {
                        if (s[l] !== p[j - 1] && p[j - 1] !== '.') {
                            allMatch = false;
                            break;
                        }
                    }

                    if (allMatch) {
                        match[i + 1][j + 1] = true;
                        break;
                    }
                }
            } else {
                match[i + 1][j + 1] = false;
            }
        }
    }

    return match[s.length][p.length];
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

document.getElementById("regular-expression-matching").innerHTML = isMatchDP("bbc", "a*b*c");