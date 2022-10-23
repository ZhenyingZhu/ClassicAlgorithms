/*
 * [Source] https://leetcode.com/problems/restore-ip-addresses/
 * [Difficulty]: Medium
 * [Tag]: Backtracking
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: If the current one, two, or three digits are valid, compute the next one.
// [Corner Case]: 0 at the begining, 000 as a digit, already four parts.
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/rcanddp/RestoreIPAddresses.java
 */

/* Java solution
public class Solution {
    public List<String> restoreIpAddresses(String s) {
		List<String> result=new ArrayList<String>();
		if(s.length()<4 || s.length()>12) return result;
		for(int i=0; i<s.length(); i++){
			if(s.charAt(i)<'0' || s.charAt(i)>'9') return result;
		}
		restoreIpAddresses(s, "", 1, result);
		return result;
    }
	
	public void restoreIpAddresses(String left, String prev, int order, List<String> list){
		if(left.equals("")) return;
		if(order==4){
			if(left.charAt(0)=='0' && left.length()>1) return;
			if(Integer.parseInt(left)>255) return;
			prev+=left;
			list.add(prev);
			return;
		}
		if(left.charAt(0)=='0'){
			String result=prev+"0.";
			restoreIpAddresses(left.substring(1), result, order+1, list);
			return;
		}
		int size=(left.length()>=3)?2:left.length();
		for(int i=0; i<size; i++){
			String digit=left.substring(0, i+1);
			String result=prev+digit+".";
			restoreIpAddresses(left.substring(i+1), result, order+1, list);
		}
		if(left.length()<=2) return;
		String digit=left.substring(0, 3);
		if(Integer.parseInt(digit)>255) return;
		String result=prev+digit+".";
		restoreIpAddresses(left.substring(3), result, order+1, list);
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
