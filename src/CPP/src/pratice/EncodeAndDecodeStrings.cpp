#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/encode-and-decode-strings/
// http://www.1point3acres.com/bbs/thread-211115-1-1.html

class Codec {
public:
    string encode(vector<string> &strs) {
        string res = "";
        for (string &str : strs) {
            res += "(" + to_string(str.length()) + ")" + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        if (s.empty())
            return {};

        vector<string> res;
        size_t left = 0;
        while (left < s.size()) {
            size_t right = s.find_first_of(")", left);
            int size = stoi(s.substr(left + 1, right - left - 1));
            res.push_back(s.substr(right + 1, size));
            left = right + size + 1;
        }
        return res;
    }
};

int main() {
    Codec c;

    vector<string> strs = {"a", "bb", "ccc"};
    string tmp = c.encode(strs);
    cout << tmp << endl;
    for (string &s : c.decode(tmp))
        cout << s << " ";
    cout << endl;

    return 0;
}
