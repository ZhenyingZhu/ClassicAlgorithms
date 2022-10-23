#include "IsWellFormed.hpp"

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

    bool IsWellFormed::isWellFormed(const string &s) {
        stack<char> leftParts;

        for (char c : s) {
            switch (c) {
            case '(':
                leftParts.push(c);
                break;
            case '[':
                leftParts.push(c);
                break;
            case '{':
                leftParts.push(c);
                break;
            case ')':
                if (leftParts.empty() || leftParts.top() != '(')
                    return false;
                leftParts.pop();
                break;
            case ']':
                if (leftParts.empty() || leftParts.top() != '[')
                    return false;
                leftParts.pop();
                break;
            case '}':
                if (leftParts.empty() || leftParts.top() != '{')
                    return false;
                leftParts.pop();
                break;
            default:
                throw invalid_argument("Unrecognized brace.");
            }
        }

        if ( !leftParts.empty() )
            return false;

        return true;
    }

    bool IsWellFormed::test() {
        string s1 = "[()[]{()()}]";
        string s2 = "[()[]{()()";
        string s3 = ")[]";
        string s4 = "[](";

        if (!isWellFormed(s1)) {
            cout << "Should be true: " << s1 << endl;
            return false;
        }

        if (isWellFormed(s2)) {
            cout << "Should be false: " << s2 << endl;
            return false;
        }

        if (isWellFormed(s3)) {
            cout << "Should be false: " << s3 << endl;
            return false;
        }

        if (isWellFormed(s4)) {
            cout << "Should be false: " << s4 << endl;
            return false;
        }

        return true;
    }

  } // chapter9
} // epi
