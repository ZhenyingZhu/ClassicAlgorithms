const lengthOfLongestSubstring = function(s) {
    let max = 0;
    let st = 0;

    let charIndexes = new Map();
    for (let i = 0; i < s.length; i++) {
        if (charIndexes.has(s[i])) {
            let charIndex = charIndexes.get(s[i]);
            if (charIndex >= st) {
                // console.log(s.substring(st, i));
                max = Math.max(max, i - st);

                st = charIndex + 1;
            }
        }

        charIndexes.set(s[i], i);
    }

    // console.log(s.substring(st));
    return Math.max(max, s.length - st);
};

const lengthOfLongestSubstringWrongSolution = function(s) {
    // a map record when a char is last seen. So if hit it again, move back to there.
    // why is it wrong because for "abba", if a hit, "bba" is not the solution.
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

class Queue {
    constructor() {
        this.elements = [];
    }

    enqueue(e) {
        this.elements.push(e);
    }

    dequeue() {
        return this.elements.shift();
    }

    isEmpty() {
        return this.elements.length === 0;
    }
}

// document.getElementById("longest-substring-without-repeating-characters").innerHTML = lengthOfLongestSubstring("abba");
document.getElementById("longest-substring-without-repeating-characters").innerHTML = lengthOfLongestSubstring("abcabcbade");

