/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start

/*
Notes:
similar to backtracking, you can either pass in external variable's reference to modify;
or return the value directly. The latter involves less variable initialisations and is
marginally faster
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int maxArea = 0;
        for (int row = 0; row < grid.size(); row++){
            for (int col = 0; col < grid[0].size(); col++){
                if(!visited[row][col] && grid[row][col] == 1){
                    maxArea = max(maxArea, traverse(grid, row, col, visited));
                }
            }
        }
        return maxArea;
    }

    int traverse(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()){
            return 0;
        }

        if(visited[row][col]){
            return 0;
        }

        int area = 0;
        if(grid[row][col] == 1){
            area++;
            visited[row][col] = true;
            for (auto dir : directions){
                area += traverse(grid, row + dir[0], col + dir[1], visited);
            }
        }
        return area;
    }

/*     void traverse(vector<vector<int>>& grid, int& area, int row, int col, vector<vector<bool>>& visited){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()){
            return;
        }

        if(visited[row][col]){
            return;
        }

        if(grid[row][col] == 1){
            area++;
            visited[row][col] = true;
            for (auto dir : directions){
                traverse(grid, area, row + dir[0], col + dir[1], visited);
            }
        }
    } */
};
// @lc code=end

