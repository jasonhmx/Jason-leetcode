/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
/*
Notes:
monotonic stack, first thought is to duplicate the array
and check the first half and take mod size

This is pretty much it, except that we don't actually have 
to manually duplicate the vector. Can use clever mod operation
to index into the array
*/
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> res(nums.size());
        int sz = nums.size();
        for (int i = sz * 2 - 1; i >= 0; i--){
            while (!s.empty() && s.top() <= nums[i % sz]){
                s.pop();
            }
            // the earlier elements will be overwritten
            res[i % sz] = s.empty() ? -1 : s.top();
            s.push(nums[i % sz]); 
        }
        return res;
    }
};
// @lc code=end

