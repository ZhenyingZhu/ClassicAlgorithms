/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
    if (nums.length < 4) {
        return [];
    }

    nums.sort(function(a, b) { return a - b; });

    // console.log(nums);

    let res = [];
    for (let i = 0; i < nums.length - 3; i++) {
        if (i > 0 && nums[i] === nums[i - 1]) {
            continue;
        }

        // console.log(`Current i: ${i}, nums[i]: ${nums[i]}`);

        for (let j = i + 1; j < nums.length - 2; j++) {
            if (j > i + 1 && nums[j] === nums[j - 1]) {
                continue;
            }

            // console.log(`Current j: ${j}, nums[j]: ${nums[j]}`);

            let tar = target - nums[i] - nums[j];

            // console.log(`Current target: ${tar}`);

            let st = j + 1;
            let ed = nums.length - 1;
            while (st < ed) {
                if ((st > j + 1 && nums[st] === nums[st - 1])) {
                    st++;
                    continue;
                }

                // console.log(`Current st: ${st}, nums[st]: ${nums[st]}`);
                // console.log(`Current ed: ${ed}, nums[ed]: ${nums[ed]}`);

                let val = nums[st] + nums[ed];
                if (val === tar) {
                    res.push([nums[i], nums[j], nums[st], nums[ed]]);
                    st++;
                } else if (val > tar) {
                    ed--;
                } else {
                    st++;
                }
            }
        }
    }

    return res;
};

// document.getElementById("4sum").innerHTML = fourSum([1,0,-1,0,-2,2], 0);
document.getElementById("4sum").innerHTML = fourSum([2,2,2,2,2], 8);