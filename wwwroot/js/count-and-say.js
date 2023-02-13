/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
    if (n === 1) {
        return "1";
    }

    let str = countAndSay(n - 1);

    let res = "";
    let cnt = 1;
    let cur = str[0];
    for (let i = 1; i < str.length; i++) {
        if (str[i] === cur) {
            cnt++;
        } else {
            res += cnt + cur;
            cur = str[i];
            cnt = 1;
        }
    }

    res += cnt + cur;
    return res;
};

document.getElementById("count-and-say").innerHTML = countAndSay(4);
