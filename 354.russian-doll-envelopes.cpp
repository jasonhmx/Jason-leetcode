/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
/*
Notes:
trick is to sort by width first, then sort the same width elems
by height in reverse order, and use longest-incresing-subsequence
method running for the height.

Dynamic programming method works but exceeds time. Have to use binary
search to not exceed time
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() == 1){
            return 1;
        }
        sort(envelopes.begin(), envelopes.end(), 
        [](vector<int>& a, vector<int>& b){
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });
        // after sorting, use same strat as LIS
        vector<int> heights(envelopes.size());
        for (int i = 0; i < envelopes.size(); i++){
            heights[i] = envelopes[i][1];
        }
        vector<int> dp(envelopes.size(), 1);
        for (int i = 1; i < envelopes.size(); i++){
            for (int k = 0; k < i; k++){
                if (heights[i] > heights[k]){
                    dp[i] = max(dp[i], dp[k] + 1);
                }
            }
        }
        
        int res = 1;
        for (int i : dp){
            res = max(res, i);
        }
        return res;
    }

};
// @lc code=end

