/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
const twoSumBF = function(nums, target) {
    let result = [];

    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            if (nums[i] + nums[j] === target) {
                result.push(i);
                result.push(j);

                return result;
            }
        }
    }
};

const twoSumMap = function(nums, target) {
    let map = new Map();
    for (let i = 0; i < nums.length; i++) {
        let val = target - nums[i];
        if (map.has(val)) {
            let j = map.get(val);

            return [j, i];
        }

        map.set(nums[i], i);
    }
};

const twoSumSort = function(nums, target) {
    indexes = [];
    for (let i = 0; i < nums.length; i++) {
        const num_idx = {num: nums[i], idx: i};
        indexes.push(num_idx);
    }

    indexes.sort(function(a, b) {
        return a.num - b.num
    });

    let i = 0;
    let j = nums.length - 1;

    while (i < j) {
        if (indexes[i].num + indexes[j].num === target) {
            return [indexes[i].idx, indexes[j].idx];
        }

        if (indexes[i].num + indexes[j].num < target) {
            i++;
        }
        else
        {
            j--;
        }
    }
};

/* Test cases
[2,7,11,15]
9
[3,2,4]
6
[3,3]
6
*/

// console.log(twoSumSort([2, 7, 11, 15], 9));
document.getElementById('two-sum').innerHTML = twoSumSort([2, 7, 11, 15], 9);