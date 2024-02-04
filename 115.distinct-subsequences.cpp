/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start

/*
Notes:
Dynamic programming. This one is slightly tricky.
memo[start][seek] tells you how many distinct subsequences there are for s[start:] matching t[seek:]
base case is when seek reaches the end, signalling we have a match
if start reaches end, we don't have match
then memoize
*/
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> memo;
    int numDistinct(string s, string t) {
        memo.resize(s.size());
        for(auto& i:memo){
            i.resize(t.size(), -1);
        }
        return dp(s, t, 0, 0);
    }

    int dp(string& s, string& t, int start, int seek){
        if(seek == t.size()){
            return 1;
        }
        if(start == s.size()){
            return 0;
        }
        if (memo[start][seek] != -1){
            return memo[start][seek];
        }
        int res = 0;
        if(s[start] == t[seek]){
            // try next char, or try same char but start from next
            res += dp(s, t, start+1, seek+1);
        }
        // either way, try start from next
        res += dp(s, t, start+1, seek);
        memo[start][seek] = res;
        return res;
    }
};
// @lc code=end

