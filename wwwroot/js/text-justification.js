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

        if (cur.length > maxWidth) {
            return []; // invalid input case.
        }

        if (len + cur.length > maxWidth) {
            res.push(fullJustifyNS.construstLine(st, idx, words, maxWidth));
            st = idx;
            len = 0;
            continue;
        }

        len += cur.length + 1;
        idx++;
    }

    res.push(fullJustifyNS.construstLastLine(st, idx, words, maxWidth));
    return res;
};

const fullJustifyNS = {
    space: " ",

    construstLine: function(st, ed, words, maxWidth) {
        // not include ed.
        let len = 0;
        for (let i = st; i < ed; i++) {
            len += words[i].length;
        }

        let total = maxWidth - len;
        let inter = ed - st - 1;
        if (inter === 0) {
            return words[st] + this.space.repeat(total);
        }

        let res = "";

        let base = Math.floor(total / inter);
        let extra = total % inter;
        let cur = st;
        for (let i = 0; i < extra; i++) {
            res += words[cur++] + this.space.repeat(base + 1);
        }

        while (cur < ed - 1) {
            res += words[cur++] + this.space.repeat(base);
        }

        res += words[ed - 1];
        return res;
    },

    construstLastLine: function(st, ed, words, maxWidth) {
        // not include ed.
        let len = 0;
        let res = "";
        for (let i = st; i < ed - 1; i++) {
            res += words[i] + this.space;
            len += words[i].length + 1;
        }
        res += words[ed - 1];
        len += words[ed - 1].length;
        res += this.space.repeat(maxWidth - len);
        return res;
    },
};

document.getElementById("text-justification").innerHTML =
    // fullJustify(["This", "is", "an", "example", "of", "text", "justification."], 16);
    fullJustify(["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], 20);
