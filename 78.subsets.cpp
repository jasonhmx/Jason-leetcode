/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> result;
    vector<int> track;
    void backtrack(vector<int> &nums, int start)
    {
        result.push_back(track);

        for (int i = start; i < nums.size(); i++)
        {
            track.push_back(nums[i]);
            backtrack(nums, i + 1);
            track.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        backtrack(nums, 0);
        return result;
    }


};
// @lc code=end
