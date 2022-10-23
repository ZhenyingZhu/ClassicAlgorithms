/*
 * [Source] https://leetcode.com/problems/palindrome-partitioning/
 * [Difficulty]: Medium
 * [Tag]: Backtracking
 */

#include <iostream>

using namespace std;

// [Solution]: start from 0 to end, if s[0,i] is palindrome, then add s[0,i] and recursive call to deal with s[i+1,end]. Use s[0]==s[i] && isPalindrome(s[1,i-1]) to fast the process.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/rcanddp/PalindromePartitioning.java
 */

/* Java solution
public class Solution {
    public ArrayList<ArrayList<String>> partition(String s) {
		ArrayList<String> prev=new ArrayList<String>();
		ArrayList<ArrayList<String>> result=new ArrayList<ArrayList<String>>();
		partition(s, 0, prev, result);
		return result;
    }
	
	public void partition(String s, int pos, ArrayList<String> prev, ArrayList<ArrayList<String>> result){
		if(pos==s.length()) return;
		partition(s, pos+1, prev, result);
		if(!isPalindrome(s, pos)) return;
		ArrayList<String> addition=(ArrayList<String>)prev.clone();
		addition.add(s.substring(0, pos+1));
		if(pos==s.length()-1){
			result.add(addition);
			return;
		}
		partition(s.substring(pos+1), 0, addition, result);
	}
	
	public boolean isPalindrome(String s, int end){
		int start=0; 
		while(start<end){
			if(s.charAt(start)!=s.charAt(end)) return false;
			start++; end--;
		}
		return true;
	}
}
 */

int main() {
    Solution sol;

    return 0;
}
