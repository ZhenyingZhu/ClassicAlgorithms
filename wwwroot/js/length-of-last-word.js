/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let cnt = 1;
    let st = false;
    for (let i = s.length - 1; i >= 0; i--) {
        if (s[i] === " ") {
            if (st) {
                return cnt;
            }
        } else {
            if (st) {
                cnt++;
            } else {
                st = true;
            }
        }
    }

    return cnt;
};

document.getElementById("length-of-last-word").innerHTML =
    // lengthOfLastWord("   fly me   to   the moon  ");
    // lengthOfLastWord("moon");
    // lengthOfLastWord("moon ");
    lengthOfLastWord(" moon");
