/*
 * [Source] https://leetcode.com/problems/word-break-ii/
 * [Difficulty]: Hard
 * [Tag]: Dynamic Programming
 * [Tag]: Backtracking
 */

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>

using namespace std;

// [Solution]: Recursive find from index st, what is the result. Use a hash map to record the result, key is idx, and value is string vector.
// [Corner Case]:
class Solution {
private:
    vector<string> wordBreakHelper(const string& s, int st, int minLen, int maxLen, 
            const unordered_set<string>& wordDict, unordered_map<int, vector<string>>& partsAfterIdx) {
        int len = s.length();
        if (st == len)
            return {""};
        if (partsAfterIdx.find(st) != partsAfterIdx.end())
            return partsAfterIdx[st];

        vector<string> res;
        for (int i = minLen; i <= maxLen && st + i <= len; ++i) {
            string cur = s.substr(st, i);
            if (wordDict.find(cur) != wordDict.end()) {
                for (string& str : wordBreakHelper(s, st + i, minLen, maxLen, wordDict, partsAfterIdx)) {
                    if (str == "") { // end
                        res.push_back(cur);
                    } else {
                        res.push_back(cur + " " + str);
                    }
                }
            }
        }

        partsAfterIdx[st] = res;
        return res;
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.length() == 0 || wordDict.size() == 0)
            return {};

        int minLen = INT_MAX, maxLen = INT_MIN;
        for (const string& word : wordDict) {
            int len = word.length();
            minLen = min(len, minLen);
            maxLen = max(len, maxLen);
        }

        unordered_map<int, vector<string>> partsAfterIdx;
        return wordBreakHelper(s, 0, minLen, maxLen, wordDict, partsAfterIdx);
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/rcanddp/WordBreakSolution.java
 */

// [Solution]: first check if it is constructable, then construct it.
/* Java solution
public class Solution {
    public List<String> wordBreak(String s, Set<String> dict) {
		boolean[][] matrix=new boolean[s.length()][s.length()]; 
		boolean[] start=new boolean[s.length()+1]; // If a word end before it, then this is true, otherwise don't need to borther to check this line. 
		start[0]=true;
		for(int i=0; i<matrix.length; i++){
			if(!start[i]) continue;
			StringBuffer testWord=new StringBuffer();
			for(int j=i; j<matrix.length; j++){
				testWord.append(s.charAt(j));
				if(dict.contains(testWord.toString())){
					matrix[i][j]=true;
					start[j+1]=true;
				}
			}
		}
		List<String> list=new ArrayList<String>();
		if(!start[s.length()]){
			return list;
		}
		list=construct(s, matrix);
		return list;
    }
		
	public ArrayList<String> construct(String s, boolean[][] matrix){
		ArrayList<String> list=new ArrayList<String>();
		String prev=null;
		construct(s, matrix, list, 0, prev);
		return list;
	}
	public void construct(String s, boolean[][] matrix, List<String> list, int line, String prev){
		if(line==matrix.length){
			list.add(prev);
			return;
		}
		StringBuffer word=new StringBuffer();
		for(int i=line; i<matrix[line].length; i++){
			word.append(s.charAt(i));
			if(matrix[line][i]){
				String sentence=(prev==null)?word.toString():prev+" "+word.toString();
				construct(s, matrix, list, i+1, sentence);
			}
		}
    }
}
 */

int main() {
    Solution sol;

    unordered_set<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    for (string& s : sol.wordBreak("catsanddog", wordDict)) {
        cout << s << endl;
    }

    return 0;
}
