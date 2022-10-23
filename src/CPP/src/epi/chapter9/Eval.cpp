#include "Eval.hpp"

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

    int Eval::eval(const string &rpnExpression) {
        stack<int> operants;
        stringstream ss(rpnExpression);
        string token;

        while ( getline(ss, token, ',') ) {
            if (token == "+" || token == "-" || token == "x" || token == "/") {
                int y = operants.top();
                operants.pop();
                int x = operants.top();
                operants.pop();

                switch ( token.front() ) {
                case '+':
                    operants.push(x + y);
                    break;
                case '-':
                    operants.push(x - y);
                    break;
                case 'x':
                    operants.push(x * y);
                    break;
                case '/':
                    operants.push(x / y);
                    break;
                default:
                    throw invalid_argument("Should not reach here.");
                }
            } else {
                int num = stoi(token);
                operants.push(num);
            }
        }

        return operants.top();
    }

    bool Eval::test() {
        string s = "3,4,+,2,x,1,+";

        int res = eval(s);
        if (res != 15) {
            cout << "Should be: 15" << endl;
            cout << "Result is: " << res << endl;
            return false;
        }

        return true;
    }

  } // chapter9
} // epi
