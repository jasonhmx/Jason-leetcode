/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start

/*
Notes:
First thoughts: similar to longest increasing subsequence; but the dp array needs to take two fields
one for the length, one for the starting element
When advancing, compare the starting element with the newly added element
This doesn't really work though

The method that actually works:
Similar to the edit distance problem. Have two pointers here that expands outwards. If the chars they point
to are the same, we can add that to palindrome; if not, we try moving one outwards and then the other
*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        memo.resize(s.size());
        for (auto& i : memo){ // make an abundance of access
            i.resize(s.size(), -1);
        }
        int res = 1;
        for (int i = 0; i < s.size(); i++){
            res = max(res, max(dp(s, i, i), dp(s, i, i+1)));
        }
        return res;
    }

private:
    vector<vector<int>> memo;

    int dp(string& s, int l, int r){
        if (l < 0 || r >= s.size()){ // out of bounds base case
            return 0;
        }
        if (memo[l][r] != -1){
            return memo[l][r];
        }

        int res = -1;
        if (s[l] == s[r]){
            if (l == r){
                res = 1 + dp(s, l-1, r+1);
            } else {
                res =  2 + dp(s, l-1, r+1);
            }
        } else {
            res = max(dp(s, l-1, r), dp(s, l, r+1));
        }
        memo[l][r] = res;
        return res;
    }

};
// @lc code=end

