/*
 * [Source] https://leetcode.com/problems/alien-dictionary/
 * [Difficulty]: Hard
 * [Tag]: Graph
 * [Tag]: Topological Sort
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// [Solution]: Use recursive call to group strings with same prefix together, and compare char at pos. Then topological sort
// [Corner Case]: Fill the less length string with a * at pos
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        helper(words, 0, words.size() - 1, 0, graph);

/*
for (auto it = graph.begin(); it != graph.end(); ++it) {
cout << "key " << it->first << " Neighbor ";
for (auto iter = it->second.begin(); iter != it->second.end(); ++iter) cout << *iter << " "; cout << endl;
}
*/
        unordered_map<int, vector<char>> charSet = topologicalSort(graph);

        vector<char> res;
        int level = 0;
        while (charSet.count(level)) {
            for (char &c : charSet[level]) {
                if (c != '*')
                    res.push_back(c);
            }
            ++level;
        }
        return string(res.begin(), res.end());
    }

    void helper(vector<string> &words, int stIdx, int edIdx, int pos, unordered_map<char, unordered_set<char>> &graph) {
cout << "st " << stIdx << " ed " << edIdx << " pos " << pos << endl;
        int maxLen = 0;
        for (int i = stIdx; i <= edIdx; ++i)
            maxLen = max((int)words[i].length(), maxLen);
        if (maxLen <= pos)
            return;

        char prev = '*';
        int newStIdx = stIdx;
        for (int i = stIdx; i <= edIdx; ++i) {
            char cur = '*';
            if ((int)words[i].length() > pos) // fill string that is not enough length with *
                cur = words[i][pos];

            if (cur != prev) {
                graph[cur].insert(prev); // cur > prev
cout << "cur " << cur << " prev " << prev << endl;
                helper(words, newStIdx, i - 1, pos + 1, graph);
                prev = cur;
                newStIdx = i;
            }
        }
        helper(words, newStIdx, edIdx, pos + 1, graph);
    }

    unordered_map<int, vector<char>> topologicalSort(unordered_map<char, unordered_set<char>> &graph) {
        unordered_map<int, vector<char>> levelCharsetMap;
        unordered_map<char, int> charLevelMap;
        bool cycleDetected = false;
        for (auto it = graph.begin(); it != graph.end(); ++it) {
            unordered_set<char> visiting;
            dfs(it->first, graph, visiting, levelCharsetMap, charLevelMap, cycleDetected);
        }
        return levelCharsetMap;
    }

    int dfs(char cur, unordered_map<char, unordered_set<char>> &graph, unordered_set<char> &visiting,
            unordered_map<int, vector<char>> &levelCharsetMap, unordered_map<char, int> &charLevelMap,
            bool &cycleDetected) {
cout << "dfs " << cur << endl;
        if (cycleDetected)
            return -1;
        // detect cycle
        if (visiting.count(cur) > 0) {
cout << "cycle detect " << cur << endl;
            cycleDetected = true;
            levelCharsetMap.clear();
            return -1;
        }

        // visted in another cycle
        if (charLevelMap.count(cur))
            return charLevelMap[cur];

        // the smallest cur,  could be *, but could be else
        if (graph.find(cur) == graph.end() || graph[cur].empty()) {
            levelCharsetMap[0].push_back(cur);
            charLevelMap[cur] = 0;
            return 0;
        }

        visiting.insert(cur);
        unordered_set<char> &neighbors = graph[cur];
        int maxChildLevel = 0;
        for (auto neighborIt = neighbors.begin(); neighborIt != neighbors.end(); ++neighborIt) {
            int level = dfs(*neighborIt, graph, visiting, levelCharsetMap, charLevelMap, cycleDetected);
            maxChildLevel = max(maxChildLevel, level);
        }
        visiting.erase(cur);
        levelCharsetMap[maxChildLevel + 1].push_back(cur);
        charLevelMap[cur] = maxChildLevel + 1;
        return maxChildLevel + 1;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    /*
    vector<string> dict = {
      "wrt",
      "wrf",
      "er",
      "ett",
      "rftt"
    };
    */

   //vector<string> dict = {"z"};
   vector<string> dict = {"a", "b", "ca", "cc"};

    cout << sol.alienOrder(dict) << endl;

    return 0;
}
