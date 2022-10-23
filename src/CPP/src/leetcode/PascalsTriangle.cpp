/*
 * [Source] https://leetcode.com/problems/pascals-triangle/
 * [Difficulty]: Easy
 * [Tag]: Array
 */

#include <iostream>

using namespace std;

// [Solution]: Do it recursively
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/PascalsTriangleAll.java
 */

// [Solution]: Use two rolling arrays to save memory(actually not)
/* Java solution
public class Solution {
    public List<List<Integer>> generate(int numRows) {
        numRows=numRows-1; // Well, I get this wrong at the first time
		List<List<Integer>> result=new ArrayList<List<Integer>>();
		if(numRows<0){
			return result;
		}
		List<Integer> firstLine=new ArrayList<Integer>();
		firstLine.add(1);
		result.add(firstLine);
		if(numRows==0){
			return result;
		}
		List<Integer> secondLine=new ArrayList<Integer>();
		secondLine.add(1); secondLine.add(1); 
		result.add(secondLine);
		if(numRows==1){
			return result;
		}
		getRow(numRows, secondLine, result);
		return result;
	}
	
	public void getRow(int rowIndex, List<Integer> prev, List<List<Integer>> result){
		List<Integer> current=new ArrayList<Integer>();
		current.add(1);
		for(int i=1; i<prev.size(); i++){
			current.add(prev.get(i)+prev.get(i-1));
		}
		current.add(1);
		result.add(current);
		if(prev.size()==rowIndex) return;
		else getRow(rowIndex, current, result);
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
