/*
 * [Source] https://leetcode.com/problems/word-ladder/
 * [Difficulty]: Medium
 * [Tag]: String
 * [Tag]: Breadth-first Search
 */

#include <iostream>

using namespace std;

// [Solution]: Treat it as graph. Use BFS to find the shortest path.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/WordLadder.java
 */

/* Java solution
public class Solution {
    public int ladderLength(String start, String end, Set<String> dict) {
		if(start==null || end==null) return 0;
		if(start.equals(end)) return 2;
		HashMap<String, Integer> map=new HashMap<String, Integer>();
		Queue<String> queue=new LinkedList<String>();
		dict.remove(start);
		queue.offer(start);
		map.put(start, 1);
		while(!queue.isEmpty()){
			String node=queue.poll();
			for(int i=0; i<node.length(); i++){
				char[] changeOneWord=node.toCharArray();
				for(char c='a'; c<='z'; c++){
					if(changeOneWord[i]==c) continue;
					changeOneWord[i]=c;
					String intermediate=new String(changeOneWord);
					if(intermediate.equals(end)) return map.get(node)+1;
					if(dict.contains(intermediate)){
						if(!queue.contains(intermediate)){
							dict.remove(intermediate);
							int level=map.get(node)+1;
							map.put(intermediate, level);
							queue.offer(intermediate); 
						}
					}
				}
			}
		}
		if(!map.containsKey(end)) return 0;
		return map.get(end);
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
