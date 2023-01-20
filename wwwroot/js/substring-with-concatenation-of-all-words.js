/**
 * @param {string} s
 * @param {string[]} words
 * @return {number[]}
 */
var findSubstring = function(s, words) {
    // build a dict: key is a word and val is the count (in case there are dup words)
    // go through each index in s, check start from it, if there is a concatenation using sliding window.
    // exit if the index is already in the result.
    let res = [];
    if (words.length === 0) {
        return res;
    }
    let wordLen = words[0].length;
    if (s.length < wordLen * words.length) {
        return res;
    }

    let dict = {};
    for (let i = 0; i < words.length; i++) {
        if (dict[words[i]] === undefined) {
            dict[words[i]] = 1;
        } else {
            dict[words[i]]++;
        }
    }

    for (let i = 0; i <= s.length - wordLen * words.length; i++) {
        if (res.includes(i)) {
            continue;
        }

        slidingWindow(s, i, wordLen, words.length, JSON.parse(JSON.stringify(dict)), res);
    }

    return res;
};

const slidingWindow = function(s, st, wordLen, totalWords, dict, res) {
    let cur = st;
    let begin = st;
    while (cur <= s.length - wordLen) {
        let sub = s.substring(cur, cur + wordLen);
        if (dict[sub] === undefined || dict[sub] === 0) {
            return;
        }

        dict[sub]--;
        totalWords--;

        if (totalWords === 0) {
            res.push(begin);

            let addBack = s.substring(begin, begin + wordLen);
            begin += wordLen;
            dict[addBack]++;
            totalWords++;
        }

        cur += wordLen;
    }
};

document.getElementById("substring-with-concatenation-of-all-words").innerHTML =
    //findSubstring("barfoothefoobarman", ["foo","bar"]);
    //findSubstring("wordgoodgoodgoodbestword", ["word","good","best","word"]);
    //findSubstring("barfoofoobarthefoobarman", ["bar","foo","the"]);
    findSubstring("wordgoodgoodgoodbestword", ["word","good","best","good"]);
