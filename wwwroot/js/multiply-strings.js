/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var multiply = function(num1, num2) {
    return multiplyNS.multiplyConvert(num1, num2);
};

let multiplyNS = {
    multiplyConvert: function(num1, num2) {
        let resArr = new Array(num1.length + num2.length + 1);
        for (let i = 0; i < resArr.length; i++) {
            resArr[i] = 0;
        }

        for (let i = 0; i < num1.length; i++) {
            let a = parseInt(num1[num1.length - i - 1]);
            for (let j = 0; j < num2.length; j++) {
                let b = parseInt(num2[num2.length - j - 1]);

                let mul = a * b;
                let first = mul % 10;
                let second = Math.floor(mul / 10);
                resArr[i + j] += first;
                resArr[i + j + 1] += second;
            }

            // console.log(resArr);
        }

        for (let i = 0; i < resArr.length - 1; i++) {
            resArr[i + 1] += Math.floor(resArr[i] / 10);
            resArr[i] = resArr[i] % 10;
        }

        let res = "";
        let start = true;
        for (let i = resArr.length - 1; i >= 0; i--) {
            if (start && resArr[i] === 0) {
                continue;
            }

            if (resArr[i] !== 0) {
                start = false;
            }

            res += resArr[i];
        }

        if (res.length === 0) {
            res = "0";
        }

        return res;
    }
};

document.getElementById("multiply-strings").innerHTML =
    //multiply("12", "34");
    multiply("123456789", "987654321");
