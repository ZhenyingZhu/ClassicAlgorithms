/*
 * [Source] https://leetcode.com/problems/first-missing-positive/
 * [Difficulty]: Hard
 * [Tag]: Array
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Bucket sort. Cannot use sum and compare because there might be dup.
// [Corner Case]: If all positive values show up, return the next of the largest value. Dup cause infinite loop.
class Solution {
private:
    void bucketSort(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            while (nums[i] > 0 && nums[i] <= len && nums[i] != i + 1) {
                int val = nums[i];
                int pos = val - 1;
                if (nums[pos] == val)
                    break;

                nums[i] = nums[pos];
                nums[pos] = val;
            }
        }
    }

public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 1;

        bucketSort(nums);
        for (int i = 0; i < len; ++i) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return len + 1;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/sortandsearch/FirstMissingPositive.java
 */

/* Java solution
public class Solution {
    public int firstMissingPositive(int[] A) {
        bucketSort(A);
        for(int i=0; i<A.length; i++){
            if(A[i]!=i+1) return i+1;
        }
        return A.length+1;
    }
    
    private void bucketSort(int[] array){
        for(int i=0; i<array.length; i++){
            while(array[i]!=i+1){
                if(array[i]<=0 || array[i]>array.length || array[i]==array[array[i]-1]){
                    break;
                }else{
                    int tmp=array[array[i]-1];
                    array[array[i]-1]=array[i];
                    array[i]=tmp;
                }
            }
        }
    }
}
 */

int main() {
    Solution sol;

    vector<int> vec = {1};
    //vector<int> vec = {1, 2, 0};
    //vector<int> vec = {3, 4, -1, 1};
    cout << sol.firstMissingPositive(vec) << endl;

    return 0;
}
