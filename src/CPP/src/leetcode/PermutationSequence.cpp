/*
 * [Source] https://leetcode.com/problems/permutation-sequence/
 * [Difficulty]: Medium
 * [Tag]: Backtracking
 * [Tag]: Math
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Use a vector indicate candidates. With n digits, if k/(2^(n-2)) = i, then add vec[i] to the begining
// [Corner Case]: only 1 number.
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> pos;
        int prod = 1;
        for (int i = 1; i < n; i++) {
            prod *= i;
            pos.push_back(prod);
        }
        reverse(pos.begin(), pos.end());

        vector<int> nums;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);

        k--;
        string res;
        for (int i = 0; i < (int)pos.size(); i++) {
            int p = k / pos[i];
            k %= pos[i];

            res.push_back('0' + get(nums, p));
        }
        res.push_back('0' + get(nums, 0));
        return res;
    }

    int get(vector<int> &nums, int idx) {
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != 0) {
                if (idx == 0) {
                    int tmp = nums[i];
                    nums[i] = 0;
                    return tmp;
                }
                idx--;
            }
        }
        return -1;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/PermutationSequence.java
 */

/* Java solution
public class Solution {
    public String getPermutation(int n, int k) {
		if(k<=0) return null;
        int[] array=new int[n];
		int[] factorials=new int[n-1];
		for(int i=0; i<n; i++){
			array[i]=i+1;
		}
		int fac=1;
		for(int i=1; i<n; i++){
			fac*=i;
			factorials[i-1]=fac;
		}
		StringBuffer prev=new StringBuffer();
		getPermutation(k-1, array, array.length-1, factorials, prev);
		return prev.toString();
    }
	
	public void getPermutation(int k, int[] array, int last, int[] factorials, StringBuffer prev){
		if(last==0){
			prev.append(array[0]);
			return;
		}
		int mul=k/factorials[last-1];
		int mod=k%factorials[last-1];
		prev.append(array[mul]);
		for(int i=mul; i<last; i++){
			array[i]=array[i+1];
		}
		getPermutation(mod, array, last-1, factorials, prev);
    }
}
 */

int main() {
    Solution sol;

    for (int i = 1; i <= 6; i++)
        cout << sol.getPermutation(3, i) << endl;

    return 0;
}
