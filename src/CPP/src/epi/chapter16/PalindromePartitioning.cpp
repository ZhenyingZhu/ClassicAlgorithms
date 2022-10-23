#include "PalindromePartitioning.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <cassert>

using std::vector;
using std::string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter16 {
    bool PalindromePartitioning::isPalindrome(const string &prefix) {
        size_t st = 0, ed = prefix.size() - 1;
        while (ed > st) {
            if (prefix[st++] != prefix[ed--])
                return false;
        }
        return true;
    }

    void PalindromePartitioning::partitioningHelper(const string &input, size_t offset,
            vector<std::string> &partitions, vector<vector<string>> &result) {
        if (offset == input.size()) {
            result.push_back(partitions);
            return;
        }

        for (size_t i = offset + 1; i <= input.size(); ++i) {
            string prefix = input.substr(offset, i - offset);
            if (isPalindrome(prefix)) {
                partitions.push_back(prefix);
                partitioningHelper(input, i, partitions, result);
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> PalindromePartitioning::palindromePartitioning(const string &input) {
        vector<vector<string>> res;
        vector<string> partitions;
        partitioningHelper(input, 0, partitions, res);

        return res;
    }

    bool PalindromePartitioning::test() {
        string input("0204451881");
        vector<vector<string>> res = palindromePartitioning(input);

        if (res.size() != 12) {
            cout << "Wrong number of results: " << res.size() << endl;
            for (vector<string> vec : res) {
                for (string str : vec) {
                    cout << string(str) << ", ";
                }
                cout << endl;
            }

            return false;
        }

        return true;
    }

  } // chapter16
} // epi
