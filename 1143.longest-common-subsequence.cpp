/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> memo;

    int longestCommonSubsequence(string text1, string text2) {
        // bottom-up:
        // return dpBU(text1, text2);

        // top-down:
        memo.resize(text1.size() + 1);
        for (auto& i : memo){
            i.resize(text2.size() + 1, -1);
        }
        return dpTD(text1, text2, 0, 0);
    }

    // try and see if I can do a bottom-up traverse
    int dpBU(string text1, string text2){
        int l1 = text1.size();
        int l2 = text2.size();
        vector<vector<int>> lcs(l1 + 1); // lcs[i][j] contains the lcs between text1 from i onwards, and text 2 from j
        for (auto& i : lcs){
            i.resize(l2 + 1, 0); // make enough space for the dp array
        }
        // sizes are initialised to 1 + actual size to allow last element's access

        for (int i = l1-1; i >= 0; i--){
            for (int k = l2-1; k >= 0; k--){
                if (text1[i] == text2[k]){
                    lcs[i][k] = 1 + lcs[i+1][k+1];
                } else {
                    lcs[i][k] = max(lcs[i+1][k], lcs[i][k+1]);
                }
            }
        }
        return lcs[0][0];
    }

    // now try the top-down approach
    int dpTD(string& text1, string& text2, int i, int j){
        if (i == text1.size() || j == text2.size()){
            return 0;
        }
        if (memo[i][j] != -1){
            return memo[i][j];
        }
        int res = 0;
        if (text1[i] == text2[j]){
            res = 1 + dpTD(text1, text2, i+1, j+1);
        } else {
            res = max(dpTD(text1, text2, i, j+1), dpTD(text1, text2, i+1, j));
        }
        memo[i][j] = res;
        return res;
    }
};
// @lc code=end

