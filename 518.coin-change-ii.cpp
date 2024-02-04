/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start

/*
Notes:

DP. memo here needs to know two things: the amount left and which coins you can choose. not just one D
*/
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> memo;
    int change(int amount, vector<int>& coins) {
        memo.resize(amount+1);
        for (auto& i : memo){
            i.resize(coins.size(), -1);
        }
        // return dp(amount, coins, 0);
        return dpBall(amount, coins, 0);
    }

    // num ways = sum of num ways of choosing from each coin
    int dp(int amount, vector<int>& coins, int start){
        if (amount == 0){
            return 1;
        }
        if (amount < 0){
            return 0;
        }
        if (memo[amount][start] != -1){
            return memo[amount][start];
        }
        int res = 0;
        for (int i = start; i < coins.size(); i++){
            res += dp(amount-coins[i], coins, i);
        }
        memo[amount][start] = res;
        return res;
    }

    // num ways = num ways choose this coin + num ways not choose this coin
    int dpBall(int amount, vector<int>& coins, int start){
        if (amount == 0){
            return 1;
        }
        if (amount < 0){
            return 0;
        }
        if (start >= coins.size()){
            return 0;
        }
        if (memo[amount][start] != -1){
            return memo[amount][start];
        }
        int res = 0;
        res = dpBall(amount - coins[start], coins, start) + dpBall(amount, coins, start+1);
        memo[amount][start] = res;
        return res;
    }
};
// @lc code=end

