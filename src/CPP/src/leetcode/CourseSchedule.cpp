/*
 * [Source] https://leetcode.com/problems/course-schedule/
 * [Difficulty]: Medium
 * [Tag]: Depth-first Search
 * [Tag]: Breadth-first Search
 * [Tag]: Graph
 * [Tag]: Topological Sort
 */

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>

using namespace std;

// [Solution]: Abstract the question into single direction graph. Use DFS to detect cycle. Notice not like doubly direction graph, need backtracking the path
// [Corner Case]:
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses <= 1 || prerequisites.empty())
            return true;

        unordered_map<int, vector<int>> graph;
        for (pair<int, int> &edge : prerequisites) {
            graph[edge.first].push_back(edge.second);
        }

        unordered_set<int> visited, visiting;
        for (auto it = graph.begin(); it != graph.end(); ++it) {
            if (visited.count(it->first))
                continue;
            if (hasCycle(it->first, graph, visiting, visited))
                return false;
        }
        return true;
    }

    bool hasCycle(int node, unordered_map<int, vector<int>> &graph, unordered_set<int> &visiting, unordered_set<int> &visited) {
        if (visiting.count(node))
            return true;

        visiting.insert(node);
        for (int &neighbor : graph[node]) {
            if (hasCycle(neighbor, graph, visiting, visited))
                return true;
        }
        visiting.erase(node);
        visited.insert(node);
        return false;
    }
};

class SolutionChaos {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0)
            return true;

        unordered_map<int, unordered_set<int>> graph;
        for (const pair<int, int>& p : prerequisites) {
            graph[p.first].insert(p.second);
        }

        unordered_set<int> visited;
        for (unordered_map<int, unordered_set<int>>::iterator it = graph.begin(); it != graph.end(); ++it) {
            int node = it->first;
            if (visited.find(node) != visited.end()) {
                continue; // visited
            }

            vector<int> path;
            if (hasCycle(node, graph, path, visited))
                return false;
        }

        return true;
    }

private:
    bool hasCycle(int node, unordered_map<int, unordered_set<int>>& graph, vector<int>& path, unordered_set<int>& visited) {
        if (find(path.begin(), path.end(), node) != path.end()) {
            return true;
        }
        visited.insert(node);
        path.push_back(node);
        
        for (const int& neighbor : graph[node]) {
            if (hasCycle(neighbor, graph, path, visited))
                return true;
        }
        path.pop_back();
        return false;
    }
};

// [Solution]:

int main() {
    Solution sol;

    vector<pair<int, int>> pre = {{0, 1}, {1, 0}};
    //vector<pair<int, int>> pre = {{0, 1}};
    //vector<pair<int, int>> pre = {{1, 0}, {2, 0}};
    //vector<pair<int, int>> pre = {{1,0},{2,6},{1,7},{6,4},{7,0},{0,5}};
    cout << (sol.canFinish(8, pre)?"True":"False") << endl;

    return 0;
}
