/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start

/*
Notes:
Used DFS for searching.
Traverse all nodes, if we haven't encountered it and it is new land,
traverse the land and icrement island count

labuladong didn't use visited; he just drowned the islands so that 
dfs is not searching the previously drowned nodes
Obv this wouldn't work if we want to maintain consistency of the 
original grid
*/

#include <vector>
using namespace std;

class Solution {
public:
    // traverse from top to bottom, if encountered a unvisited land, run
    // traverseIsland(). When traverse is finished, return count
    int islandCount = 0;
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int row = 0; row < grid.size(); row++){
            for (int col = 0; col < grid[0].size(); col++){
                if(!visited[row][col] && grid[row][col] == '1'){
                    traverseIsland(grid, row, col, visited);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }

    void traverseIsland(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& visited) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()){
            return;
        }

        if (visited[row][col]) {
            return;
        }

        if (grid[row][col] == '1'){
            visited[row][col] = true;
            for (auto dir : direction){
                traverseIsland(grid, row + dir[0], col + dir[1], visited);
            }
        }
    }
};
// @lc code=end

