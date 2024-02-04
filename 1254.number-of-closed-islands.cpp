/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    // traverse from top to bottom, if encountered a unvisited land, run
    // traverseIsland(). When traverse is finished, return count
    int islandCount = 0;
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        // pre traverse islands on the edge
        for (int col = 0; col < grid[0].size(); col++){
            if(!visited[0][col] && grid[0][col] == 0){
                traverseIsland(grid, 0, col, visited);
            }
            if(!visited[grid.size() - 1][col] && grid[grid.size() - 1][col] == 0){
                traverseIsland(grid, grid.size() - 1, col, visited);
            }
        }

        for (int row = 0; row < grid.size(); row++){
            if(!visited[row][0] && grid[row][0] == 0){
                traverseIsland(grid, row, 0, visited);
            }
            if(!visited[row][grid[0].size() - 1] && grid[row][grid[0].size() - 1] == 0){
                traverseIsland(grid, row, grid[0].size() - 1, visited);
            }
        }
        
        for (int row = 0; row < grid.size(); row++){
            for (int col = 0; col < grid[0].size(); col++){
                if(!visited[row][col] && grid[row][col] == 0){
                    traverseIsland(grid, row, col, visited);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }

    void traverseIsland(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()){
            return;
        }

        if (visited[row][col]) {
            return;
        }

        if (grid[row][col] == 0){
            visited[row][col] = true;
            for (auto dir : direction){
                traverseIsland(grid, row + dir[0], col + dir[1], visited);
            }
        }
    }
};
// @lc code=end

