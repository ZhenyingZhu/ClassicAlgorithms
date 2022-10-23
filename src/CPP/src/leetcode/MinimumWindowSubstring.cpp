/*
 * [Source] https://leetcode.com/problems/minimum-window-substring/
 * [Difficulty]: Hard
 * [Tag]: Hash Table
 * [Tag]: Two Pointers
 * [Tag]: String
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <climits>
#include <deque>

using namespace std;

// [Solution]: Use a hash table to record the position of chars. Only leave necessary number of positions. st should be the smallest position in the hash table.
// [Corner Case]: If t contains duplicate chars
class Solution {
private:
    int findStart(unordered_map<char, deque<int>>& map) {
        int st = INT_MAX;
        for (unordered_map<char, deque<int>>::iterator it = map.begin(); it != map.end(); ++it) {
            st = min(st, it->second[0]);
        }
        return st;
    }

public:
    string minWindow(string s, string t) {
        int sLen = s.length(), tLen = t.length();
        if (tLen > sLen)
            return "";

        unordered_map<char, deque<int>> charPoses;
        unordered_map<char, size_t> freq;
        for (const char& c : t) {
            charPoses[c] = {};
            ++freq[c];
        }

        int contains = 0, minLen = INT_MAX;
        int st = -1, pt = -1;
        for (int i = 0; i < sLen; ++i) {
            const char& c = s[i];
            unordered_map<char, deque<int>>::iterator it = charPoses.find(c);
            if (it == charPoses.end())
                continue;

            if (it->second.size() < freq[c])
                ++contains;

            it->second.push_back(i);
            while (it->second.size() > freq[c]) {
                it->second.pop_front();
            }

            if (contains == tLen) {
                pt = findStart(charPoses);
                if (i - pt + 1 < minLen) {
                    minLen = i - pt + 1;
                    st = pt;
                }
            }
        }

        if (st == -1)
            return "";
        return s.substr(st, minLen);
    }
};

// [Solution]: Use two pointers. Use hash table to track the number of appearance of a char. When find one, move slower pointer to make all chars show up necessary times.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/MinimumWindowSubstring.java
 */

/* Java solution
public class Solution {
    public String minWindow(String S, String T) {
        if(S==null || T==null || S.length()==0 || T.length()==0) return "";
        int minStart=-1;
        int start=0;
        int minWindow=Integer.MAX_VALUE;
        HashMap<Character, Integer> map=new HashMap<Character, Integer>();
        int contain=0;
        for(int i=0; i<T.length(); i++){ // Get all char in T
            if(map.containsKey(T.charAt(i))) map.put(T.charAt(i), map.get(T.charAt(i))+1);
            else map.put(T.charAt(i), 1);
        }
        for(int i=0; i<S.length(); i++){
            char cur=S.charAt(i); // The end of window
            if(!map.containsKey(cur)) continue; // Unvalid char
            map.put(cur, map.get(cur)-1); // find one
            if(map.get(cur)>=0) contain++;
            while(contain==T.length()){
                char srt=S.charAt(start);
                if(!map.containsKey(srt)){
                    start++;
                    continue;
                }
                map.put(srt, map.get(srt)+1); // delete one
                if(map.get(srt)>0){ // start not in window
                    if(minWindow>(i-start+1)){
                        minWindow=i-start+1;
                        minStart=start;
                    }
                    contain--;
                }
                start++;
            }
        }
        if(minStart==-1) return "";
        return S.substring(minStart, minStart+minWindow);
    }
}
 */

int main() {
    Solution sol;

    //cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl;
    //cout << sol.minWindow("AA", "AA") << endl;
    cout << sol.minWindow("cabwefgewcwaefgcf", "cae") << endl;

    return 0;
}
