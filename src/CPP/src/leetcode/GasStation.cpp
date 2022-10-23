/*
 * [Source] https://leetcode.com/problems/gas-station/
 * [Difficulty]: Medium
 * [Tag]: Greedy
 */

#include <iostream>

using namespace std;

// [Solution]: If pre + gas[i] < cost[i], then set i+1 as starter. Until reach starter again. Since if we cannot reach one station, it means starter cannot be any previous station, as we always have a greater-than-0 pre.
// [Corner Case]: Cannot reach starter again, return -1.
class Solution {
};

// [Solution]: If cannot finish the circle, the sum of gas[i] < sum of cost[i]. Use this to pass the array only once.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/GasStation.java
 */

/* Java solution
public class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
		if(gas.length!=cost.length) return -1;
		int start=-1; // The valid start point. 
		int leftGas=0; // If <0, then cannot start at current station. 
		int total=0;
		for(int i=0; i<gas.length; i++){
			total+=gas[i]-cost[i];
			leftGas+=gas[i]-cost[i];
			if(leftGas<0){
				start=i;
				leftGas=0;
			}
		}
		if(total<0) return -1;
		else return start+1;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
