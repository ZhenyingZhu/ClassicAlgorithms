/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
    let res = "";
    if (t.length === 0 || t.length > s.length) {
        return res;
    }

    let dict = {};
    
};

document.getElementById("minimum-window-substring").innerHTML =
    minWindow("ADOBECODEBANC", "ABC");
