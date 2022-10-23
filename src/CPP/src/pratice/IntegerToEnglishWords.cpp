#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        digit = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        vector<string> units = {"", "Thousand", "Million", "Billion"};

        vector<string> res;
        while (num > 0) {
            res.push_back(helper(num % 1000));
            num /= 1000;
        }

        string words;
        for (int i = 0; i < (int)res.size(); ++i) {
            if (res[i].empty())
                continue;
            if (i == 0) {
                words = res[i];
                continue;
            }

            string prefix = res[i] + " " + units[i];
            if (words.empty())
                words = prefix;
            else
                words = prefix + " " + words;
        }

        return words;
    }

private:
    string helper(int num) {
        if (num == 0)
            return "";

        string res;
        if (num >= 100) {
            res += digit[num / 100] + " Hundred";
            num = num % 100;
            if (num > 0)
                res += " ";
            else
                return res;
        }

        if (num < (int)digit.size()) {
            res += digit[num];
            return res;
        }

        if (num >= 20) {
            res += tens[num / 10];
            num = num % 10;
            if (num > 0)
                res += " ";
            else
                return res;
        }

        if (num != 0) {
            res += digit[num];
        }

        return res;
    }

    vector<string> digit;
    vector<string> tens;
};

int main() {
    Solution sol;

    //cout << sol.numberToWords(1234567) << endl;
    //cout << sol.numberToWords(12000) << endl;
    //cout << sol.numberToWords(1200007) << endl;
    cout << sol.numberToWords(100) << endl;

    return 0;
}
