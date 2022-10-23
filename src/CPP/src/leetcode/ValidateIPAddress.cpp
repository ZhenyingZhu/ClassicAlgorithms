/*
 * [Source] https://leetcode.com/problems/validate-ip-address/
 * [Difficulty]: Medium
 * [Tag]: String
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Use two different code path.
// [Corner Case]:
class Solution {
public:
    string validIPAddress(string IP) {
        if (IP.find(".") != string::npos) { // testcase: other punct
            if (validIPv4(IP))
                return "IPv4";
        } else if (IP.find(":") != string::npos) {
            if (validIPv6(IP))
                return "IPv6";
        }
        return "Neither";
    }

    bool validIPv4(string &ip) {
        vector<string> vec = split(ip, ".");
        if (vec.size() != 4)
            return false;

        for (string &s : vec) { // testcase: empty string
            if ( s.empty() || (s[0] == '0' && s.length() > 1) )
                return false;
            int val = 0;
            for (char &c : s) {
                if (!isdigit(c))
                    return false;
                val = val * 10 + c - '0';
                if (val > 255) // add here to avoid overflow number get passed
                    return false;
            }
        }
        return true;
    }

    bool validIPv6(string &ip) {
        vector<string> vec = split(ip, ":");
        if (vec.size() != 8)
            return false;

        for (string &s : vec) {
            if (s.empty() || s.length() > 4)
                return false;
            for (char &c : s) {
                if ( !isdigit(c) && !(c >= 'A' && c <= 'F') && !(c >= 'a' && c <= 'f') ) // testcase: not right char
                    return false;
            }
        }
        return true;
    }

    vector<string> split(string &s, string token) {
        vector<string> res;
        size_t pos = s.find_first_of(token);
        size_t st = 0;
        while (pos != string::npos) {
            res.push_back( s.substr(st, pos - st) );
            st = pos + 1;
            pos = s.find_first_of(token, st);
        }
        res.push_back(s.substr(st));
        return res;
    }
};

int main() {
    Solution sol;
    //cout << sol.validIPAddress("172.16.254.1") << endl;
    cout << sol.validIPAddress("172..254.1") << endl;
    //cout << sol.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334") << endl;

    return 0;
}
