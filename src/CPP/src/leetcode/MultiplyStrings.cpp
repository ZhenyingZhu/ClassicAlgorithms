/*
 * [Source] https://leetcode.com/problems/multiply-strings/
 * [Difficulty]: Medium
 * [Tag]: Math
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: Two level loops. Use m + n cells to record results because 999*99 is length 5. Compute in reverse order.
// [Corner Case]: Highest bit is 0
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/MultiplyStrings.java
 */

/* Java solution
public class Solution {
    public String multiply(String num1, String num2) {
		if(num1.equals("0") || num2.equals("0")) return "0";
		int[] store=new int[num1.length()+num2.length()];
		num1=new StringBuffer(num1).reverse().toString(); // Otherwise 99*99 the first cell should be empty
		num2=new StringBuffer(num2).reverse().toString();
        for(int i=0; i<num1.length(); i++){ 
			int a=num1.charAt(i)-'0';
			for(int j=0; j<num2.length(); j++){
				int b=num2.charAt(j)-'0';
				store[i+j]+=a*b;
			}
		}
		StringBuffer result=new StringBuffer();
		int carry=0;
		for(int i=0; i<store.length-1; i++){
			int cur=store[i]+carry;
			result.insert(0, cur%10);
			carry=cur/10; 
		}
		int cur=store[store.length-1]+carry;
		if(cur!=0) result.insert(0, cur); // Wont have more than 0 at first
		return result.toString();
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
