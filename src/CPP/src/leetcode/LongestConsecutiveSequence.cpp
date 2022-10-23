/*
 * [Source] https://leetcode.com/problems/longest-consecutive-sequence/
 * [Difficulty]: Hard
 * [Tag]: Array
 * [Tag]: Union Find
 */

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Use a hash set to contain all values. Then exclude one value if used in the sequence.
// [Corner Case]:
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        int maxLen = 0;
        while (!set.empty()) {
            int st = *set.begin();
            int len = 1;
            set.erase(st);

            int nxt = st + 1;
            while (set.find(nxt) != set.end()) {
                ++len;
                set.erase(nxt++);
            }

            int pre = st - 1;
            while (set.find(pre) != set.end()) {
                ++len;
                set.erase(pre--);
            }

            maxLen = max(len, maxLen);
        }

        return maxLen;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/datastructure/LongestConsecutiveSequence.java
 */

/* Java solution
public class Solution {
    public int longestConsecutive(int[] num) {
		if(num.length<=0) return 0;
		HashSet<Integer> set=new HashSet<Integer>();
		for(int val: num){
			set.add(val);
		}
		int max=0;
		for(int val: num){
			int valLeft=val-1;
			int valRight=val+1;
			int cnt=1;
			set.remove(val);
			while(set.contains(valLeft)){
				cnt++;
				set.remove(valLeft);
				valLeft--;
			}
			while(set.contains(valRight)){
				cnt++;
				set.remove(valRight);
				valRight++;
			}
			if(cnt>max) max=cnt;
		}
		return max;
    }
}
 */

int main() {
    Solution sol;

    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutive(nums) << endl;

    return 0;
}
