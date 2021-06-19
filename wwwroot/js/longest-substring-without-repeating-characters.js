 var lengthOfLongestSubstring = function(s) {
    // a map record when a char is last seen. So if hit it again, move back to there.
    let map = new Map();

    let start = 0;
    let max = 0;
    for (let i = 0; i < s.length; i++) {
        if (!map.has(s[i])) {
            map.set(s[i], i);
        } else {
            console.log(s.substring(start, i));

            max = Math.max(max, i - start);
            start = map.get(s[i]) + 1;

            map.set(s[i], i);
        }
    }

    console.log(s.substring(start, s.length));
    return Math.max(max, s.length - start);
};

document.getElementById("longest-substring-without-repeating-characters").innerHTML = lengthOfLongestSubstring("abba");