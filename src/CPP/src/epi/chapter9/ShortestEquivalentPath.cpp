#include "ShortestEquivalentPath.hpp"

#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <vector>

using std::stack;
using std::string;
using std::stringstream;
using std::stoi;
using std::length_error;
using std::invalid_argument;
using std::cout;
using std::endl;
using std::vector;

namespace epi {
  namespace chapter9 {

    string ShortestEquivalentPath::shortestEquivalentPath(const string &path) {
        if (path.empty())
            throw invalid_argument("Path cannot be empty");

        stringstream ss(path);
        string token;
        vector<string> stack;

        if (path.front() == '/')
            stack.push_back("/");

        while (getline(ss, token, '/')) {
            if (token == "..") {
                if (stack.empty() || stack.back() == "..") {
                    stack.push_back(token);
                } else if (stack.back() == "/") {
                    throw invalid_argument("No parent for root");
                } else {
                    stack.pop_back();
                }
            } else if (token != "." && token != "") {
                stack.push_back(token);
            }
        }

        if (stack.empty()) {
            return ".";
        }

        string res(stack.front());
        for (size_t i = 1; i != stack.size(); ++i) {
            if (i == 1 && res == "/") {
                res += stack[i];
            } else {
                res += "/" + stack[i];
            }
        }

        return res;
    }

    bool ShortestEquivalentPath::test() {
        vector<string> tests = {
                "/a/b/../c/",
                "../a/b/./c",
                "a/b/c",
                ".//"
        };

        vector<string> anses = {
                "/a/c",
                "../a/b/c",
                "a/b/c",
                "."
        };

        for (size_t i = 0; i != tests.size(); ++i) {
            string str = tests[i];
            string ans = anses[i];
            if (shortestEquivalentPath(str) != ans) {
                cout << "Should Be: " << ans << endl;
                cout << "Result: " << shortestEquivalentPath(str) << endl;
                return false;
            }
        }
        return true;
    }

  } // chapter9
} // epi
