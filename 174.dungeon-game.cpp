/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {

public:
    using Dungeon = vector<vector<int>>;
    Dungeon memo;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int height = dungeon.size();
        int width = dungeon[0].size();
        memo.resize(dungeon.size());
        for(auto& i : memo){
            i.resize(dungeon[0].size(), -1);
        }
        memo[height-1][width-1] = dungeon[height-1][width-1] >= 0 ? 1 : 1-dungeon[height-1][width-1];
        return dp(0, 0, dungeon);

    }

    int dp(int i, int j, Dungeon& dungeon){
        // dp(i,j) gives the minimum health required at square i,j to reach the end
        if(i >= dungeon.size() || j >= dungeon[0].size()){
            return 99999;
        }
        if (memo[i][j]!=-1){
            return memo[i][j];
        }
        int res = min(dp(i+1, j, dungeon), dp(i, j+1, dungeon)) - dungeon[i][j];
        if (res < 1){
            res = 1;
        }
        memo[i][j] = res;
        return res;
    }
};
// @lc code=end

