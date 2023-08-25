/**
 * @param {string} s
 * @return {string[]}
 */
var restoreIpAddresses = function(s) {
    let res = [];
    restoreIpAddressesNS.helper(s, "", 0, res);
    return res;
};

const restoreIpAddressesNS = {
    helper: function(s, cur, dotPos, res) {
        // console.log(s, cur, dotPos, res);

        if (dotPos === 4) {
            if (s.length === 0) {
                res.push(cur);
            }

            return;
        }

        if (dotPos !== 0) {
            cur += ".";
        }

        if (s[0] === '0') {
            this.helper(s.substring(1), cur + "0", dotPos + 1, res);
            return;
        }

        for (let i = 1; i <= 3 && i <= s.length; i++) {
            let num = s.substring(0, i);
            if (parseInt(num) <= 255) {
                this.helper(s.substring(i), cur + num, dotPos + 1, res);
            }
        }
    },
};

document.getElementById("restore-ip-addresses").innerHTML =
    // restoreIpAddresses("25525511135");
    // restoreIpAddresses("0000");
    restoreIpAddresses("101023");
