/*
 * [Source] https://leetcode.com/problems/decode-ways/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: D[i]=D[i-1]+D[i-2] if S[i-1][i] is valid
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/DecodeWays.java
 */

/* Java solution
public class Solution {
    public int numDecodings(String s) {
		if(s.length()<1) return 0;
		if(s.charAt(0)=='0') return 0;
		for(int i=0; i<s.length(); i++){
			if(s.charAt(i)<'0' || s.charAt(i)>'9') return 0;
		}
		if(s.length()==1) return 1;
        int[] array=new int[s.length()+1];
		array[0]=1; array[1]=1;
		for(int i=1; i<s.length(); i++){
			if(s.charAt(i)=='0'){
				if(s.charAt(i-1)=='0' || s.charAt(i-1)>'2') return 0;
				else{
				array[i+1]=array[i-1];
				continue;
				}
			}
			int sum=array[i];
			if(s.charAt(i-1)!='0' && Integer.parseInt(s.substring(i-1, i+1))<=26) sum+=array[i-1];
			array[i+1]=sum;
		}
		return array[s.length()];
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
