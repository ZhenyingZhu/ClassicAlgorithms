/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    let dict = new Object();
    for (let i = 0; i < strs.length; i++) {
        let str = strs[i].split("").sort().join("");
        if (dict[str] === undefined) {
            dict[str] = new Array();
        }
        dict[str].push(strs[i]);
    }

    let res = [];
    for (let key of Object.keys(dict)) {
        res.push(dict[key]);
    }
    return res;
};

document.getElementById("group-anagrams").innerHTML =
    groupAnagrams(["eat","tea","tan","ate","nat","bat"]);
