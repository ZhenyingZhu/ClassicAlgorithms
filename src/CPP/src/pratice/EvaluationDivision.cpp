#include <iostream>
#include <utility>
#include <unordered_map>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/evaluate-division
// http://www.1point3acres.com/bbs/thread-225703-1-1.html

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double> &values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < (int)equations.size(); ++i) {
            string &a = equations[i].first, &b = equations[i].second;
            graph[a][b] = values[i];
            graph[b][a] = 1.0 / values[i];
        }

        for (auto midIt = graph.begin(); midIt != graph.end(); ++midIt) {
            string mid = midIt->first;
            for (auto stIt = graph.begin(); stIt != graph.end(); ++stIt) {
                string st = stIt->first;
                if (!graph[st].count(mid))
                    continue;

                for (auto edIt = graph.begin(); edIt != graph.end(); ++edIt) {
                    string ed = edIt->first;
                    if (st == ed) {
                        graph[st][ed] = 1.0;
                    } else if (graph[mid].count(ed)) {
                        graph[st][ed] = graph[st][mid] * graph[mid][ed];
                    }
                }
            }
        }

        vector<double> res;
        for (pair<string, string> &query : queries) {
            string &a = query.first, &b = query.second;
            if (graph.count(a) && graph[a].count(b))
                res.push_back(graph[a][b]);
            else
                res.push_back(-1.0);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<pair<string, string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0,3.0};
    vector<pair<string, string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};

    for (double &val : sol.calcEquation(equations, values, queries)) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
