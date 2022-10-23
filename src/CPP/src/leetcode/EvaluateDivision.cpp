/*
 * [Source] https://leetcode.com/problems/evaluate-division/
 * [Difficulty]: Medium
 * [Tag]: Graph
 */

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>

using namespace std;

// [Solution]: Floyd–Warshall algorithm
// [Corner Case]:
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < (int)equations.size(); ++i) {
            string &dividend = equations[i].first, &divisor = equations[i].second;
            double &quotient = values[i];

            graph[dividend][divisor] = quotient;
            graph[divisor][dividend] = 1.0 / quotient;
        }

for (auto it = graph.begin(); it != graph.end(); ++it) {
    cout << it->first << ": ";
    for (auto i = it->second.begin(); i != it->second.end(); ++i) {
        cout << i->first << "=" << i->second << " ";
    }
    cout << endl;
}

        updateGraph(graph);

for (auto it = graph.begin(); it != graph.end(); ++it) {
    cout << it->first << ": ";
    for (auto i = it->second.begin(); i != it->second.end(); ++i) {
        cout << i->first << "=" << i->second << " ";
    }
    cout << endl;
}

        vector<double> res;
        for (pair<string, string> &query : queries) {
            string &dividend = query.first, &divisor = query.second;
            if (graph.find(dividend) == graph.end() || graph[dividend].find(divisor) == graph[dividend].end()) {
                res.push_back(-1.0);
            } else {
                res.push_back(graph[dividend][divisor]);
            }
        }
        return res;
    }

    void updateGraph(unordered_map<string, unordered_map<string, double>> &graph) {
        // why str/str=1 is computed is because str/tmp * tmp/str
        for (auto verticalIt = graph.begin(); verticalIt != graph.end(); ++verticalIt) {
            string vertical = verticalIt->first;
            for (auto stIt = graph.begin(); stIt != graph.end(); ++stIt) {
                string st = stIt->first;
                for (auto edIt = graph.begin(); edIt != graph.end(); ++edIt) {
                    string ed = edIt->first;
                    // already computed. since there is no contradiction, there won't be a shorter path
                    if (graph[st].find(ed) != graph[st].end())
                        continue;

                    // not able to compute at this time
                    if (graph[st].find(vertical) == graph[st].end())
                        continue;
                    if (graph[vertical].find(ed) == graph[vertical].end())
                        continue;

                    graph[st][ed] = graph[st][vertical] * graph[vertical][ed];
                }
            }
        }
    }
};

// [Solution]: Union find
/* Java solution

 */

int main() {
    Solution sol;

    vector<pair<string, string>> equations = { {"a", "b"}, {"b", "c"} };
    vector<double> values = {2.0, 3.0};
    vector<pair<string, string>> queries = { {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"} };

    vector<double> res = sol.calcEquation(equations, values, queries);
    for (double &d : res)
        cout << d << " ";
    cout << endl;

    return 0;
}
