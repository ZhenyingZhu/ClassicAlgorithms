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
        let res = 0;
        for (let i = 0; i < num1.length; i++) {
            let a = parseInt(num1[i]);
            let mul = 0;
            for (let j = 0; j < num2.length; j++) {
                let b = parseInt(num2[j]);
                mul = mul * 10 + a * b;
            }
            console.log("a: " + a, ", mul: " + mul + ", res: " + res);
            console.log(res * 10);
            res = res * 10 + mul;
        }
    
        return res.toString();
    }
};

document.getElementById("multiply-strings").innerHTML =
    // multiply("12", "34");
    multiply("123456789", "987654321");
