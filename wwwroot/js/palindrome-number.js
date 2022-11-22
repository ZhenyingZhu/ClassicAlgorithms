const isPalindromeDigit = function(x, n) {
    // console.log("x: " + x + ", n: " + n)
    if (x < 10 && n <= 1) {
        return true;
    }

    let low = x % 10;

    let pow = 10 ** (n - 1);
    let high = Math.floor(x / pow);

    if (low === high) {
        x = x % pow;
        x = Math.floor(x / 10);
        return isPalindromeDigit(x, n - 2);
    }

    return false;
};

const isPalindrome = function(x) {
    if (x < 0) {
        return false;
    }

    let digit = 0;
    let pow = 1;
    while (x >= pow) {
        digit++;
        pow *= 10;
    }

    return isPalindromeDigit(x, digit);
};

document.getElementById("palindrome-number").innerHTML = isPalindrome(1000021);