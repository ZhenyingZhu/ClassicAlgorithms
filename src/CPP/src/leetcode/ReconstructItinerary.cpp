/*
 * [Source] https://leetcode.com/problems/reconstruct-itinerary/
 * [Difficulty]: Medium
 * [Tag]: Depth-first Search
 * [Tag]: Graph
 */

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// [Solution]: https://en.wikipedia.org/wiki/Eulerian_path
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for (pair<string, string> &edge : tickets) {
            graph[edge.first].push(edge.second);
        }

        vector<string> res;
        dfs("JFK", graph, res);
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(string node, unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &graph, vector<string> &res) {
        while (!graph[node].empty()) {
            string neighbor = graph[node].top();
            graph[node].pop();
            dfs(neighbor, graph, res);
        }
        res.push_back(node);
    }
};

// [Solution]: Use dfs. Need to notice need to visit all pathes, so can reach a node more than twice, but every path only once.
// [Corner Case]:
class SolutionSelf {
public:
    struct VecWithIter {
        VecWithIter() {}
        bool allVisited() const {
            for (const bool &b : visited)
                if (!b)
                    return false;
            return true;
        }

        vector<string> vec;
        vector<bool> visited;
    };

    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, VecWithIter> graph;
        int edgeNums = 0;
        for (pair<string, string> &edge : tickets) {
            graph[edge.first].vec.push_back(edge.second);
            ++edgeNums;
        }

        for (auto it = graph.begin(); it != graph.end(); ++it) {
            vector<string> &vec = it->second.vec;
            sort(vec.begin(), vec.end());
            it->second.visited.resize(vec.size(), false);
        }

        /* Test
        for (auto it = graph.begin(); it != graph.end(); ++it) {
            vector<string> &vec = it->second.vec;
            cout << it->first << ":";
            for (string& tt : vec)
                cout << tt << " ";
            cout << endl;
        }
        */

        vector<string> path = {"JFK"};
        dfs(graph, "JFK", path, 0, edgeNums);
        return path;
    }

    bool dfs(unordered_map<string, VecWithIter> &graph, string cur, vector<string> &path, int visited, int total) {
        auto it = graph.find(cur);
        if (it == graph.end() || it->second.allVisited()) {
            return visited == total;
        }

        VecWithIter &node = it->second;
        for (int i = 0; i < (int)node.vec.size(); ++i) {
            if (node.visited[i])
                continue;

            string &next = node.vec[i];
            node.visited[i] = true;
            path.push_back(next);
            if ( dfs(graph, next, path, visited + 1, total) ) // true means find the path, so don't modify it again
                return true;
            path.pop_back();
            node.visited[i] = false;
        }

        return false; // cannot find a path
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<pair<string, string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    //vector<pair<string, string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<pair<string, string>> tickets = {{"JFK", "AAA"}, {"JFK", "BBB"}, {"BBB", "JFK"}, {"BBB", "AAA"}, {"AAA", "BBB"}};

    vector<string> res = sol.findItinerary(tickets);
    for (string &str : res)
        cout << str << " ";
    cout << endl;

    return 0;
}
