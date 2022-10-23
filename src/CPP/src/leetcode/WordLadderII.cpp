/*
 * [Source] https://leetcode.com/problems/word-ladder-ii/
 * [Difficulty]: Hard
 * [Tag]: Array
 * [Tag]: Backtracking
 * [Tag]: Breadth-first Search
 * [Tag]: String
 */

#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

// [Solution]: Treat it as graph. Use BFS to find the shortest pathes. Two special cases. 1. to avoid find longer path, use level order traverse; 2. to deal with two pathes hit same node on the path, tag nodes as visited after the whole current level visited, not in between. Use linked list to retrive result
// [Corner Case]: 
class Solution {
private:
    struct GraphNode {
        GraphNode(string s, GraphNode *p): str(s), pre(p) { }
        string str;
        GraphNode *pre;
    };

    vector<GraphNode*> getNeighbors(GraphNode *cur, const unordered_set<string> &wordList) {
        string s = cur->str;
        vector<GraphNode*> neighbors;
        for (size_t i = 0; i < s.length(); ++i) {
            char ori = s[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == ori)
                    continue;
                s[i] = c;
                if (wordList.find(s) != wordList.end()) {
                    neighbors.push_back(new GraphNode(s, cur));
                }
            }
            s[i] = ori;
        }
        return neighbors;
    }

    vector<string> getPath(GraphNode *end) {
        vector<string> path;
        GraphNode *cur = end;
        while (cur != NULL) {
            path.push_back(cur->str);
            cur = cur->pre;
        }
        reverse(path.begin(), path.end());
        return path;
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        wordList.erase(beginWord);
        wordList.insert(endWord);

        GraphNode begin(beginWord, NULL);
        queue<GraphNode*> q;
        q.push(&begin);
        int size = 1;

        vector<vector<string>> res;
        while (!q.empty()) {
            unordered_set<string> visitedStr;
            for (int i = 0; i < size; ++i) {
                GraphNode *top = q.front();
                q.pop();

                for (GraphNode *&neighbor : getNeighbors(top, wordList)) {
//cout << neighbor->str << " <-" << neighbor->pre->str << endl;
                    if (neighbor->str == endWord) {
                        res.push_back(getPath(neighbor));
                        continue;
                    }

                    q.push(neighbor);
                    visitedStr.insert(neighbor->str);
                }
            }

            if (res.size() > 0)
                break;
            size = q.size();
            for (const string &s : visitedStr) {
                wordList.erase(s);
            }
        }

        return res;
    }
};

// [Solution]: Use hash table maintain parents
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/WordLadderPaths.java
 */

/* Java solution
public class Solution {
    public List<List<String>> findLadders(String start, String end, Set<String> dict) {
		if(start==null || end==null) return null;
		List<List<String>> res=new ArrayList<List<String>>();
		List<String> oneResult=new ArrayList<String>();
		if(start.equals(end)){
			oneResult.add(start);
			oneResult.add(end);
			res.add(oneResult);
			return res;
		}
		HashMap<String, ArrayList<String>> map=new HashMap<String, ArrayList<String>>();
		dict.add(start);
		dict.add(end);
		for(String s: dict){
			map.put(s, new ArrayList<String>());
		}
		Queue<String> queue=new LinkedList<String>();
		queue.offer(start);
		while(!queue.isEmpty()){
			int levelAmount=queue.size();
			ArrayList<String> levelNodes=new ArrayList<String>();
			for(int i=0; i<levelAmount; i++){
				String onLevelNode=queue.poll();
				levelNodes.add(onLevelNode);
				dict.remove(onLevelNode); // Not even avoid cycle, but also avoid longer path. 
			}
			for(String node: levelNodes){
				for(int i=0; i<node.length(); i++){
					char[] changeOneWord=node.toCharArray();
					for(char c='a'; c<='z'; c++){
						if(changeOneWord[i]==c) continue;
						changeOneWord[i]=c;
						String intermediate=new String(changeOneWord);
						if(dict.contains(intermediate)){
							if(!queue.contains(intermediate)) queue.offer(intermediate); 
							map.get(intermediate).add(node);
						}
					}
				}
			}
			if(queue.contains(end)) break;
		}
		List<String> prev=new ArrayList<String>();
		prev.add(end);
		constructAns(start, end, prev, map, res);
		return res;
    }
	public void constructAns(String start, String cur, List<String> prev, HashMap<String, ArrayList<String>> map, List<List<String>> res){
		if(cur.equals(start)){
			Collections.reverse(prev);
			res.add(prev);
			return;
		}
		ArrayList<String> onLevelNodes=map.get(cur);
		for(String node: onLevelNodes){
			List<String> onePath=new ArrayList<String>(prev);
			onePath.add(node);
			constructAns(start, node, onePath, map, res);
		}
    }
}
 */

int main() {
    Solution sol;

   /* 
    unordered_set<string> wordList = {"hot","dot","dog","lot","log"};
    vector<vector<string>> res = sol.findLadders("hit", "cog", wordList);
    */
    /*
    unordered_set<string> wordList = {"a","b","c"};
    vector<vector<string>> res = sol.findLadders("a", "c", wordList);
    */
    unordered_set<string> wordList = {"ted","tex","red","tax","tad","den","rex","pee"};
    vector<vector<string>> res = sol.findLadders("red", "tax", wordList);
    for (vector<string> &vec : res) {
        for (string &s : vec) {
            cout << s << ",";
        }
        cout << endl;
    }

    return 0;
}
