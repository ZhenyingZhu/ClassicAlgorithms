/*
 * [Source] https://leetcode.com/problems/n-queens-ii/
 * [Difficulty]: Hard
 * [Tag]: Backtracking
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// [Solution]: Use a vector of int to indicate how previous queens locate. Then place queens to available positions.
// [Corner Case]:
class Solution {
private:
    vector<bool> computeValidSlots(const vector<int>& prevRows, const int curRow, const int n) {
        vector<bool> availableSlots(n, true);
        for (int preRow = 0; preRow < (int)prevRows.size(); ++preRow) {
            int pos = prevRows[preRow];
            availableSlots[pos] = false;
            int diff = curRow - preRow;
            if (pos - diff >= 0)
                availableSlots[pos - diff] = false;
            if (pos + diff < n)
                availableSlots[pos + diff] = false;
        }
        return availableSlots;
    }

    void nQueensHelper(int row, const int n,  vector<int>& prevRows, int& res) {
        if (row == n) {
            ++res;
            return;
        }

        vector<bool> availableSlots = computeValidSlots(prevRows, row, n);
        for (int i = 0; i < n; ++i) {
            if (!availableSlots[i])
                continue;
            prevRows.push_back(i);
            nQueensHelper(row + 1, n, prevRows, res);
            prevRows.pop_back();
        }
    }

public:
    int totalNQueens(int n) {
        int res = 0;
        if (n <= 0)
            return res;
        vector<int> prevRows;
        nQueensHelper(0, n, prevRows, res);
        return res;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/N-QueensWays.java
*/

/* Java solution
public class Solution {
    public int totalNQueens(int n) {
		if(n<=0) return 0;
		int[] positions=new int[n];
		int result=solveNQueens(positions, 0);
		return result;
    }
	
	public int solveNQueens(int[] positions, int idx){
		if(idx==positions.length){
			return 1;
		}
		int[] col=new int[positions.length];
		for(int i=0; i<idx; i++){
			int vertical=positions[i];
			col[vertical]=-1;
			int offset=idx-i;
			if((vertical-offset)>=0) col[vertical-offset]=-1;
			if((vertical+offset)<col.length) col[vertical+offset]=-1;
		}
		int sum=0;
		for(int i=0; i<col.length; i++){
			if(col[i]!=-1){
				int[] prev=copy(positions, idx);
				prev[idx]=i;
				sum+=solveNQueens(prev, idx+1);
			}
		}
		return sum;
	}
	
	public int[] copy(int[] array, int idx){
		int[] result=new int[array.length];
		for(int i=0; i<idx; i++){
			result[i]=array[i];
		}
		return result;
    }
}
 */

int main() {
    Solution sol;

    int res = sol.totalNQueens(4);
    cout << res << endl;

    return 0;
}
