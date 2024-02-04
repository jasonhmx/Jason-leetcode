/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> track;

    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return result;
    }

    void backtrack(int n, int k, int start) {
        if (track.size() == k){
            result.push_back(track);
        }

        for (int i = start; i <= n; i++)
        {
            track.push_back(i);
            backtrack(n, k, i+1);
            track.pop_back();
        }
    }
};
// @lc code=end

