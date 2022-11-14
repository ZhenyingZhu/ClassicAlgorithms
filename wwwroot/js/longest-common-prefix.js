/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if (strs.length == 0) {
        return '';
    }

    let charIdx = 0;
    for (; charIdx < strs[0].length; charIdx++) {
        let cur = strs[0][charIdx];
        for (let i = 1; i < strs.length; i++) {
            if (strs[i].length <= charIdx || strs[i][charIdx] !== cur) {
                return strs[0].substring(0, charIdx);
            }
        }
    }

    return strs[0];
};

document.getElementById("longest-common-prefix").innerHTML = longestCommonPrefix(["flower","flower","flower","flower"]);