/*
 * [Source] https://leetcode.com/problems/valid-anagram/
 * [Difficulty]: Easy
 * [Tag]: Hash Table
 * [Tag]: Sort
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// [Solution]: Use hash table. Notice there could be extra char in second string. So need to confirm all counts in hash table are 0.
// [Corner Case]:
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> charFreq;
        for (char& c : s)
            charFreq[c]++;

        for (char& c : t)
            charFreq[c]--;

        for (auto it = charFreq.begin(); it != charFreq.end(); ++it) {
            if (it->second != 0)
                return false;
        }
        return true;
    }
};

// [Solution]: Sort first string and second string. Compare with second string to see if they are same. 

int main() {
    Solution sol;

    cout << sol.isAnagram("anagram", "nagaram") << endl;
    cout << sol.isAnagram("anagram", "nagaramb") << endl;
    cout << sol.isAnagram("anagrama", "nagaram") << endl;

    return 0;
}
