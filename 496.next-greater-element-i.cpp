/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
/*
Notes:
Thought 1. use priority queue to organise val, index strcut of nums2
problem: priority queue doesn't have find or access methods
Thought 2. use vector<pair<>> and sort it based on val; find next greatest
    by traversing the next
problem: worst case still O(N) for each find
Thought 3. use ordered map (val->idx) that sorts the keys. same problem as before

best way:
use a monotonic stack, stacking from the end
it's monotonic because the stack always has an increasing order
*/
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> m; // m[key] = val where key is number, val is next greatest number
        vector<int> res(nums1.size());
        for (int i = nums2.size() - 1; i >= 0; i--){
            while(!s.empty() && nums2[i] >= s.top()){
                s.pop();
            }
            m[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++){
            res[i] = m[nums1[i]];
        }
        return res;
    }
};
// @lc code=end

