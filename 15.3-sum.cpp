/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start

/*
Notes:
2 pointer 2sum, essentially backtrack and add the third
Or can use the full-on backtracking nsum algo in the other file
*/

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int index = 0;
        while (index < nums.size()){
            int curr = nums[index];
            vector<vector<int>> tuples = twoSumTarget(nums, 0 - curr, index + 1);
            if(!tuples.empty()){
                for(auto tuple : tuples){
                    tuple.push_back(curr);
                    res.push_back(tuple);
                }
            }

            while(index < nums.size() && nums[index] == curr){
                index++;
            }
        }
        return res;
    }

    vector<vector<int>> twoSumTarget(vector<int>& nums, int target, int start){
        vector<vector<int>> res;
        int lo = start;
        int hi = nums.size() - 1;
        while (lo < hi){
            int sum = nums[lo] + nums[hi];
            int left = nums[lo];
            int right = nums[hi];
            if (sum < target){
                while(lo < hi && nums[lo] == left){
                    lo++;
                }
            } else if (sum > target){
                while(lo < hi && nums[hi] == right){
                    hi--;
                }
            } else{
                res.push_back({left, right});
                while (lo < hi && nums[lo] == left) lo++;
                while (lo < hi && nums[hi] == right) hi--;
            }
        }
        return res;
    }
};
// @lc code=end

