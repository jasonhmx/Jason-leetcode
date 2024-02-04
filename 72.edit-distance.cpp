/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start

/*
Notes:
Dynamic programming. Similar to longest-common-subsequence problem
Need to understand the choice and the cases
Compare each char, deside what to do next
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> memo;
    int minDistance(string word1, string word2) {
/*         memo.resize(word1.size() + 1);
        for (auto& i : memo){
            i.resize(word2.size() + 1, -1);
        }
        return dpTD(word1, word2, 0, 0); */
        return dpBU(word1, word2);
    }

    int dpTD(string& word1, string& word2, int i, int j){
        // start from 0, end when i or j reaches end
        // base case: if one pointer reaches the end, delete/insert the rest of the characters
        if(i == word1.size()){ // insert rest
            return word2.size() - j;
        }
        if (j == word2.size()){ // delete rest
            return word1.size() - i;
        }
        if (memo[i][j] != -1){
            return memo[i][j];
        }

        int res = -1;
        if(word1[i] == word2[j]){ // skip to next
            res = dpTD(word1, word2, i+1, j+1);
        } else {
            int del = 1 + dpTD(word1, word2, i+1, j);
            int ins = 1 + dpTD(word1, word2, i, j+1);
            int sub = 1 + dpTD(word1, word2, i+1, j+1);
            res = min(min(del, ins), sub);
        }
        memo[i][j] = res;
        return res;
    }

    int dpBU(string& word1, string& word2){
        int l1 = word1.size();
        int l2 = word2.size();
        vector<vector<int>> dp(l1 + 1);
        for (auto& i : dp){
            i.resize(l2 + 1, -1);
        }
        // can populate last row and column first
        for (int j = 0; j <= l2; j++){
            dp[l1][j] = l2 - j;
        }
        for (int i = 0; i <= l1; i++){
            dp[i][l2] = l1 - i;
        }
        for (int i = l1 - 1; i >= 0; i--){
            for (int j = l2 - 1; j >= 0; j--){
                if (word1[i] == word2[j]){
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    int del = 1 + dp[i+1][j];
                    int ins = 1 + dp[i][j+1];
                    int sub = 1 + dp[i+1][j+1];
                    dp[i][j] = min(min(del, ins), sub);
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

