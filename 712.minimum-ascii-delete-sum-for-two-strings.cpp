/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

// @lc code=start

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> asc1;
    vector<int> asc2;
    vector<vector<int>> memo;
    int minimumDeleteSum(string s1, string s2) {
        // initialise two asc arrays
        asc1.resize(s1.size() + 1, 0);
        asc2.resize(s2.size() + 1, 0);
        for (int i = 0; i < s1.size(); i++){
            asc1[i] = static_cast<int>(s1[i]);
        }
        for (int j = 0; j < s2.size(); j++){
            asc2[j] = static_cast<int>(s2[j]);
        }
        // initialise memo
        memo.resize(s1.size() + 1);
        for (auto& i : memo){
            i.resize(s2.size() + 1, -1);
        }
        return dpTD(s1, s2, 0, 0);
    }

    int dpTD(string& s1, string& s2, int i, int j){
        // base case
        if (i == s1.size()){
            return accumulate(asc2.begin() + j, asc2.end(), 0);
        }
        if (j == s2.size()){
            return accumulate(asc1.begin() + i, asc1.end(), 0);
        }
        if (memo[i][j] != -1){
            return memo[i][j];
        }

        int res = -1;
        if (s1[i] == s2[j]){
            res = dpTD(s1, s2, i+1, j+1);
        } else {
            res = min(dpTD(s1, s2, i+1, j) + asc1[i], dpTD(s1, s2, i, j+1) + asc2[j]);
        }
        memo[i][j] = res;
        return res;
    }
};
// @lc code=end

