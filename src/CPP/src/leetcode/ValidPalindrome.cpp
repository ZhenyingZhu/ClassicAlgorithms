/*
 * [Source] https://leetcode.com/problems/valid-palindrome/
 * [Difficulty]: Easy
 * [Tag]: Two Pointers
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: One pointer from begin, one from end. Skip non-alpha chars. Stop when they meet.
// [Corner Case]: 
class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0, ed = s.length() - 1;
        while (st < ed) {
            if (!isalnum(s[st])) {
                st++;
            } else if (!isalnum(s[ed])) {
                ed--;
            } else {
                char a = s[st], b = s[ed];
                if (a >= 'A' && a <= 'Z')
                    a -= 'A' - 'a';
                if (b >= 'A' && b <= 'Z')
                    b -= 'A' - 'a';
                if (a != b)
                    return false;
                st++;
                ed--;
            }
        }
        return true;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/ValidPalindrome.java
 */

/* Java solution
public class Solution {
    public boolean isPalindrome(String s) {
		if(s==null) return false;
		if(s.equals("")) return true; 
		int before=0;
		int after=s.length()-1;
		char[] stringArray=s.toCharArray();
		while(before<after){
			while(!Character.isLetterOrDigit(stringArray[before])){
				before++;
				if(before>=s.length()) return true;
			}
			if(stringArray[before]<='Z' && stringArray[before]>='A'){
				stringArray[before]=(char)(stringArray[before]+'a'-'A');
			}
			while(!Character.isLetterOrDigit(stringArray[after])){
				after--;
			}
			if(stringArray[after]<='Z' && stringArray[before]>='A'){
				stringArray[after]=(char)(stringArray[after]+'a'-'A');
			}
			if(before>=after) break;
			if(stringArray[before]!=stringArray[after]) return false;
			before++; after--;
		}
		return true;
    }
}
 */

int main() {
    Solution sol;

    cout << sol.isPalindrome("aA") << endl;

    return 0;
}
