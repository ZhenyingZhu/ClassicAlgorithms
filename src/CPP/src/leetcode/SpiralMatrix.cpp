/*
 * [Source] https://leetcode.com/problems/spiral-matrix/
 * [Difficulty]: Medium
 * [Tag]: Array
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Use two pointers for row, and two points for col
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty())
            return res;

        int rowSt = 0, rowEd = matrix.size() - 1, colSt = 0, colEd = matrix[0].size() - 1;
        while (rowSt <= rowEd && colSt <= colEd) {
            for (int i = colSt; i <= colEd; i++)
                res.push_back(matrix[rowSt][i]);
            rowSt++;

            for (int j = rowSt; j <= rowEd; j++)
                res.push_back(matrix[j][colEd]);
            colEd--;

            if (rowSt <= rowEd) {
                for (int i = colEd; i >= colSt; i--)
                    res.push_back(matrix[rowEd][i]);
                rowEd--;
            }

            if (colSt <= colEd) {
                for (int j = rowEd; j >= rowSt; j--)
                    res.push_back(matrix[j][colSt]);
                colSt++;
            }
        }
        return res;
    }
};

// [Solution]: Mark the visited cells. If touch a marked cell or board, turn right. Use a direction vector to indicate which direction.

/* Java solution
public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
		List<Integer> result=new ArrayList<Integer>();
        if(matrix==null || matrix.length<=0 || matrix[0].length<=0) return result;
		int m=matrix.length;
		int n=matrix[0].length;
		int total=m*n;
		int[] xDir={0, 1, 0, -1};
		int[] yDir={1, 0, -1, 0};
		int pt=0;
		int i=0;
		int x=0; 
		int y=-1;
		while(i<total){
			for(int a=0; a<n; a++){
				x+=xDir[pt];
				y+=yDir[pt];
				result.add(matrix[x][y]);
				i++;
			}
			pt++;
			if(pt==4) pt=0;
			n--;
			m--;
			for(int b=0; b<m; b++){
				x+=xDir[pt];
				y+=yDir[pt];
				result.add(matrix[x][y]);
				i++;
			}
			pt++;
			if(pt==4) pt=0;
		}
		return result;
    }
}
 */

// [Solution]: Use the ith row as offset. To avoid go back, need be careful about the middle.
// [Corner Case]: middle is a line. middle is a square. middle is a dot.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/SpiralMatrix.java
 */

// [Solution]: recursive call with left top and right end corrdinate.

int main() {
    Solution sol;

    //vector<vector<int>> matrix = {{1,2,3}};
    vector<vector<int>> matrix = {{1,2,3,4},{10,11,12,5},{9,8,7,6}};
    for (int &num : sol.spiralOrder(matrix))
        cout << num << ", ";
    cout << endl;

    return 0;
}
