const convert = function(s, numRows) {
    if (numRows <= 1) {
        return s;
    }

    let rows = new Array(numRows);
    for (let i = 0; i < numRows; i++) {
        rows[i] = new Array();
    }

    let cur = 0;
    let down = true;
    for (let i = 0; i < s.length; i++) {
        rows[cur].push(s[i]);
        if (cur === 0) {
            down = true;
        } else if (cur === numRows - 1) {
            down = false;
        }

        cur += down ? 1 : -1;
    }

    let result = "";
    for (let i = 0; i < numRows; i++) {
        result += rows[i].join("");
    }

    return result;
};

document.getElementById("zigzag-conversion").innerHTML = convert("PAYPALISHIRING", 3);