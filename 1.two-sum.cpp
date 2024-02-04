/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

/*
Note: 
Different ways of doing it. Can use 2-pointer method which has O(NlogN); or 
can't use the same number twice!!
*/

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < nums.size(); i++){
            if (map.count(nums[i])){
                map[nums[i]].push_back(i);
            } else {
                vector<int> toPush = {i};
                map[nums[i]] = toPush;
            }
        }
        for (int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if (map.count(diff)){
                for (auto k : map[diff]){
                    if (i != k){
                        return {i, k};
                    }
                }
            }
        }
        return {-1, -1};
    }
};
// @lc code=end

