#include "FindAllSubstrings.hpp"

#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "../../MyUtils.h"

using std::unordered_map;
using std::string;
using std::vector;
using std::invalid_argument;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter13 {
    bool FindAllSubstrings::checkSubstring(const string &s, unordered_map<string, size_t> &wordFreq,
                                           size_t start, size_t wordLen, size_t wordNum) {
        unordered_map<string, size_t> wordShows;

        for (size_t i = 0; i != wordNum; ++i) {
            size_t st = start + i * wordLen;
            string cur = s.substr(st, wordLen);

            auto iter = wordFreq.find(cur);
            if (iter == wordFreq.end())
                return false;

            ++wordShows[cur];
            if (wordShows[cur] > wordFreq[cur])
                return false;
        }

        return true;
    }

    vector<size_t> FindAllSubstrings::findAllSubstrings(const std::string &s, const std::vector<std::string> &words) {
        if (words.empty() || words[0].size() == 0)
            throw invalid_argument("Empty word list or empty string");

        unordered_map<string, size_t> wordFreq;
        for (string word : words) {
            ++wordFreq[word];
        }

        size_t wordLen = words[0].size(), wordNum = words.size();

        vector<size_t> res;
        for (size_t i = 0; i + wordLen * wordNum <= s.size(); ++i) {
            if ( checkSubstring(s, wordFreq, i, wordLen, wordNum) )
                res.push_back(i);
        }

        return res;
    }

    bool FindAllSubstrings::test() {
        string sentence("amanaplanacanal");
        vector<string> words = {"can","apl", "ana"};

        vector<size_t> ans = {4};
        vector<size_t> res = findAllSubstrings(sentence, words);

        if (res != ans) {
            cout << "Should be " << vec_to_string(ans) << endl;
            cout << "Result " << vec_to_string(res) << endl;
            return false;
        }

        return true;
    }

  } // chapter13
} // epi
