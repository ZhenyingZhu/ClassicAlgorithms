#include "GetValidIPAddress.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::invalid_argument;

namespace epi {
  namespace chapter7 {
  bool GetValidIPAddress::isValidIPPart(const string &partialIP) {
      if (partialIP.size() >= 2 && partialIP[0] == '0')
          return false;

      int i = atoi (partialIP.c_str());
      if ( i > 255 )
          return false;

      return true;
  }

    void GetValidIPAddress::getValidIPAddressHelper(const string &s, size_t pos,
                                                    string partialStr, size_t part,
                                                    vector<string> &vec) {
        if (part == 4) {
            if (pos == s.size())
                vec.push_back(string(partialStr));
            return;
        }

        if ( s.size() - pos < 4 - part ) // Not enough numbers
            return;

        string addition = "";
        for (int i = 0; i != 3; ++i) {
            addition += s[pos + i];
            if (!isValidIPPart(addition))
                break;

            if (part == 3)
                getValidIPAddressHelper(s, pos + i + 1, partialStr + addition, part + 1, vec);
            else
                getValidIPAddressHelper(s, pos + i + 1, partialStr + addition + '.', part + 1, vec);
        }
    }

    vector<string> GetValidIPAddress::getValidIPAddress(const string &s) {
        if (s.size() < 4 || s.size() > 9)
            throw invalid_argument(s + " can not be a valid IP.");

        vector<string> vec;
        getValidIPAddressHelper(s, 0, "", 0, vec);

        return vec;
    }

    bool GetValidIPAddress::test() {
        string ip1("19216811");
        string ip2("009216");

        vector<string> tests = {ip1, ip2};

        for (string test : tests) {
            vector<string> res = getValidIPAddress(test);
            if (res.size() < 2) { // Too lazy to create a map
                for (string s : res)
                    cout << s << endl;

                return false;
            }
        }

        return true;
    }
  } // chapter7
} // epi
