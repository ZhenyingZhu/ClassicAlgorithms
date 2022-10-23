/*
 * [Source] https://leetcode.com/problems/maximal-rectangle/
 * [Difficulty]: Hard
 * [Tag]: Array
 * [Tag]: Hash Table
 * [Tag]: Stack
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <functional>
#include <climits>
#include <string>

using namespace std;

// [Solution]: Reduce number of dimisions. First compute height of each cell, then from previous cells, use the min height multiple width to get the area.
// [Corner Case]:
class Solution {
private:
    int findMaxArea(const vector<vector<int>>& upHeight, int i, int j) {
        int h = INT_MAX, maxArea = 0;
        for (int k = j; k >= 0; --k) {
            if (upHeight[i][k] == 0)
                break;
            h = min(upHeight[i][k], h);
            maxArea = max(h * (j - k + 1), maxArea);
        }
        //cout << "(" << i << "," << j << "): " << maxArea << endl;
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;

        int height = matrix.size(), width = matrix[0].size();
        vector<vector<int>> upHeight(height, vector<int>(width, -1));

        int maxReg = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (i == 0) {
                    upHeight[i][j] = matrix[i][j] == '1' ? 1 : 0;
                } else {
                    upHeight[i][j] = matrix[i][j] == '1' ? upHeight[i - 1][j] + 1 : 0;
                }
                maxReg = max(findMaxArea(upHeight, i, j), maxReg);
            }
        }

        return maxReg;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/MaximalRectangle.java
 */

/* Java solution
public class Solution {
    public int maximalRectangle(char[][] matrix) {
        int l=matrix.length;
		if(l==0) return 0;
		int w=matrix[0].length;
		if(w==0) return 0;
		int max=0;
		int[][] length=new int[l][w];
		for(int i=0; i<l; i++){
			int cnt=0;
			for(int j=0; j<w; j++){
				if(matrix[i][j]=='0'){
					cnt=0;
				}else{
					cnt++;
				}
				length[i][j]=cnt;
			}
		}
		for(int i=0; i<l;i++){
			for(int j=0; j<w; j++){
				if(length[i][j]!=0){
					int h=1; // This line first;
					int width=length[i][j];
					while(i+1-h>=0){ // The index
						if(length[i-h+1][j]==0) break;
						width=Math.min(width, length[i-h+1][j]);
						max=Math.max(max, h*width);
						h++;
					}
				}
			}
		}
		return max;
    }
}
 */

int main() {
    Solution sol;

    vector<string> strs = {
        "10100",
        "10111",
        "11111",
        "10010"
    };
    vector<vector<char>> matrix;
    for (const string& s : strs) {
        matrix.push_back(vector<char>(s.begin(), s.end()));
    }

    cout << sol.maximalRectangle(matrix) << endl;

    return 0;
}
