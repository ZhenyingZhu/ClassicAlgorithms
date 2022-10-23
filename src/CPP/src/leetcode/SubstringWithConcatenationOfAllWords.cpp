/*
 * [Source] https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 * [Difficulty]: Hard
 * [Tag]: Hash Table
 * [Tag]: Two Pointers
 * [Tag]: String
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// [Solution]: Moving window
// [Corner Case]: words have dup. not start from s index 0.
class Solution {
private:
    int deleteHead(const string& s, int head, unordered_map<string, int>& showedStrings, const int len) {
        string remove = s.substr(head, len);
        --showedStrings[remove];
        return head + len;
    }

    void findHelper(const string& s, int st, const unordered_map<string, int>& freq, const int len, const int total, vector<int>& res) {
        unordered_map<string, int> showedStrings;

        int head = st;
        int found = 0;
        for (int i = st; i <= s.length() - len; i += len) {
            string cur = s.substr(i, len);
            const auto it = freq.find(cur);
            if ( it == freq.end() ) {
                findHelper(s, i + len, freq, len, total, res);
                return;
            }

            ++found;
            ++showedStrings[cur];

            while (showedStrings[cur] > it->second) {
                head = deleteHead(s, head, showedStrings, len);
                --found;
            }

            if (found == total) {
                res.push_back(head);
                head = deleteHead(s, head, showedStrings, len);
                --found;
            }

        }
    }

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.size() == 0)
            return res;

        unordered_map<string, int> freq;
        for (const string& word : words) {
            ++freq[word]; // it works!
        }

        int len = words[0].length();
        for (int i = 0; i < len; ++i) {
            findHelper(s, i, freq, len, words.size(), res);
        }

        return res;
    }

};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/SubstringWithConcatenationOfAllWords.java
 */

/* Java solution
public class Solution {
    public List<Integer> findSubstring(String S, String[] L) {
        List<Integer> result = new ArrayList<Integer>(); 
        if(L == null || L.length == 0) {
            return result; 
        }
        int len = L[0].length(); 
        int amt = L.length; 
        if(S == null || S.length() < amt * len) {
            return result; 
        }
        HashMap<String, Integer> words = new HashMap<String, Integer>(); 
        for(String word : L) {
            if(words.containsKey(word)) { // If repeat
                words.put(word, words.get(word) + 1); 
            } else {
                words.put(word, 1); 
            }
        }
        for(int start = 0; start < len; ++start) {
            HashMap<String, Integer> map = new HashMap<String, Integer>(words); 
            Queue<String> queue = new LinkedList<String>(); 
            int idx = start; 
            for(int i = start; i < S.length() - len + 1; i += len) { // last i should equal to s - len
                String tempStr = S.substring(i, i + len); 
                if(!map.containsKey(tempStr)) {
                    idx = i + len; 
                    map = new HashMap<String, Integer>(words); 
                    queue = new LinkedList<String>(); 
                    continue; 
                }
                queue.offer(tempStr);
                if(map.get(tempStr) > 0) {
                    map.put(tempStr, map.get(tempStr) - 1); 
                    if(queue.size() == amt) { // Find one, but might be part of next
                        result.add(idx); 
                        idx += len; 
                        String rm = queue.poll(); 
                        map.put(rm, map.get(rm) + 1); 
                    }
                } else { // tempStr repeat
                    String rm = queue.poll(); 
                    idx += len; 
                    while(!rm.equals(tempStr)) {
                        map.put(rm, map.get(rm) + 1); 
                        idx += len; 
                        rm = queue.poll(); 
                    }
                    map.put(tempStr, 0); 
                }
            }
        }
        return result; 
    }
}
 */

int main() {
    Solution sol;

    vector<string> words = {"bar","foo","the"};
    vector<int> res = sol.findSubstring("barfoofoobarthefoobarman", words);
    for (const int& i : res)
        cout << i << ",";
    cout << endl;

    return 0;
}
