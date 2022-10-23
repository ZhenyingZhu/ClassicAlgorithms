#include "FindStudentWithHighestBestOfThreeScores.hpp"

#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <functional>
#include <iostream>
#include <stdexcept>
#include "../../MyUtils.h"

using std::unordered_map;
using std::string;
using std::vector;
using std::max;
using std::ifstream;
using std::priority_queue;
using std::greater;
using std::runtime_error;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter13 {
    string FindStudentWithHighestBestOfThreeScores::findStudentWithHighestBestOfThreeScores(ifstream *ifs) {
        const size_t SCORE_NUM = 3;
        unordered_map< string, priority_queue<int, vector<int>, greater<int>> > studentThreeScores;

        string id;
        int score;
        while (*ifs >> id >> score) {
            if (studentThreeScores[id].size() == SCORE_NUM)
                studentThreeScores[id].pop();

            studentThreeScores[id].push(score);
        }

        string bestStudentId = "not found";
        int highestScoreSum = -1;
        for (auto &pair : studentThreeScores) {
            if (pair.second.size() < SCORE_NUM)
                continue;

            priority_queue<int, vector<int>, greater<int>> &queue = pair.second;
            int scoreSum = 0;
            while (!queue.empty()) {
                scoreSum += queue.top();
                queue.pop();
            }

            if (scoreSum > highestScoreSum) {
                highestScoreSum = scoreSum;
                bestStudentId = pair.first;
            }
        }

        return bestStudentId;
    }

    bool FindStudentWithHighestBestOfThreeScores::test() {
        ifstream ifs("resources/StudentScores");
        string res = findStudentWithHighestBestOfThreeScores(&ifs);
        if (res != "001") {
            cout << "Should be 001" << endl;
            cout << "Result " << res << endl;
            return false;
        }

        return true;
    }

  } // chapter13
} // epi
