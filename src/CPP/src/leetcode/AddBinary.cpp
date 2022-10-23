/*
 * [Source] https://leetcode.com/problems/add-binary/
 * [Difficulty]: Easy
 * [Tag]: Math
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: Use a carry
// [Corner Case]: two numbers are not same length
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/AddBinary.java
 */

/* Java solution
public class Solution {
    public String addBinary(String a, String b) {
		if(a.length()<b.length()){ // a always longer
			String tmp=a;
			a=b;
			b=tmp;
		}
		char[] first=a.toCharArray();
		char[] second=b.toCharArray();
		int aLen=a.length();
		int bLen=b.length();
		int[] res=new int[aLen];
		int c=0;
		for(int i=0; i<bLen; i++){
			res[aLen-1-i]=first[aLen-1-i]+second[bLen-1-i]-2*'0'+c;
			if(res[aLen-1-i]>=2){
				res[aLen-1-i]-=2;
				c=1;
			}else{
				c=0;
			}
		}
		for(int i=aLen-bLen-1; i>=0; i--){
			res[i]=first[i]-'0'+c;
			if(res[i]>=2){
				res[i]-=2;
				c=1;
			}else{
				c=0;
			}
		}
		StringBuffer result=new StringBuffer();
		if(c==1) result.append('1');
		for(int i=0; i<res.length; i++){
			result.append(Integer.toString(res[i]));
		}
		return result.toString();
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
