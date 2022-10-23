/*
 * [Source] https://leetcode.com/problems/maximum-product-subarray/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// [Solution]: The condition is very complicate. So negative multiply come from positive * num when num is smaller than 0, or negative * num when num is larger than 0, and negative is smaller than 0. Positive multiply comes from positive * num when num is larger than 0, or negative * num when num is smaller than 0, or reset if negative is not intialized yet.
// [Corner Case]:
class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int localMin = 1, localMax = 1;
        int globalMax = INT_MIN;
        for (int &num : nums) {
cout << num << endl;
            if (num > 0) {
                localMax = localMax * num;
                localMin = min(localMin * num, 1);
            } else if (num < 0) {
                int tmp = localMin;
                localMin = localMax * num;
                if (tmp < 0) {
                    // this leads to localMax can still be the result
                    // need to exit earlier, otherwise use the globalMax check at the end will conduct wrong answer
                    localMax = tmp * num;
                    globalMax = max(globalMax, localMax);
cout << localMax << " " << localMin << " " << globalMax << endl;
                    continue;
                } else {
                    localMax = 1;
                }
            } else {
                localMin = 1;
                localMax = 1;
            }

            if (num <= 0) {
                globalMax = max(globalMax, num);
            } else {
                globalMax = max(globalMax, localMax);
            }
cout << localMax << " " << localMin << " " << globalMax << endl;
        }
        return globalMax;
    }
};

class SolutionChaos {
    public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int res = INT_MIN;
        int positive = 1, negative = 1;
        for (int &num : nums) {
            if (num == 0) {
                res = max(res, 0);
                positive = 1;
                negative = 1;
            } else if (num < 0) {
                if (negative < 0) {
                    int prePos = positive;
                    positive = negative * num;
                    negative = prePos * num;
                    res = max(positive, res);
                } else {
                    res = max(num, res);
                    negative = positive * num;
                    positive = 1;
                }
            } else {
                positive *= num;
                if (negative < 0) // otherwise negative is 1
                    negative *= num;
                res = max(positive, res);
            }
        }
        return res;
    }
};

// [Solution]: Maintain both positive and negative max. Since negative * negative is positive.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/MaximumProductSubarray.java
 */

/* Java solution
package algorithms; 

import java.util.*;

public class MaximumProductSubarray {
     // Function: Return the max product of subarray.  
     // Solution: Consider -- is + and 0. Use prefix product. 
    
    public int maxProduct(int[] A) {
        if (A == null || A.length == 0) {
            return 0; 
        }
        
        int res = Integer.MIN_VALUE, mul = 1, negMax = 1;
        for (int i = 0; i < A.length; ++i) {
            mul *= A[i]; 
            if (mul > 0) {
                res = Math.max(res, mul); 
            } else if (mul < 0) {
                res = Math.max(res, mul / negMax); 
                if (negMax == 1) {
                    negMax = mul; 
                } else {
                    negMax = Math.max(negMax, mul); 
                }
            } else {
                res = Math.max(res, mul); 
                mul = 1; 
                negMax = 1; 
            }
        }
        
        return res; 
    }
}
 */

int main() {
    Solution sol;

    //vector<int> nums = {2, 3, -2, 4, -2}; // 96
    //vector<int> nums = {-2}; // -2
    //vector<int> nums = {2,-5,-2,-4,3}; // 24
    vector<int> nums = {-1, -2, -9, -6}; // 108
    cout << sol.maxProduct(nums) << endl;

    return 0;
}
