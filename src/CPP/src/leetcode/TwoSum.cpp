/*
 * [Source] https://leetcode.com/problems/two-sum/
 * [Difficulty]: Easy
 * [Tag]: Array
 * [Tag]: Hash Table
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }

        return {-1, -1};
    }

    vector<int> twoSumSort(vector<int>& nums, int target) {
        // use a hash map to record indexes
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]].push_back(i);
        }

        // sort the vector so that only needs to move indexes to one direction
        sort(nums.begin(), nums.end());

        int st = 0, ed = nums.size() - 1;
        while (st < ed) {
            if (nums[st] + nums[ed] == target) {
                // If there are dup value
                if (nums[st] != nums[ed]) {
                    return {map[nums[st]][0], map[nums[ed]][0]};
                } else {
                    return {map[nums[st]][0], map[nums[st]][1]};
                }
            } else if (nums[st] + nums[ed] < target) {
                st++;
            } else {
                ed--;
            }
        }

        return {-1, -1};
    }

    struct IdxNum {
        int idx;
        int num;
    };

    bool compare(const IdxNum& a, const IdxNum& b) const {
        return a.num < b.num;
    }

    vector<int> twoSumStruct(vector<int>& nums, int target) {
        vector<IdxNum> v;
        for (int i = 0; i != nums.size(); i++) {
            v.push_back({i, nums[i]});
        }
        sort(v.begin(), v.end(), compare);

        int st = 0;

        int ed = nums.size() - 1;
        while (st < ed) {
            int sum = v[st].num + v[ed].num;
            if (sum == target) {
                return {v[st].idx, v[ed].idx};
            } else if (sum < target) {
                st++;
            } else {
                ed--;
            }
        }

        return {-1, -1};
    }
};

// [Solution]: Sort
/* Java solution
public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] res = {-1, -1}; 
        if (numbers == null || numbers.length <= 1) {
            return res; 
        }
        int[] indice = new int[numbers.length]; 
        sort(numbers, indice); 
        int st = 0; 
        int ed = numbers.length - 1; 
        while (st < ed) {
            if (numbers[st] + numbers[ed] == target) {
                res[0] = indice[st] < indice[ed] ? indice[st] : indice[ed]; 
                res[1] = indice[st] < indice[ed] ? indice[ed] : indice[st];
                return res; 
            } else if (numbers[st] + numbers[ed] < target) {
                ++st; 
            } else {
                --ed; 
            }
        }
        return res; 
    }
    
    private void sort(int[] numbers, int[] indice) {
        int i; 
        for (i = 0; i < numbers.length; ++i) {
            indice[i] = i + 1; 
        }
        quickSort(numbers, indice, 0, numbers.length - 1); 
    }
    
    private void quickSort(int[] numbers, int[] indice, int st, int ed) {
        if (st >= ed) {
            return; 
        }
        int md = st + (ed - st) / 2; 
        swap(numbers, indice, md, ed); 
        int pt = st - 1; 
        for (int i = st; i < ed; ++i) {
            if (numbers[i] < numbers[ed]) {
                ++pt; 
                swap(numbers, indice, pt, i); 
            }
        }
        ++pt; 
        swap(numbers, indice, pt, ed); 
        quickSort(numbers, indice, st, pt - 1); 
        quickSort(numbers, indice, pt + 1, ed); 
    }
    
    private void swap(int[] numbers, int[] indice, int pos1, int pos2) {
        int tmpNum = numbers[pos1]; 
        int tmpIdx = indice[pos1]; 
        numbers[pos1] = numbers[pos2];
        indice[pos1] = indice[pos2]; 
        numbers[pos2] = tmpNum; 
        indice[pos2] = tmpIdx; 
    }
}
 */

// [Solution]: Hash table
/* Java solution
 * https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/TwoSumHash.java
 */

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 4};
    vector<int> res = sol.twoSum(nums, 6);

    cout << res[0] << ", " << res[1] << endl;

    return 0;
}
