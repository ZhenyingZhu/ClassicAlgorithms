/*
 * [Source] https://leetcode.com/problems/word-break/
 * [Difficulty]: Medium
 * [Tag]: Backtracking
 * [Tag]: Dynamic Programming
 */

#include <iostream>

using namespace std;

// [Solution]: First compute the min and max length of dict words. Then try to seperate words from s[0,min] and s[min+1,end] to s[0,max] and s[max+1,end]. Recursive call.
// [Corner Case]:
class Solution {
};

// [Solution]: Use hash map to record if a string from index i is breakable.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/rcanddp/WordBreak.java
 */

/* Java solution
public class Solution {
    public boolean wordBreak(String s, Set<String> dict) {
		int size=s.length();
		boolean[] start=new boolean[size+1]; // Don't need a matrix to record
		start[0]=true;
		for(int i=0; i<size; i++){
			if(!start[i]) continue;
			StringBuffer testWord=new StringBuffer();
			for(int j=i; j<size; j++){
				testWord.append(s.charAt(j));
				if(dict.contains(testWord.toString())){
					start[j+1]=true;
				}
			}
		}
		return start[size];
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
