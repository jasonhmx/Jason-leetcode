/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
/*
Notes:
Dynamic programming. Fewest num coins for amount = fnc for (amount - coin) + 1

Here we used hashmap as the memo data structure. Which might be slower compared to direct
access of a, say, vector. If were to use vector, need to think about how best to initialise.

In this case, can size the vector to be (amount + 1), where 0 is still 0 but 
memo[current_amount] would give you solution to the sub problem
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        return dp(memo, coins, amount);
    }

    int dp(unordered_map<int, int>& memo, vector<int>& coins, int amount){
        if (memo.count(amount)){
            return memo[amount];
        }
        if (amount < 0) {
            return -1;
        }
        int res = INT_MAX;
        for (int coin : coins){
            int prev = dp(memo, coins, amount - coin);
            if (prev != -1){
                res = min(res, prev + 1);
            }
        }
        if (res == INT_MAX) {
            memo[amount] = -1;
        } else {
            memo[amount] = res;
        }
        return memo[amount];
    }

private:
    unordered_map<int, int> memo{{0, 0}}; // maps from amount to fewest number of coins
};
// @lc code=end

