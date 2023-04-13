/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    let directories = path.split("/");
    let arr = new Array();
    for (let i = 0; i < directories.length; i++) {
        let directory = directories[i];
        if (directory.length === 0 || directory === ".") {
            continue;
        }

        if (directory === "..") {
            if (arr.length === 0) {
                continue;
            }

            arr.pop();
        } else {
            arr.push(directory);
        }
    }

    if (arr.length === 0) {
        return "/";
    }

    let res = "";
    for (let i = 0; i < arr.length; i++) {
        res += "/" + arr[i];
    }

    return res;
};

document.getElementById("simplify-path").innerHTML =
    // simplifyPath("/home/");
    // simplifyPath("/../");
    // simplifyPath("/home//foo/");
    // simplifyPath("/.../");
    simplifyPath("/app/build/../");
