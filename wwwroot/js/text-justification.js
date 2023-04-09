/**
 * @param {string[]} words
 * @param {number} maxWidth
 * @return {string[]}
 */
var fullJustify = function(words, maxWidth) {
    if (words.length === 0) {
        return [];
    }

    let res = [];
    let idx = 0;
    let len = 0;
    let st = 0;
    while (idx < words.length) {
        let cur = words[idx];
        if (len + cur.length > maxWidth) {
            res.push(fullJustifyNS.construstLine(st, idx, words, maxWidth));
            st = idx;
            continue;
        }

        len += cur.length + 1;
    }

    res.push(fullJustifyNS.construstLastLine(st, idx, words, maxWidth));
    return res;
};

const fullJustifyNS = {
    construstLine: function(st, ed, words, maxWidth) {
        // not include ed.
        return "";
    },

    construstLastLine: function(st, ed, words, maxWidth) {
        // not include ed.
        return "";
    },
};

document.getElementById("text-justification").innerHTML =
    fullJustify(["This", "is", "an", "example", "of", "text", "justification."], 16);
