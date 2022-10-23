#include <iostream>

using namespace std;

// [Source]: https://leetcode.com/problems/valid-number/?tab=Description

// [Solution]: https://en.wikipedia.org/wiki/Deterministic_finite_automaton, https://mnmunknown.gitbooks.io/algorithm-notes/content/dfa_parse_integer.html

class Solution {
public:
    bool isNumber(string s) {
        s.erase(s.find_last_not_of(" \n\r\t") + 1);
cout << s << "'" << endl;
        if (s.empty())
            return false;
        s = s.substr(s.find_first_not_of(" \n\r\t"));
cout << s << "'" << endl;
        char state = 's';
        for (char &c : s) {
            state = transition(c, state);
            if (state == 'F')
                return false;
        }
        return (state != 's' && state != 'd' && state != 'e');
    }

    char transition(char &c, char prevState) {
        switch(prevState) {
            case 's': {
                          if (isdigit(c))
                              return 'N';
                          if (c == '+' || c == '-')
                              return 'S';
                          if (c == '.')
                              return 'd';
                          break;
                      }
            case 'S': {
                          if (isdigit(c))
                              return 'N';
                          if (c == '.')
                              return 'd';
                          break;
                      }
            case 'd': {
                          if (isdigit(c))
                              return 'D';
                          break;
                      }
            case 'N': {
                          if (isdigit(c))
                              return 'N';
                          if (c == '.')
                              return 'D';
                          if (c == 'e')
                              return 'e';
                          break;
                      }
            case 'D': {
                          if (isdigit(c))
                              return 'D';
                          if (c == 'e')
                              return 'e';
                          break;
                      }
            case 'e': {
                          if (isdigit(c))
                              return 'E';
                          if (c == '+' || c == '-')
                              return 'e';
                          break;
                      }
            case 'E': {
                          if (isdigit(c))
                              return 'E';
                          break;
                      }
            default: break;
        }
        return 'F';
    }
};

int main() {
    Solution sol;

    //cout << sol.isNumber("123") << endl;
    //cout << sol.isNumber("1.") << endl;
    //cout << sol.isNumber(".1") << endl;
    //cout << sol.isNumber("+.1") << endl;
    //cout << sol.isNumber("   +.1e-5   ") << endl;
    cout << sol.isNumber(" ") << endl;

    return 0;
}
