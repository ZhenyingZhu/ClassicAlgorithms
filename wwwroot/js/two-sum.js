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
}

console.log(twoSumMap([2, 7, 11, 15], 9));
document.getElementById('two-sum').innerHTML = twoSumMap([2, 7, 11, 15], 13);