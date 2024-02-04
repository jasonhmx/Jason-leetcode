/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
/*
Notes:
Dynamic programming. Simplified version of edit-distance (72). Only top-down shown here.
*/

#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> memo;
    int minDistance(string word1, string word2) {
        memo.resize(word1.size() + 1);
        for (auto& i : memo){
            i.resize(word2.size() + 1, -1);
        }
        return dp(word1, word2, 0, 0);
    }

    int dp(string& word1, string& word2, int i, int j){
        // base case: if one reaches the end, delete the rest from the other
        if (i == word1.size()){
            return word2.size() - j;
        }
        if (j == word2.size()){
            return word1.size() - i;
        }
        if (memo[i][j] != -1){
            return memo[i][j];
        }
        int res = -1;
        if (word1[i] == word2[j]){ // skip to next, don't need to delete
            res = dp(word1, word2, i+1, j+1);
        } else {
            res = min(dp(word1, word2, i+1, j) + 1, dp(word1, word2, i, j+1) + 1);
        }
        memo[i][j] = res;
        return res;
    }
};
// @lc code=end

