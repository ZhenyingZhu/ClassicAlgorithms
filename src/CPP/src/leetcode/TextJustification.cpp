/*
 * [Source] https://leetcode.com/problems/text-justification/
 * [Difficulty]: Hard
 * [Tag]: String
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// [Solution]: Need deal last line different according to the question.
// [Corner Case]: if a string is just L length. if several string lengths sum to just L and no place for spaces
class Solution {
private:
    string constructString(vector<string>& vec, const int maxWidth) {
        int len = vec.size();

        int totalLen = 0;
        for (const string& s : vec) {
            totalLen += s.length();
        }

        int spaceLen = maxWidth - totalLen;
        if (len == 1)
            return vec[0] + string(spaceLen, ' ');

        int avgSpaceLen = spaceLen / (len - 1), additionalSpaces = spaceLen % (len - 1);

        string res;
        int i = 0;
        for (; i < additionalSpaces; ++i) {
            res += vec[i] + string(avgSpaceLen + 1, ' ');
        }
        for (; i < len - 1; ++i) {
            res += vec[i] + string(avgSpaceLen, ' ');
        }
        res += vec[i];

        return res;
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int len = words.size();
        if (len == 0)
            return res;

        vector<string> curLine = {words[0]};
        int curLen = words[0].length();
        for (int i = 1; i < len; ++i) {
            const string& curStr = words[i];
            // space need count
            if (curLen + 1 + curStr.length() > maxWidth) {
                res.push_back(constructString(curLine, maxWidth));
                curLine = {curStr};
                curLen = curStr.length();
            } else {
                curLine.push_back(curStr);
                curLen += 1 + curStr.length();
            }
        }
        
        string lastLine = curLine[0];
        for (size_t i = 1; i < curLine.size(); ++i) {
            lastLine += " " + curLine[i];
        }
        lastLine += string(maxWidth - curLen, ' ');
        res.push_back(lastLine);

        return res;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/TextJustification.java
 */

/* Java solution
public class Solution {
    public List<String> fullJustify(String[] words, int L) {
		List<String> result=new ArrayList<String>();
        int idx=0;
		while(idx<words.length){
			int len=words[idx].length();
			int end=idx+1;
			while(end<words.length){
				len+=1+words[end].length(); // Space ahead
				if(len>L){
					end=end-1;
					break;
				}else{
					end++;
				}
			}
			String line=createLine(words, L, idx, end);
			result.add(line);
			idx=end+1;
		}
		return result;
    }
	
	public String createLine(String[] words, int L, int idx, int end){
		if(end>=words.length) return createLastLine(words, L, idx);
		int interval=end-idx;
		if(interval==0) interval=1;
		int totalLen=L;
		for(int i=idx; i<=end; i++){
			totalLen-=words[i].length();
		}
		int spaceNum=totalLen/interval;
		int leftSpace=totalLen%interval;
		StringBuffer res=new StringBuffer();
		int cur=idx;
		while(cur<=end){
			res.append(words[cur]);
			if(interval<=0) break;
			if(leftSpace>0){
				for(int j=0; j<=spaceNum; j++) res.append(' ');
				leftSpace--;
			}else for(int j=0; j<spaceNum; j++) res.append(' ');
			interval--;
			cur++;
		}
		return res.toString();
	}
	
	public String createLastLine(String[] words, int L, int idx){
		StringBuffer res=new StringBuffer();
		res.append(words[idx++]);
		while(idx<words.length){
			res.append(' ');
			res.append(words[idx]);
			idx++;
		}
		int leftSpace=L-res.length();
		for(int i=0; i<leftSpace; i++){
			res.append(' ');
		}
		return res.toString();
    }
}
 */

int main() {
    Solution sol;

    //vector<string> vec = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> vec = {"What","must","be","shall","be."};
    //for (const string& s : sol.fullJustify(vec, 16)) {
    for (const string& s : sol.fullJustify(vec, 12)) {
        cout << s << endl;
    }

    return 0;
}
