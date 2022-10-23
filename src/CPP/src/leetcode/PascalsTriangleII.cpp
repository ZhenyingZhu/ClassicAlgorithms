/*
 * [Source] https://leetcode.com/problems/pascals-triangle-ii/
 * [Difficulty]: Easy
 * [Tag]: Array
 */

#include <iostream>

using namespace std;

// [Solution]: Use C(n,i) to compute
// [Corner Case]:
class Solution {
};

// [Solution]: Use rolling arrays to save memory
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/PascalsTriangleRow.java
 */

/* Java solution
public class Solution {
    public List<Integer> getRow(int rowIndex) {
		List<Integer> firstLine=new ArrayList<Integer>();
		if(rowIndex<0) return firstLine;
		List<Integer> secondLine=new ArrayList<Integer>();
		firstLine.add(1);
		if(rowIndex==0) return firstLine;
		secondLine.add(1); secondLine.add(1); 
		if(rowIndex==1) return secondLine;
		List<Integer> result=getRow(rowIndex, secondLine, firstLine);
		return result;
	}
	
	public List<Integer> getRow(int rowIndex, List<Integer> prev, List<Integer> result){
		for(int i=1; i<result.size(); i++){
			result.set(i, prev.get(i-1)+prev.get(i));
		}
		result.add(prev.get(prev.size()-2)+prev.get(prev.size()-1));
		result.add(1);
		if(prev.size()==rowIndex) return result;
		else return getRow(rowIndex, result, prev);
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
