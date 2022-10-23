/*
 * [Source] https://leetcode.com/problems/integer-to-english-words/
 * [Difficulty]: Hard
 * [Tag]: Math
 * [Tag]: String
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Not hard. Part each 3 digits.
// [Corner Case]: middle 0 shouldn't print. Space at the end should elimited
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        vector<string> numStrings;
        while (num > 0) {
            numStrings.push_back(convert(num % 1000));
            num /= 1000;
        }

        vector<string> units = {"Thousand", "Million", "Billion"};
        string res("");
cout<< numStrings.size() << endl;
        for (int i = (int)numStrings.size() - 1; i > 0; --i) {
            if (numStrings[i] != "")
                res += numStrings[i] + " " + units[i - 1] + " ";
        }
        res += numStrings[0];

        if (res.back() == ' ')
            res.erase(res.end() - 1);

        return res;
    }

    string convert(int num) {
        int hundred = num / 100, ten = num % 100;

        string res("");
        if (hundred > 0) {
            res += onesMap[hundred] + " Hundred ";
        }

        if (ten < 20) {
            res += onesMap[ten]; // Deal with 0 as well
        } else {
            int tenDight = ten / 10, oneDigit = ten % 10;
            res += tensMap[tenDight];
            if (oneDigit > 0)
                res += " " + onesMap[oneDigit];
        }

        if (res.back() == ' ')
                        res.erase(res.end() - 1);

        return res;
    }

    vector<string> onesMap = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tensMap = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> testCases = {123, 12345, 1234567, 123000, 1000010, 100000};
    vector<string> results = {"One Hundred Twenty Three", "Twelve Thousand Three Hundred Forty Five", "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
        , "One Hundred Twenty Three Thousand", "One Million Ten", "One Hundred Thousand"};

    for (size_t i = 0; i < testCases.size(); ++i) {
        string r = sol.numberToWords(testCases[i]);
        cout << r;
        if (r != results[i])
            cout << " Fail";
        cout << endl;
    }

    return 0;
}
