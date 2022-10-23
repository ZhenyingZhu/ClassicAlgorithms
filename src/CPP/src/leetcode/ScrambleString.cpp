/*
 * [Source] https://leetcode.com/problems/scramble-string/
 * [Difficulty]: Hard
 * [Tag]: Dynamic Programming
 * [Tag]: String
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// [Solution]: From defination, if s1[0,i]=s2[0,i] and s1[i,l]=s2[i,l], or s1[0,i]=s2[l-i,l] and s1[i,l]=s2[0,i], return true. One fail case is "abcd" and "bdac". Use hash table to save time
// [Corner Case]:
class Solution {
private:
    bool isScrambleHelper(const string& s1, const string& s2, unordered_map<string, bool>& map) {
        if (s1 == s2)
            return true;

        if (s1.length() != s2.length() || s1.length() == 1)
            return false;

        string key = s1 + "/" + s2;
        unordered_map<string, bool>::iterator it = map.find(key);
        if (it != map.end()) {
            cout << key << endl;
            return it->second;
        }

        int len = s1.length();
        for (int i = 1; i < len; ++i) {
            string s1Left = s1.substr(0, i), s1Right = s1.substr(i, len - i);

            string s2Left = s2.substr(0, i), s2Right = s2.substr(i, len - i);
            if (isScrambleHelper(s1Left, s2Left, map) && isScrambleHelper(s1Right, s2Right, map)) {
                map[key] = true;
                return true;
            }

            string s2Left2 = s2.substr(0, len - i), s2Right2 = s2.substr(len - i, i);
            if (isScrambleHelper(s1Left, s2Right2, map) && isScrambleHelper(s1Right, s2Left2, map)) {
                map[key] = true;
                return true;
            }
        }

        map[key] = false;
        return false;
    }

public:
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> map;
        return isScrambleHelper(s1, s2, map);
    }
};

// [Solution]: Dynamic processing. when k is the length, i is the st of s1, and j is the st of s2. D[k][i][j] = D[x][i][j] && D[k-x][i+x][j+x] || D[x][i][j+k-x] && D[k-x][i+k-x][j]
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/rcanddp/ScrambleString.java
 */

/* Java solution
public class Solution {
    public boolean isScramble(String s1, String s2) {
        if(s1.length()!=s2.length()) return false;
		if(s1.equals(s2)) return true;
		if(s1.length()==1 && s2.length()==1 && !s1.equals(s2)) return false;
		int len=s1.length();
		boolean[][][] matrix=new boolean[len][len][len];
		for(int i=0; i<len; i++){ // The first chart
			for(int j=0; j<len; j++){
				if(s1.charAt(i)==s2.charAt(j)){
					matrix[0][i][j]=true;
				}
			}
		}
		for(int n=2; n<=len; n++){ // n length strings
			for(int i=0; i<=len-n; i++){ // start from i of s1
				for(int j=0; j<=len-n; j++){ // start from j of s2
					for(int k=1; k<n; k++){ // first part is k length
						if((matrix[k-1][i][j] && matrix[n-k-1][i+k][j+k]) // first part of s1=first part of s2
						|| (matrix[k-1][i][j+n-k] && matrix[n-k-1][i+k][j])){ // second part of s1=first part of s2
							matrix[n-1][i][j]=true;
							break; // It is already true
						}
					}
				}
			}
		}
		return matrix[len-1][0][0];
    }
}
 */

int main() {
    Solution sol;

/*
    if ( !sol.isScramble("rgeat", "great") )
        cout << "1 Fail" << endl;
    if ( !sol.isScramble("rgtae", "great") )
        cout << "2 Fail" << endl;
    if ( sol.isScramble("abcd", "bdac") )
        cout << "3 Fail" << endl;
*/
    if ( sol.isScramble("abcdefghijklmnopq", "efghijklmnopqcadb") )
        cout << "4 Fail" << endl;

    return 0;
}
