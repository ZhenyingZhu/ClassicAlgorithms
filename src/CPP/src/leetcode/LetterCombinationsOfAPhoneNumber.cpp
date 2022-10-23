/*
 * [Source] https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * [Difficulty]: Medium
 * [Tag]: Backtracking
 * [Tag]: String
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// [Solution]: Use an char array. In a recursive function, each time replace the last char and call itself with next digit.
// [Corner Case]: 1 is empty string and 0 is space. Be careful about 1, if only 1, return empty vector.
class Solution {
private:
    void letterHelper(const string& digits, const vector<string>& mapping, int idx, vector<char>& prev, vector<string>& res) {
        if (idx == (int)digits.length()) {
            res.push_back(string(prev.begin(), prev.end()));
            return;
        }

        string represent = mapping[digits[idx] - '0'];
        if (represent == "") {
            letterHelper(digits, mapping, idx + 1, prev, res);
            return;
        }

        for (const char& c : represent) {
            prev.push_back(c);
            letterHelper(digits, mapping, idx + 1, prev, res);
            prev.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return {};
        }

        vector<string> res;
        vector<string> mapping = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<char> candidate;

        letterHelper(digits, mapping, 0, candidate, res);
        return res;
    }
};

/* Java solution
public class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<String>(); 
        if (digits == null) {
            return result; 
        }
        // index means the number
        String[] map = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
        letterCombinationsHelper(digits, 0, map, "", result); 
        return result; 
    }
    
    private void letterCombinationsHelper(String digits, int idx, String[] map, String prev, List<String> result){
        if (idx == digits.length()) {
            result.add(prev); 
            return; 
        }
        int digit = digits.charAt(idx) - '0'; 
        if (digit == 1) {
            letterCombinationsHelper(digits, idx + 1, map, prev, result); 
            return; 
        }
        char[] possibles = map[digit].toCharArray(); 
        for (int i = 0; i < possibles.length; ++i) {
            String cur = prev + possibles[i]; 
            letterCombinationsHelper(digits, idx + 1, map, cur, result); 
        }
    }
}
 */

// [Solution]: Use a list to store previous results. And add current char to the end of each result in the list.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/LetterCombinationsOfAPhoneNumber.java
 */

int main() {
    Solution sol;
    
    //vector<string> res = sol.letterCombinations("");
    //vector<string> res = sol.letterCombinations("1");
    vector<string> res = sol.letterCombinations("0123");
    int id = 0;
    for (const string& s : res)
        cout << id++ << ": " << s << endl;

    return 0;
}
