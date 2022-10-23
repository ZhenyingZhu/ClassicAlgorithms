/*
 * [Source] https://leetcode.com/problems/candy/
 * [Difficulty]: Hard
 * [Tag]: Greedy
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: From left to right, if lower rate, get only one candy. From right to left, do the same, then pick the higher value.
// [Corner Case]: Same rating, the next one only get 1 candy.
class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        if (len == 0)
            return 0;

        vector<int> leftToRight(len), rightToLeft(len);
        leftToRight[0] = 1;
        rightToLeft[len - 1] = 1;

        for (int i = 1; i < len; ++i) {
            if (ratings[i] <= ratings[i - 1]) {
                leftToRight[i] = 1;
            } else {
                leftToRight[i] = leftToRight[i - 1] + 1;
            }
        }

        for (int i = len - 2; i >= 0; --i) {
            if (ratings[i] <= ratings[i + 1]) {
                rightToLeft[i] = 1;
            } else {
                rightToLeft[i] = rightToLeft[i + 1] + 1;
            }
        }

        int sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += max(leftToRight[i], rightToLeft[i]);
        }
        return sum;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/Candy.java
 */

/* Java solution
public class Solution {
    public int candy(int[] ratings) {
		int size=ratings.length;
		int[] numbers=new int[size];
		int num=1;
		for(int i=1; i<size; i++){ // easy to handle, only compute the diff
			if(ratings[i]>ratings[i-1]){
				numbers[i]=num++;
			}else{
				num=1; // Skip this cell. 
			}
		}
		num=1;
		for (int i=size-2; i>=0; i--){
			if(ratings[i]>ratings[i+1]){
				numbers[i]=Math.max(numbers[i], num++);
			}else{
				num=1;
			}
		}
		int sum=size;
		for(int i=0; i<size; i++){
			sum+=numbers[i];
		}
		return sum;
    }
}
 */

int main() {
    Solution sol;

    vector<int> vec = {1,2,2};
    cout << sol.candy(vec) << endl;

    return 0;
}
