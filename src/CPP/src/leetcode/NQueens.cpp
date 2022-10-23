/*
 * [Source] https://leetcode.com/problems/n-queens/
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

    vector<string> generateRes(const vector<int>& rows, const int n) {
        vector<string> res;
        for (const int& i : rows) {
            string row(n, '.');
            row[i] = 'Q';
            res.push_back(row);
        }
        return res;
    }

    void nQueensHelper(int row, const int n,  vector<int>& prevRows, vector<vector<string>>& reses) {
        if (row == n) {
            reses.push_back(generateRes(prevRows, n));
            return;
        }

        vector<bool> availableSlots = computeValidSlots(prevRows, row, n);
        for (int i = 0; i < n; ++i) {
            if (!availableSlots[i])
                continue;
            prevRows.push_back(i);
            nQueensHelper(row + 1, n, prevRows, reses);
            prevRows.pop_back();
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> reses;
        if (n <= 0)
            return reses;
        vector<int> prevRows;
        nQueensHelper(0, n, prevRows, reses);
        return reses;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/N-QueensSolution.java
 */

/* Java solution
public class Solution {
    public List<String[]> solveNQueens(int n) {
        List<String[]> result=new ArrayList<String[]>();
		if(n<=0) return result;
		int[] positions=new int[n];
		solveNQueens(positions, 0, result);
		return result;
    }
	
	public void solveNQueens(int[] positions, int idx, List<String[]> result){
		if(idx==positions.length){
			String[] solution=createStringList(positions);
			result.add(solution);
		}
		int[] col=new int[positions.length];
		for(int i=0; i<idx; i++){
			int vertical=positions[i];
			col[vertical]=-1;
			int offset=idx-i;
			if((vertical-offset)>=0) col[vertical-offset]=-1;
			if((vertical+offset)<col.length) col[vertical+offset]=-1;
		}
		for(int i=0; i<col.length; i++){
			if(col[i]!=-1){
				int[] prev=copy(positions, idx);
				prev[idx]=i;
				solveNQueens(prev, idx+1, result);
			}
		}
	}
	
	public int[] copy(int[] array, int idx){
		int[] result=new int[array.length];
		for(int i=0; i<idx; i++){
			result[i]=array[i];
		}
		return result;
	}
	
	public String[] createStringList(int[] positions){
		String[] result=new String[positions.length];
		for(int i=0; i<positions.length; i++){
			int pos=positions[i];
			StringBuffer row=new StringBuffer();
			for(int j=0; j<positions.length; j++){
				if(j!=pos) row.append('.');
				else row.append('Q');
			}
			result[i]=row.toString();
		}
		return result;
    }
}
 */

int main() {
    Solution sol;

    vector<vector<string>> res = sol.solveNQueens(4);
    for (const vector<string>& v : res) {
        for (const string& s : v)
            cout << s << endl;
        cout << endl;
    }

    return 0;
}
