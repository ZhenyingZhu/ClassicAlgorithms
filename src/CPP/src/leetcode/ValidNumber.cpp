/*
 * [Source] https://leetcode.com/problems/valid-number/
 * [Difficulty]: Hard
 * [Tag]: Math
 * [Tag]: String
 */

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

// [Solution]: Deal with case by case.
// [Corner Case]: All cases are corner cases.
class Solution {
private:
    string trim(const string& s) {
        size_t st = s.find_first_not_of(' ');
        if (st == string::npos)
            return s;
        size_t ed = s.find_last_not_of(' '); // cannot not found, otherwise st is npos
        return s.substr(st, ed - st + 1);
    }

    bool containsInvalidChar(const string& s) {
        int len = s.length();
        int ePos = len, dotPos = len;
        for (int i = 0; i < len; ++i) {
            char c = s[i];
            if (c == '+' || c == '-') {
                // sign can only show at beginning or after Exp
                if (i != 0 && i != ePos + 1)
                    return true;
            } else if (c == 'e' || c == 'E') {
                // Exp can only show once
                if (ePos != len)
                    return true;
                ePos = i;
            } else if (c == '.') {
                // dot can only show once and before Exp
                if (dotPos != len || i > ePos)
                    return true;
                dotPos = i;
            } else if ( !isdigit(c) ) {
                return true;
            }
        }
        return false;
    }

    vector<string> split(const string& s, string delims) {
        vector<string> tokens;

        for (const char& c : delims) {
            size_t p = s.find(c);
            if (p != string::npos) {
                tokens.push_back(s.substr(0, p));
                if (p == s.length() - 1) {
                    tokens.push_back("");
                } else {
                    tokens.push_back(s.substr(p + 1, s.length() - p - 1));
                }
            }
        }
        if (tokens.size() == 0)
            tokens.push_back(s);

        return tokens;
    }

    bool isInteger(const string& s) {
        if (s.find('.') != string::npos || s.length() == 0)
            return false;
        size_t i = 0;
        if (s[0] == '+' || s[0] == '-')
            ++i;
        return s.length() > i;
    }

    bool isValidDicimal(const string& s) {
        // cannot only has a dot
        if (s.length() == 0)
            return false;
        size_t i = 0;
        if (s[0] == '+' || s[0] == '-')
            ++i;
        if (s.length() == i)
            return false;
        return !(s[i] == '.' && s.length() == i + 1);
    }

public:
    bool isNumber(string s) {
        string str = trim(s);
        if ( str == "" || containsInvalidChar(str) )
            return false;

        vector<string> breakByExp = split(str, "eE");
        if (breakByExp.size() == 2) {
            if (!isInteger(breakByExp[1]))
                return false;
        }
        if (!isValidDicimal(breakByExp[0]))
            return false;

        return true;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/ValidNumber.java
 */

/* Java solution
public class Solution {
    public boolean isNumber(String s) {
        if(s==null || s.length()<=0) return false;
		int startSpace=0;
		while(s.charAt(startSpace)==' '){
			startSpace++;
			if(startSpace>=s.length()) return false;
		}
		int endSpace=s.length()-1;
		while(s.charAt(endSpace)==' '){
			endSpace--;
			if(endSpace<0) return false;
		}
		s=s.substring(startSpace, endSpace+1); // Allow space at head or end
		
		int point=-1;
		int exp=s.length();
		for(int i=0; i<s.length(); i++){
			if(s.charAt(i)=='.'){
				if(point==-1) point=i;
				else return false;
			}
			if(s.charAt(i)=='e' || s.charAt(i)=='E'){
				if(exp==s.length()) exp=i;
				else return false;
			}
		}
		if(exp==0 || exp==s.length()-1) return false; // not allow 3e or e3 or e
		if(point!=-1 && s.length()==1) return false; // allow 3. and .3 but not .
		if(exp<point) return false; // exp cannot be dicimal
		
		boolean numberBeforeExp=false;
		int cur=0;
		if(s.charAt(cur)=='+' || s.charAt(cur)=='-'){
			cur++;
			if(cur==s.length() || s.charAt(cur)=='e') return false;
		}
		while(cur!=point && cur<exp){ // After sign bit, no special before dot or exp
			if(!Character.isDigit(s.charAt(cur))) return false;
			numberBeforeExp=true;
			cur++;
		}
		if(cur==exp && !numberBeforeExp) return false; // +e or + is not allowed
		if(cur==point){
			cur++; 
			while(cur<exp){
				if(!Character.isDigit(s.charAt(cur))) return false; // Not allow .+
				numberBeforeExp=true;
				cur++;
			}
		}
		if(!numberBeforeExp) return false; // cur==exp, +.e or +. is not allowed
		if(exp==s.length()) return true; // end
		cur++; 
		if(cur==s.length()) return false; // not allow 1.23e
		if(s.charAt(cur)=='+' || s.charAt(cur)=='-'){
			cur++;
			if(cur==s.length()) return false; // not allow 1.23e+
		}
		while(cur<s.length()){
			if(!Character.isDigit(s.charAt(cur))) return false;
			cur++;
		}
		return true;
	}
}
 */

int main() {
    Solution sol;

    vector<string> cases = {".", "+", "e", "1.", "+.0", "1"};
    for (const string& s : cases) {
        cout << sol.isNumber(s) << endl;
    }

    return 0;
}
