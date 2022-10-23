/*
 * [Source] https://leetcode.com/problems/simplify-path/
 * [Difficulty]: Medium
 * [Tag]: Stack
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: Split string by '/'. Use a stack. If find "..", pop, if "." or empty, do nothing.
// [Corner Case]: only "/", then stack is empty.
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/datastructure/SimplifyPath.java
 */

/* Java solution
public class Solution {
    public String simplifyPath(String path) {
		if(path==null || path.length()<=0) return null;
		if(path.equals("/")) return "/";
		char[] array=path.toCharArray();
        Stack<String> stack=new Stack<String>();
		int idx=1;
		while(idx<array.length){
			if(array[idx]=='/'){ // a slash
				idx++;
				continue;
			}
			String dir=getDirectory(array, idx);
			if(!dir.equals(".")){ // current dir
				if(dir.equals("..")){ // parent dir
					if(!stack.empty()) stack.pop();
				}else{
					stack.push(dir);
				}
				idx=idx+dir.length()+1;
			}else{
				idx=idx+2;
			}
		}
		if(stack.empty()) return "/";
		Stack<String> reverse=new Stack<String>();
		while(!stack.empty()){
			reverse.push(stack.pop());
		}
		StringBuffer result=new StringBuffer();
		while(!reverse.empty()){
			result.append('/');
			result.append(reverse.pop());
		}
		return result.toString();
    }
	
	public String getDirectory(char[] path, int start){
		StringBuffer directory=new StringBuffer();
		int index=start;
		while(index<path.length){
			if(path[index]=='/') break;
			directory.append(path[index]);
			index++;
		}
		return directory.toString();
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
