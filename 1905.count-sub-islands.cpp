/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<bool>> visited(grid1.size(), vector<bool>(grid1[0].size(), false));
        for (int row = 0; row < grid1.size(); row++){
            for (int col = 0; col < grid1[0].size(); col++){
                if (!visited[row][col] && grid2[row][col] == 1 && grid1[row][col] == 0){
                    traverseIsland(grid2, row, col, visited);
                }
            }
        }
        int res = 0;
        for (int row = 0; row < grid1.size(); row++){
            for (int col = 0; col < grid1[0].size(); col++){
                if (!visited[row][col] && grid2[row][col] == 1){
                    res++;
                    traverseIsland(grid2, row, col, visited);
                }
            }
        }
        return res;
    }

    void traverseIsland(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()){
            return;
        }

        if (visited[row][col]) {
            return;
        }

        if (grid[row][col] == 1){
            visited[row][col] = true;
            for (auto dir : direction){
                traverseIsland(grid, row + dir[0], col + dir[1], visited);
            }
        }
    }
};
// @lc code=end

